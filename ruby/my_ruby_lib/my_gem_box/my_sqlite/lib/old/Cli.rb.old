# require my_sqlite_class

class MySqlite::Cli
    def initialize(filelist)
      @filelist = filelist
      # @my_sqlite = MySqliteClass.new
    end

    def tokenize(input, delimiter = ' ')
      tokens = input.split(delimiter)
      tokens
    end

    def prompt
      print "my_sqlite> "
      input = $stdin.gets
      puts "input from gets: #{input.inspect}"
      return nil if input.nil?
      tokens = tokenize(input)
      tokens[0]
    end

    def process_input(input, list)
      case true
      when input == "SELECT"
        p "Consuming token SELECT"
        # Handle SELECT queries
      when input == "INSERT"
        p "Consuming token INSERT"
        # Handle INSERT queries
      when input == "UPDATE"
        p "Consuming token UPDATE"
        # Handle UPDATE queries
      when input == "DELETE"
        p "Consuming token DELETE"
        # Handle DELETE queries
      when input == "QUIT"
        puts "Exiting my_sqlite"
        exit
      else
        puts "Bad Arg"
      end
    end

    def start
      puts "MySQLite CLI version 0.1"
      list = LinkedList.new
      @filelist.each do |elem|
        list.append(elem)
      end
      puts list.print_LL
      @filelist = nil
      loop do
        input = prompt
        puts "input after prompt: #{input.inspect}"
        break if input.nil? # check of  ctrl+d
        process_input(input, list)
      end
    end
  end