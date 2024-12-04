## Przydatne skróty:

# Usuwanie wielu tabulatorów naraz: 
Shift + Tab

# Dodawanie/usuwanie wielu komentarzy naraz:
Ctrl + /


    local compressor decompress_flag temp_file
    compressor="$1"
    decompress_flag="$2"
    temp_file="$3"
    local compress_times=()
    local decompress_times=()
    local compressed_file="${temp_file}.${compressor}"
compression_test() {
    #gzip bzip2 xz zstd lz4 7z
    
    for i in {1..5}; do
        compress_times+=($(measure_time ))
        
        decompress_times+=($(measure_time ))
    done
}