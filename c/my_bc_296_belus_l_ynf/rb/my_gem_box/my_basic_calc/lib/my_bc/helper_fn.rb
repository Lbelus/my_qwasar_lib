module Helper_fn
    PRECEDENCE = {
        "+" => 1,
        "-" => 1,
        "*" => 2,
        "/" => 2,
        "^" => 3,
        "%" => 3
    }

    ASSOCIATIVITY = {
        "^" => :right,
        "+" => :left,
        "-" => :left,
        "*" => :left,
        "/" => :left
    }

    def is_a_number(str)
        !!(Float(str) rescue false)
    end

    def associativity_check(token, stack)
        if (PRECEDENCE[token] == PRECEDENCE[stack.last] and
            ASSOCIATIVITY[token] == :left)
            return true
        end
        return false
    end

    def precedence_check(token, stack)
        if !stack.empty? and evaluate_operators(stack.last) 
            if ((PRECEDENCE[token] < PRECEDENCE[stack.last]) or 
                associativity_check(token, stack))
                return true
            end
        end
            return false
    end

    def clear_stack(stack)
        loop do
            if stack.last == "("
                stack.pop
                break
            end
            yield stack.pop
        end
    end

end