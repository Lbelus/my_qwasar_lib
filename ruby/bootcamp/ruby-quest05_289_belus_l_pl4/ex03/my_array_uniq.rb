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

class My_array_uniq
    include Fn_support

    def initialize(tokens)
        @tokens = tokens
    end

    def rm_dup
        result = []
        prev = nil
        Fn_support.my_each(@tokens) do |x|
            if prev != x
                result << yield(x)
            end
            prev = x;
        end
        result
    end
end

def my_array_uniq(param_1)
    param_1.sort!
    new_uniq = My_array_uniq.new(param_1)
    new_uniq.rm_dup {|x| x}
end


# def my_array_uniq(param_1)
#     param_1.uniq!
# end