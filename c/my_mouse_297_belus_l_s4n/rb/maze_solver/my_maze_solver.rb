
class Queue
    def initialize
        @my_queue = []
    end
    
    def enqueue(item)
        @my_queue.push(item)
    end

    def dequeue
        @my_queue.shift
    end

    def empty?
        @my_queue.empty?
    end

    def size
        @my_queue.size
    end
    
    def peek
        p @my_queue
    end
end


class Grid_attr
    attr_accessor :nb_row, :nb_col, :size_grid, :row_start, :col_start, :s_value, :e_value, :obstacle

    def initialize(nb_row, nb_col, size_grid, row_start, col_start, s_value, e_value, obstacle)
        @nb_row     = nb_row 
        @nb_col     = nb_col
        @size_grid  = size_grid
        @row_start  = row_start
        @col_start  = col_start
        @s_value    = s_value
        @e_value    = e_value
        @obstacle   = obstacle
    end
end

def get_size_grid(str)
    result = ""
    str.split('').each do  |char|
        if char == '*'
            break
        end
        result << char
    end
    result.split('x')
end

    # start       = arr[0][-3]
    # finish      = arr[0][-2]
    # empty       = arr[0][-4]
    # obstacle    = arr[0][-5]

    # nb_row    = 0
    # nb_col    = 0
    # size_grid = 0
    # row_start = 0
    # col_start = 0

def get_grid_attribute(nb_row_col, arr)
    grid = Grid_attr.new(
        nb_row_col[0].to_i,
        nb_row_col[1].to_i, 
        (nb_row_col[0].to_i * nb_row_col[1].to_i),
        0,
        arr[1].index(arr[0][-3]),
        arr[0][-3],
        arr[0][-2],
        arr[0][-6]
    )
end

def explore(row, col, grid, visited, maze, row_q, col_q, next_node, prev)
    compass_row = [-1, +1, 0, 0]
    compass_col = [0, 0, +1, -1]
    index = 0
    
    while index < 4  
        new_row = row + compass_row[index]
        new_col = col + compass_col[index]
        
        index += 1
        
        if new_row < 0 or new_col < 0
            next
        end
        if new_row >= grid.nb_row or new_row >= grid.nb_col 
            next
        end
        if visited[new_row][new_col] == 1
            next
        end
        if maze[new_row][new_col] == grid.obstacle
            next
        end
        row_q.enqueue(new_row)
        col_q.enqueue(new_col)
        visited[new_row][new_col] = 1
        next_node += 1
    end
    next_node
end


        # if curr_row > prev_row or (curr_row == prev_row and (prev_col == curr_col -1 or prev_col == curr_col +1 )  )
        # if curr_row > prev_row             
        #     prev[curr_row][curr_col] = "x"
        #     prev_row = curr_row;
        #     prev_col = curr_col;
        # elsif curr_row == prev_row and (prev_col == curr_col -1 or prev_col == curr_col +1 )
        #     prev[curr_row][curr_col] = "x"
        #     prev_row = curr_row;
        #     prev_col = curr_col;
        
        # end

def is_on_path(curr_row, curr_col, prev_row, prev_col)
    if curr_row == prev_row -1 and prev_col == curr_col
        return true
    elsif curr_row == prev_row and prev_col == curr_col -1
        return true
    elsif curr_row > prev_row and prev_col == curr_col
        return true
    elsif curr_row == prev_row and prev_col == curr_col +1
        return true
    end
    return false
end

def get_file(filename)


    row_q = Queue.new
    col_q = Queue.new

    maze = IO.readlines(filename)

    count = 0
    nodes_left = 1
    next_node = 0
    destination = false

    nb_row_col = get_size_grid(maze[0])
    p grid  = get_grid_attribute(nb_row_col, maze)
    visited = Array.new(grid.nb_row) { Array.new(grid.nb_col) { 0 } }
    prev    = Array.new(grid.nb_row) { Array.new(grid.nb_col) { "." } }
    prev_row = grid.row_start
    prev_col = grid.col_start
    row_q.enqueue(grid.row_start)
    col_q.enqueue(grid.col_start)
    visited[grid.row_start][grid.col_start] = 1
    maze.delete_at(0)

    while row_q.size > 0
        curr_row = row_q.dequeue()
        curr_col = col_q.dequeue()
        
        if maze[curr_row][curr_col] == grid.e_value
            destination  = true
            break
        end
        next_node = explore(curr_row, curr_col, grid, visited, maze, row_q, col_q, next_node, prev)
        nodes_left -= 1
        # if curr_row > prev_row or (curr_row == prev_row and (prev_col == curr_col -1 or prev_col == curr_col +1 )  )
        prev[curr_row][curr_col] = "x"
        
        if is_on_path(curr_row, curr_col, prev_row, prev_col) == true
        
                    prev[curr_row][curr_col] = "x"
                    prev_row = curr_row;
                    prev_col = curr_col;
        end

        if nodes_left == 0

            nodes_left = next_node
            next_node = 0
            count += 1
        end
    end
    if destination
        visited.each_with_index do |x, index|
            p "#{index}:#{x}"
        end
        puts "prev"
        prev.each.with_index do |x, index|
            puts "#{index}:#{x}"
        end
        return count
    end
    return -1
end

p get_file(ARGV[0])

# 
