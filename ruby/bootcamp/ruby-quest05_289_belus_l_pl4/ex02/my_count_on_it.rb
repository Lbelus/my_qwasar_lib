##
##
## QWASAR.IO -- my_count_on_it
##
##
## @param {String[]} param_1
##
## @return {integer[]}
##

module Fn_support
    
    def self.my_size(str)
        chars = str.split('')
        index = 0
        chars.each do |c|
            index += 1
        end
        index
    end

    def self.my_each(param_1)
        index = 0
        len = param_1.length()
        while index < len
            yield param_1[index]
            index += 1
        end
    end

end

class My_count_on_it
    include Fn_support
    
    def initialize(tokens)
        @tokens = tokens
    end

    def custom_map
        result = []
        Fn_support.my_each(@tokens) do |x|
            result << yield(x)
        end
        result
    end
end

def my_count_on_it(param_1)
    new_count_arr = My_count_on_it.new(param_1)
    new_count_arr.custom_map  { |x|  Fn_support.my_size(x) }
end

# p my_count_on_it(["This", "is", "the", "way"])