
# solution 1
class My_own_each
    def initialize(tokens)
        @tokens = tokens
    end

    def custom_each
        index = 0
        len = @tokens.length()
        while index < len
            yield @tokens[index]
            index += 1
        end
    end
end

def my_each(param_1)
    new_each = My_own_each.new(param_1)
    new_each.custom_each do |x|
        puts x
    end
end


# solution 2

# def my_each(param_1)
#         index = 0
#         len = param_1.length()
#         while index < len
#             yield param_1[index]
#             index += 1
#         end
# end


# my_each(["blah1", "blah2", "blah3"] ) do |str|
#     puts str
# end