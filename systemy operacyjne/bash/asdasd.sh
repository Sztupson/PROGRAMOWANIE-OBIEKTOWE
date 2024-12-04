#!/bin/bash

measure_time() {
    local start end duration
    start=$(date +%s.%N)
    "$@" &>/dev/null
    end=$(date +%s.%N)
    duration=$(echo "$end - $start" | bc -l)
    echo "$duration"
}

calculate_average() {
    local sum=0
    local count=0
    for value in "$@"; do
        sum=$(echo "$sum + $value" | bc -l)
        ((count++))
    done
    echo "scale=6; $sum / $count" | bc -l
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
    avg_compress=$(calculate_average "${compress_times[@]}")
    avg_decompress=$(calculate_average "${decompress_times[@]}")

    local original_size compressed_size ratio
    original_size=$(stat -c %s "$temp_file")
    compressed_size=$(stat -c %s "$compressed_file")
    ratio=$(echo "scale=2; 100 * $compressed_size / $original_size" | bc -l)

    echo -e "$compressor\t$avg_compress\t$avg_decompress\t$ratio%"
    
    rm -f "$compressed_file"
}

create_test_data() {
    mkdir -p ~/tmp/data/random ~/tmp/data/empty ~/tmp/data/various
    for i in {1..5}; do
        dd if=~/dev/urandom of=~/tmp/data/random/random_$i bs=10M count=1 &>/dev/null
        dd if=~/dev/zero of=~/tmp/data/empty/empty_$i bs=10M count=1 &>/dev/null
    done
}

main() {
    create_test_data

        echo "$dir"
        echo -e "name\tcompress\tdecompress\tratio"

        temp_dir=$(mktemp -d)
        tar_file="$temp_dir/$(basename "$dir").tar"
        tar -cf "$tar_file" -C "$dir" . &>/dev/null

        test_compression gzip --decompress "$tar_file"
        test_compression bzip2 --decompress "$tar_file"
        test_compression xz --decompress "$tar_file"
        test_compression zstd --decompress "$tar_file"
        test_compression lz4 -d "$tar_file"
        test_compression 7z e "$tar_file" &>/dev/null

        rm -rf "$temp_dir"
    done
}

main "$@"
