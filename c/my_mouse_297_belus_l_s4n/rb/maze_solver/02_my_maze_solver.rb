class My_queue
    def initialize
        @my_queue = []
    end

    def enqueue(element)
        @my_queue.push(element)
    end
    alias_method :<<, :enqueue

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

class My_set
    
    def initialize
        @hash = {}
    end

    def add(element)
        @hash[element] = true
    end

    def remove(element)
        @hash.delete(element)
    end

    def include?(element)
        @hash.key?(element)
    end

    def size
        @hash.size
    end

    def empty?
        @hash.empty?
    end

    def to_a
        @hash.keys
    end

    def to_s
        to_a.to_s
    end
end


$queue = My_queue.new
$visited = My_set.new


class Grid_attr
    attr_accessor :size

    def initialize(size)
        @size       = size
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


def get_grid_attribute(grid)
    grid_atrr = Grid_attr.new(grid.length.to_i)
end

def is_valid(x, y, grid)
    len = grid.length
    obstacle = grid[0][len - 6]
    if x >= 0 && 
            x < len && 
            y >= 0 && 
            y < len && 
            grid[x][y] != obstacle
            true            
    else
            false
    end
end

def explore_grid(direction_vector, x, y, path, grid)
    direction_vector.each do |dx, dy|
        new_x, new_y = x + dx, y + dy
        if is_valid(new_x, new_y, grid) && !$visited.include?([new_x, new_y])
            new_path = path + [[new_x, new_y]]
            $queue << [new_x, new_y, new_path]
            $visited.add([new_x, new_y])
        end
    end
end


def golden_path(grid, path)
    len = grid.length
    breadcrumb = grid[0][len - 3]
    path.each do |x, y|
        grid[x][y] = breadcrumb 
    end
    grid
end

def print_it(grid)
    grid.each do |x|
        p x
    end
end

def bfs(grid, entrance, _exit_)

    direction_vector = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    entrance_x, entrance_y = entrance
    exit_x, exit_y = _exit_
    $queue << [entrance_x, entrance_y, [[entrance_x, entrance_y]]]

    $visited.add([entrance_x, entrance_y])

    while !$queue.empty?
      x, y, path = $queue.dequeue
      if [x, y] == [exit_x, exit_y]
        return path
      end
      explore_grid(direction_vector, x, y, path, grid)
    end
    -1
end

def get_e_coord(grid, row, value)

    col = grid[row].index(value)
    coord = row, col
end
require 'set'

def my_main(filename)

    grid        = IO.readlines(filename)
    grid_attr   = get_grid_attribute(grid)
    entrance    = get_e_coord(grid, 1, grid[0][-3])
    _exit_      = get_e_coord(grid, grid_attr.size - 1, grid[0][-2])
    path        = bfs(grid, entrance, _exit_)

    golden_path(grid, path)
    print_it(grid)
    
end

p my_main(ARGV[0])