class My_bc
    def self.my_bc(infix_notation = "0")
        op = Shunting_yard.new(infix_notation)
        op.shunting_yard_algo
    end
end

def my_bc_fn(infix_notation)
    My_bc.my_bc(infix_notation)
end

require 'my_bc/shunting_yard'