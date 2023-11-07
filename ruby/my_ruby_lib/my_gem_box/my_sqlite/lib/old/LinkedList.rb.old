class Node
    attr_accessor :value, :next_node
  
    def initialize(value, next_n = nil)
      @value = value
      @next_n = next_n
    end
end

class LinkedList
    def initialize
        @head = nil
    end

    def append(value)
        if @head.nil?
            @head = Node.new(value)
        else
            curr = @head
            curr = curr.next_node while curr.next_node
            curr.next_node = Node.new(value)
        end
    end

    def print_LL
        result = []
        curr = @head
  
        while curr
            result << curr.value
            curr = curr.next_node
      end

        result.join(' -> ')
    end
end