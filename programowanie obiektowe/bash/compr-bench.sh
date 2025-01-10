create_data() {
mkdir -p ~/tmp/data/random ~/tmp/data/empty ~/tmp/data/various
for i in $(seq 1 5); do
    dd if=/dev/urandom of=~/tmp/data/random/random_$i bs=10M count=1 
    dd if=/dev/zero of=~/tmp/data/empty/empty_$i bs=10M count=1 
done
}

measure_time() {
    local start end duration
    start=$(date +%s.%N)
    "$@" &>/dev/null
    end=$(date +%s.%N)
    duration=$(echo "$end - $start" | bc -l)
    echo "$duration"
}

test_compression() {
    local compressor decompress_flag temp_file
    compressor="$1"
    decompress_flag="$2"
    temp_file="$3"

    local compress_times=()
    local decompress_times=()
    local compressed_file="${temp_file}.${compressor}"

    for i in {1..5}; do
        compress_times+=($(measure_time "$compressor" -k "$temp_file"))
        decompress_times+=($(measure_time "$compressor" "$decompress_flag" "$compressed_file"))
    done

    local avg_compress avg_decompress
    avg_compress=$(echo "scale=6; (${compress_times[*]})/5" | bc -l)
    avg_decompress=$(echo "scale=6; (${decompress_times[*]})/5" | bc -l)

    local original_size compressed_size ratio
    original_size=$(stat -c %s "$temp_file")
    compressed_size=$(stat -c %s "$compressed_file")
    ratio=$(echo "scale=2; 100 * $compressed_size / $original_size" | bc -l)

    echo -e "$compressor\t$avg_compress\t$avg_decompress\t$ratio%"
    
    rm -f "$compressed_file"
}


main() {
    create_data

    for dir in "$@"; do
        echo "$dir"
        echo -e "name\tcompress\tdecompress\tratio"

        temp_dir=$(mktemp -d)
        tar_file="$temp_dir/$(basename "$dir").tar"
        tar -cf "$tar_file" -C "$dir" . 

        test_compression gzip --decompress "$tar_file"
        test_compression bzip2 --decompress "$tar_file"
        test_compression xz --decompress "$tar_file"
        test_compression zstd --decompress "$tar_file"
        test_compression lz4 -d "$tar_file"
        test_compression 7z e "$tar_file" 

        rm -rf "$temp_dir"
    done
}