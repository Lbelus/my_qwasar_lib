
def my_hamming_dna(str1, str2)
    len = str1.length
    if (len != str2.length)
        return -1
    end
    count = 0
    index = 0
    while index < len
        if str1[index] != str2[index]
            count += 1;
        end
    index += 1
    end
    count
end

# p my_hamming_dna(ARGV[0], ARGV[1])