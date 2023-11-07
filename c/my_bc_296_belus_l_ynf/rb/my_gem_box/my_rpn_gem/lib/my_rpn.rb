class Calc
  def self.my_rpn(tokens = "0")
      op = Operation.new(tokens)
      result = nil
      op.custom_each_with_index_reset do |val, index|
        result = op.my_calculate(val, index)
      end
      result
  end
end

def my_rpn_fn(tokens)
  Calc.my_rpn(tokens)
end

require 'my_rpn/operation'