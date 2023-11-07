require "my_rpn"
require "my_rpn/operators"
require "my_bc/helper_fn"

class My_bc::Shunting_yard
    include Helper_fn

    def initialize(infix_notation)
        @infix_notation = infix_notation
    end

    def shunting_yard_algo
        extend Operator
        stack   = []
        result  = []
        @infix_notation.each do |token|
            if is_a_number(token) #STEP 1
                result << token
            elsif token == '(' #STEP 2
                stack.push(token)
            elsif token == ')' #STEP 3
                clear_stack(stack) do |x|
                    result << x
                end
            elsif evaluate_operators(token) # STEP 4 5 6
                while precedence_check(token, stack)
                    result << stack.pop
                end
                stack.push(token)
            end
        end
        stack.reverse_each do # STEP 7
            result << stack.pop
        end
        result
    end
end