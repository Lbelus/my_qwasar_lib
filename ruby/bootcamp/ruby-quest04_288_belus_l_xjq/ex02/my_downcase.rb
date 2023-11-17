


def my_downcase(str)
    chars = str.split('')
    result = ""
    chars.each do |c|
        if c >= "A" && c <= "Z"
            c = (c.ord + 32).chr
        end
        result += c
    end
    return result
end


# p my_downcase("LORRIS")

# def my_downcase(param_1)
#     result = param_1.downcase!
#     if result != nil
#         result
#     else
#         param_1
#     end
# end