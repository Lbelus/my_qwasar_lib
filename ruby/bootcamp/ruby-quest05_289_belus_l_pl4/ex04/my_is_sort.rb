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

    def self.my_map(param_1)
        result = []
        my_each(param_1) do |x|
            result << yield(x)
        end
        result
    end

    def self.my_each_with_index(param_1)
        index = 0
        len = param_1.length()
        while index < len
            yield param_1[index], index
            index += 1
        end
    end

    def self.counting_sort_asc(param_1)
        min_value = param_1.min
        shift_arr = Fn_support.my_map(param_1) { |x| x - min_value }
        max_value = shift_arr.max
        counts = Array.new(max_value + 1, 0)
      
        Fn_support.my_each(shift_arr) do |x|
          counts[x] += 1
        end
      
        result = []
        Fn_support.my_each_with_index(counts) do |count, i|
          count.times { result << i + min_value }
        end
        
        result
      end

      def self.counting_sort_desc(param_1)
        min_value = param_1.min
        shift_arr = Fn_support.my_map(param_1) { |x| x - min_value }
        max_value = shift_arr.max
        counts = Array.new(max_value + 1, 0)
      
        Fn_support.my_each(shift_arr) do |x|
          counts[x] += 1
        end

        result = []
        counts.reverse_each.with_index do |count, i|
          count.times { result << max_value - i + min_value }
        end
        
        result
      end


end



def my_is_sort(param_1)
    if param_1 == []
        return true
    end
    asc = Fn_support.counting_sort_asc(param_1)
    desc = Fn_support.counting_sort_desc(param_1)
    if param_1 == asc or param_1 == desc
        true
    else
        false
    end
end


# def my_is_sort(param_1)
#     if param_1 == param_1.sort or param_1 == param_1.sort.reverse
#         true
#     else
#         false
#     end
# end

# p my_is_sort([4, 7, 0, 3])
# p my_is_sort([2, 1, -1])
# p my_is_sort([])