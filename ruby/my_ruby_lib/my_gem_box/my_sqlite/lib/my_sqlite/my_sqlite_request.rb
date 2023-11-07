require 'csv'

class MySqliteGetter

    attr_reader  :options, :db, :data, :col_ids, :row_ids, :result

    def initialize(options = nil, db = nil, data = nil, col_ids = [], row_ids = [], result = nil)
        @options = options
        @db = db
        @data = data
        @col_ids = col_ids
        @row_ids = row_ids
        @result = result
    end

    def from_select
        @result = @db.get_db_at(@col_ids, get_where())
    end

    def get_where
        if @row_ids == []
            @row_ids = @db.get_row_range
        end
        @row_ids
    end

    def get_select
        @col_ids
    end

    def get_result
        @result.each do |row|
            result = row.join(',')
            p result
        end
    end
end

module MySqliteSetter

	def set_from(db)
    	@db = db
	end

	def set_select(column_list = [])
        if column_list.index('*') != nil
            column_list = @db.get_header_list()
        end
        column_list.each do |column|
    	    @col_ids << @db.get_column_id(column)
        end
	end

    def set_where(column_name, criteria)  
        col_id = @db.get_column_id(column_name)
        @row_ids = @db.get_row_id(criteria, col_id)
    end

    def set_join(column_on_db_a, filename_db_b, column_on_db_b)
        id_a = @db.get_column_id(column_on_db_a)
        db_a = @db.from_to(0 , id_a )
        id_a += 1

        db_b = set_table(filename_db_b)
        id_b = db_b.get_column_id(column_on_db_b)
        db_b = db_b.from_to(id_a , id_b)

        merge = db_a.zip(db_b).map(&:flatten)
        merge = convert_to_csv(merge)
        @db = set_table(merge, false)
    end

    def set_order(order, column_name)
        col_id = @db.get_column_id(column_name)
        db = @db.get_db
        headers = db[0]
        db.shift
        case order
        when :asc
            db.sort_by! { |row| row[col_id] }
        when :desc
            db.sort_by! { |row| row[col_id] }.reverse!
        end
        db.unshift(headers)
        db_csv = convert_to_csv(db)
        @db = set_table(db_csv, false)
    end

    def set_standard_data()
        if @db.has_generic_key?(@data) 
            @data = @db.standardize_hash(@data)
        end
    end

    def self_execute_(hash)
        hash.each do |method, argument|
            if self.respond_to?(method)
                if method == "where" or method == "order" or method == "join" and argument != nil
                    self.send(method, *argument[0])
                elsif method == "delete" and argument == true
                    self.send(method)
                elsif method == "quit" and argument == true
                    break
                elsif argument != nil
                    self.send(method, argument)
                end
            else
            p "#{method} does not belong to my_sqlite"
            end
        end
    end

    private

    def to_array(*args)
        args
    end

    def object_to_hash(obj)
    	hash = {}
    	obj.instance_variables.each do |var|
    		hash[var[1..-1]] = obj.instance_variable_get(var)
      	end
      	hash
    end 
    
    def set_table(table_name, is_file = true)
        db = nil 
        if is_file
            db = from_file(table_name)
        else
            db = from_variable(table_name)
        end
        db
    end

    def from_file(table_name)
        db = InvertedIndex.new
        headers = CSV.open(table_name, headers: true).first.headers
        db.insert("0", headers.join(','))
        CSV.foreach(table_name, headers: true) do |row|
            id = row['index']
            text = row.to_s.chomp
            db.insert(id, text)
        end
        db
    end

    def from_variable(table_name)
        db = InvertedIndex.new
        headers = nil
        CSV.parse(table_name) do |row|
          headers = row
          break
        end
        db.insert("0", headers.join(','))
        CSV.parse(table_name, headers: true) do |row|
            id = row['index']
            text = row.to_s.chomp
            db.insert(id, text)
        end
        db
    end

    def convert_to_csv(matrix)
        csv_table = CSV.generate do |csv|
                matrix.each do |row|
                row[-1].chomp!
                csv << row
            end
        end
        csv_table
    end

end

class MySqliteRequest < MySqliteGetter
	include MySqliteSetter

	attr_accessor :state

	def initialize(query = nil)
		super
		if query 
			@options = object_to_hash(query)
			@state = 1
		else
			@options = Query.new
			@state = 0
		end
	end

	def from(table_name = nil)
		if @state == 0
			args = to_array(table_name)
			@options.from = args
			@options.from = table_name
		elsif @state == 1
			db = set_table(table_name)
			set_from(db)
		end
		self
	end

	def select(column_list = [])
		if @state == 0
			args = to_array(column_list)
			@options.select = args
		elsif @state == 1
			set_select(column_list)
		end
		if @state == 2
			from_select()
		end
		self
	end

	def where(column_name, criteria)
		if @state == 0
			args = to_array(column_name, criteria)
			@options.where = []
			@options.where << args
		elsif @state == 1
			set_where(column_name, criteria) 
		end
		self
	end

    def join(column_on_db_a, filename_db_b, column_on_db_b)
        if @state == 0
            args = to_array(column_on_db_a, filename_db_b, column_on_db_b)
            @options.join = []
            @options.join << args
        elsif @state == 1
            set_join(column_on_db_a, filename_db_b, column_on_db_b)
        elsif @state == 2
            @result = @db.get_db
        end
        self
    end

    def order(order, column_name)
        if @state == 0
            args = to_array(order, column_name)
            @options.order = []
            @options.order << args
        elsif @state == 1
            set_order(order, column_name)
        elsif @state == 2
            @result = @db.get_db            
        end
        self
    end

    def insert(table_name) 
        if @state == 0
            @options.insert = table_name
        elsif @state == 1
            @db = set_table(table_name)
        elsif @state == 2
            set_standard_data()
            @db.insert_hash(@data)
            @result = @db.get_db
        end
        self
    end

    def values(data)
        if @state == 0
            @options.values = data
        else
            @data = data
        end
        self
    end

    def update(table_name)
        if @state == 0
            @options.update = table_name
        elsif @state == 1
            @db = set_table(table_name)
        elsif @state == 2
            if @options['set'] == nil
                set_standard_data()
                @db.update_value(@data)
                @result = @db.get_db
            else
                @db.modify_column(@data, get_where())
                @result = @db.get_db
            end
        end
    self
    end

    def set(data)
        if @state == 0
            @options.set = data
        else
            @data = data
        end
        self
    end

    def delete
        if @state == 0
            @options.delete = true
        elsif state == 2
            row_ids = get_where().dup
            row_ids.each do |row_id|
                @db.delete_entry(row_id)
            end
            @result = @db.get_db
        end
        self
    end

    def quit
        false
    end


    def run
        if @state == 0
        # state start from 1 if CLI esle start from 0 to colect methods argument
            @options = object_to_hash(@options)
            @state = 1
        end
        while @state < 3
            self_execute_(@options)
            @state += 1
        end
        get_result()
        initialize        
    self
    end

end

require_relative 'Inverted_Index'
require_relative 'cli'