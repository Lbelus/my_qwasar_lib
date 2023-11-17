
# str.length

# str.size

def my_size(str)
    chars = str.split('')
    index = 0
    chars.each do |c|
        index += 1
    end
    index
end

# def my_size(param_1)
#     param_1.length
# end

# def my_size(param_1)
#     str.size
# end