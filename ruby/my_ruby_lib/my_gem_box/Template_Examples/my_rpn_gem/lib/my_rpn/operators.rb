module Operator 
    def my_add(left, right)
        left + right
    end
    
    def my_substract(left, right)
      left - right
    end
  
    def my_mult(left, right)
      left * right
    end
  
    def my_divide(left, right)
      left / right
    end
    
    def my_exponantiation(left, right)
      left ** right
    end

    def my_modulo(left, right)
      left % right
    end

    def raise_format_error(nb_arg)
      raise "RPN not respected" if nb_arg < 2
    end
    
    def evaluate_operators(val)
      operator_token = ['+', '-', '*', '/', '^', '%']
      operator_token.each do |token|
        if val == token
          return true
        end
      end
      return false
    end
end