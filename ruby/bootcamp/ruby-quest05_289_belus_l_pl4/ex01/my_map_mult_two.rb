class My_own_map
    def initialize(tokens)
        @tokens = tokens
    end

    def my_each(param_1)
        index = 0
        len = param_1.length()
        while index < len
            yield param_1[index]
            index += 1
        end
    end

    def custom_map
        result = []
        my_each(@tokens) do |x|
            result << yield(x)
        end
        result
    end
end

def my_map_mult_two(param_1)
    new_map = My_own_map.new(param_1)
    new_map.custom_map  { |x| x * 2 }
end



# def my_map_mult_two(param_1)
#     param_1.map { |x| x*2}
# end

# p my_map_mult_two([1, 2, 3, 4, 5])