


def my_upcase(str)
    chars = str.split('')
    result = ""
    chars.each do |c|
        if c >= "a" && c <= "z"
            c = (c.ord - 32).chr
        end
        result += c
    end
    return result
end

# p my_upcase("lorris")

# def my_upcase(param_1)
#     result = param_1.upcase!
#     if result != nil
#         result
#     else
#         param_1
#     end
# end