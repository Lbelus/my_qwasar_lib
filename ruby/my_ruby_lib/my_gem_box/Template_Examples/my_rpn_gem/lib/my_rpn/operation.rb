require "my_rpn/operators"

class Calc::Operation
  include Operator
  def initialize(tokens)
    @tokens = tokens
  end

  def custom_each_with_index_reset
    index     = 0
    len       = @tokens.length()
    prev_prev = nil
    prev      = nil
    while index < len
      if evaluate_operators(@tokens[index])
        raise_format_error(index)
        yield @tokens[index], index
        index = 0
      else
        prev_prev = prev
        prev      = @tokens[index]
        index += 1
      end
      if index == 0
        len -= 2
        @tokens.delete(prev_prev)
        @tokens.delete(prev)
      end
    end
  end

  def my_calculate(token, index)
    right  = @tokens[index - 1].to_f
    left   = @tokens[index - 2].to_f
    case token
      when '+'
        @tokens[index] = "#{my_add(left, right)}"
      when '-'
        @tokens[index] = "#{my_substract(left, right)}"
      when '*'
        @tokens[index] = "#{my_mult(left, right)}"
      when '/'
        @tokens[index] = "#{my_divide(left, right)}"
      when '^'
        @tokens[index] = "#{my_exponantiation(left, right)}"
      when '%'
        @tokens[index] = "#{my_modulo(left, right)}"
    end
  end
end