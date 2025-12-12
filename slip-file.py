def split_file(input_path, lines_per_file=5000):
    with open(input_path, 'r', encoding='utf-8') as infile:
        lines = infile.readlines()

    file_count = 1
    for i in range(0, len(lines), lines_per_file):
        chunk = lines[i:i + lines_per_file]
        output_path = f"part_{file_count:03}.srt"
        
        with open(output_path, 'w', encoding='utf-8') as outfile:
            outfile.writelines(chunk)
        
        print(f"Created {output_path} with {len(chunk)} lines")
        file_count += 1



split_file("Harvard CS50 – Full Computer Science University Course [8mAITcNt710].en.srt", lines_per_file=5000)

