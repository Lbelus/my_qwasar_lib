# https://www.shortcutfoo.com/app/dojos/ruby-strings/cheatsheet


def my_string_index(str, char)
    chars = str.split('')
    chars.each_with_index do |c, index|
        if c == char
           return index
        end
    end
    index = -1
end

# def my_string_index(param_1, param_2)
#     result = param_1.index(param_2)
#     if result != nil
#         result
#     else
#         result = -1
#     end
# end

# p my_string_index("allo", 'l')