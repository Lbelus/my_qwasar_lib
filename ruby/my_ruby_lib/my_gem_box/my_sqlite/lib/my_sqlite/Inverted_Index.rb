class InvertedIndex
    ################ initialize #################
    # Initializes new InvertedIndex with empty data and index hashes
    # @return {nil}
    def initialize
        @data = {}  # Dictionary to store the data entries
        @index = {} # Inverted index to facilitate search
    end

    ################ insert #################
    # Inserts a new text entry associated with an id into the data hash, and updates the index
    # @return {nil}
    def insert(id, txt)
        @data[id] = txt
        update_index(id, txt)
    end

    ################ insert_hash #################
    # Inserts a hash of data with the option of including an id or generating a new one
    # @return {nil}
    def insert_hash(data, is_id = false)
        if is_id
            id = is_id
        else 
            id = new_id
        end
        txt = data.values.join(',')
        @data[id] = txt
        update_index(id, txt)
    end

    ################ update_index #################
    # Updates the inverted index to include a new entry
    # @return {nil}
    def update_index(id, txt)
        values = txt.split(',')
        values.each do |value|
            @index[value] ||= []
            @index[value] << id
        end
    end

    ################ new_id #################
    # Generates a new id based on the maximum existing id
    # @return {String}
    def new_id
        id = (@data.keys.map(&:to_i).max + 1).to_s
    end

    ################ get_column_id #################
    # Returns the index of a column in the data set
    # @return {Integer}
    def get_column_id(value)
        column_lists = @data['0'].split(',')
        col_id = column_lists.index(value)
    end

    ################ key_exist? #################
    # Checks if a key exists in the data hash
    # @return {Boolean}
    def key_exist?(id)
        result = @data.has_key?(id)        
    end

    ################ delete_entry #################
    # Deletes an entry from the data hash and updates the index
    # @return {nil}
    def delete_entry(id)
        data = @data[id].split(',')
        data.each do |value|
            @index[value].delete(id)
            if(@index[value] == [])
                @index.delete(value)
            end
        end
        @data.delete(id)
    end

    ################ modify_entry #################
    # Modifies an existing entry in the data hash and updates the index
    # @return {nil}
    def modify_entry(new_data, id)
        id = id.to_s
        delete_entry(id)
        insert_hash(new_data, id)
    end


    def has_generic_key?(hash)
        array = hash.keys
        array.any? { |string| string.include? "generic_header" }
    end

    def standardize_hash(old_hash)
        headers = @data['0'].split(',')
        headers_enum = headers.to_enum
        new_hash = old_hash.transform_keys { |_key| headers_enum.next }
    end

    ################ create_new_data #################
    # Creates a new data entry by merging old data with the new one based on headers
    # @return {Hash}
    def create_new_data(data, id)
        headers = @data['0'].split(',')
        old_data = @data[id].split(',')
        new_data = {}
        new_headers = data.keys
        new_values = data.values
        jndex = 0
        headers.each.with_index do |header, index|
            if header == new_headers[jndex]
                new_data[header] = new_values[jndex]
                jndex += 1
            else
                new_data[header] = old_data[index]
            end
        end
        new_data
    end

     ################ update_value #################
    # Updates a value in the data hash
    # @return {nil}
    def update_value(data)
        values = data.values
        id = values[0].to_s
        if key_exist?(id)
            new_data = create_new_data(data, id)
            modify_entry(new_data, id)
        end
    end

    ################ modify_column #################
    # Modifies a column of entries based on an id list
    # @return {Hash}
    def modify_column(data, id_list)
        new_list = id_list.dup
        new_list.each do |id|
            if id == '0'
                next
            end
            new_data = create_new_data(data, id)
            modify_entry(new_data, id)
        end
      @index
    end

    ################ get_db #################
    # Converts data hash to a 2D matrix form
    # @return {Array}
    def get_db
        matrix = []
        @data.each do |elem|
            row = []
            row = elem[1].split(',')
            matrix << row
        end
       matrix
    end

    def get_row_range
        row_ids = []
        @data.each do |elem|
            row = elem[0]
            row_ids << row
        end
        row_ids
    end

    ################ get_id_list #################
    # Retrieves list of ids associated with a given value
    # @return {Array}
    def get_id_list(value)
      id_list = @index[value]
    end

    def get_header_list
        @data['0'].split(',')
    end

    ################ search #################
    # Searches for a value in the index and returns corresponding data entries
    # @return {Array}
    def search(value)
        id_list = @index[value]
        return [] unless id_list
        id_list.map { |id| @data[id] }
    end

    def get_db_at(col_ids, row_ids)
        matrix = []
        row_ids << '0'
        @data.each.with_index do |elem, index|
            if row_ids.index(index.to_s)
                row = []
                row = elem[1].split(',')
                result = []
                col_ids.each do |col_id|
                    result << row[col_id]
                end
                matrix << result
            end
        end
       matrix
    end

    def get_row_id(value, column_id)
        id_list = @index[value]
        id_list.map do |id| 
            row = @data[id].split(',')
            if row[column_id] == value
                id
            end
        end
        id_list
    end

    ################ from_to #################
    # Retrieves a submatrix of data entries between given column indices
    # @return {Array}
    def from_to(from, to)
        matrix = []
        @data.each do |elem|
            row = []
            values = elem[1].split(',')
            for val in from..to do
                row << values[val]
            end
            matrix << row
        end
        matrix
    end
end