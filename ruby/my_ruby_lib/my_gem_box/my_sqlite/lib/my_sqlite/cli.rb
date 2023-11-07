#require_relative 'my_sqlite_request.rb'

class Query
    # @param {String} command
    # @param {String[]} columns
    # @param {String} table
    # @param {String[][]} where
    # @param {String[][]} join
    attr_accessor :from, :select, :where, :join, :order, :insert, :values, :update, :set, :delete, :quit    

    def initialize(from = nil, select = nil, where = nil, join = nil, order = nil, insert = nil, values = nil, update = nil, set = nil, delete = nil, quit = nil)
        @update = update
        @insert = insert
        @from = from
        @select = select
        @where = where
        @join = join
        @order = order 
        @values = values
        @set = set
        @delete = delete
        @quit = quit
    end
end


module QueryMethods 

    def iskeyword?(str)
        cmnds = ['SELECT', 'INSERT', 'UPDATE', 'DELETE', 'FROM', 'WHERE', 'JOIN']
        upper = str.upcase #upper case string
        return cmnds.include?(upper) 
    end

    def isfrom?(str)
        upper = str.upcase
        return (upper == 'FROM')
    end


    def __get_input__
        result = gets.chomp
        return result
    end

    ################ get text #################
    # Gets the input from the keyboard.
    # @return {String}
    def get_text()
        text = ""
        while (1)
            text += __get_input__
            if text[text.length() - 1] == ';'
                text = text.chop #removes the last char
                break;
            end
            text += ' '
        end
        no_left_spaces = text.lstrip
        no_l_r_spaces = no_left_spaces.rstrip
        no_l_r_spaces
    end

    ##################### errors? ################
    # Check the correctness of the original query.
    def errors?(query)
        if (query == nil || query.empty?())
            return true
        elsif (query[0].casecmp("select") == 0 && valid_select?(query))
            return false
        elsif (query[0].casecmp("update") == 0 && valid_update?(query))
            return false
        elsif (query[0].casecmp("delete") == 0 && valid_delete?(query))
            return false
        elsif (query[0].casecmp("insert") == 0 && valid_insert?(query))
            return false
        else 
            return true;
        end
    end

    ##################### valid_set? ################
    def valid_set?(query)
        set_idx = find_keyword_idx(query, "set")
        where_idx = find_keyword_idx(query, "where")
        finish = query.size();
        if where_idx != nil
            finish = where_idx[0]
        end
        if set_idx == nil || set_idx.size() > 1
            return false
        elsif where_idx != nil && where_idx.size() > 1
            return false
        elsif finish < set_idx[0]
            return false
        #incorrect set conditions
        elsif (finish - set_idx[0] - 1) % 3 != 0
            puts "HERE #{((finish))}"
            puts "HERE #{((set_idx[0]))}"
            puts "HERE #{((finish - set_idx[0] - 1))}"
            puts "HERE #{((finish - set_idx[0] - 1) % 3)}"
            return false
        end

        return true
    end

    ##################### valid_update? ################
    def valid_update?(query)
        if query.empty?()
            return false
        elsif query[0].casecmp("update") != 0
            return false
        elsif query.length() < 4
            return false
        elsif query[2].casecmp("set") != 0
            return false
        elsif !valid_set?(query)
            return false
        elsif (!valid_update_delete_where?(query, find_keyword_idx(query, 'where')))
            return false
        end
        return true
    end
    
    ##################### valid_delete? ################
    def valid_delete?(query)
        if query.empty?()
            return false
        elsif query[0].casecmp("delete") != 0
            return false
        elsif query[1].casecmp("from") != 0
            return false
        elsif (!valid_update_delete_where?(query, find_keyword_idx(query, 'where')))
            return false
        end
        return true
    end
    
    ##################### valid_insert? ################
    def valid_insert?(query)
        if query.empty?()
            return false
        elsif query.length < 5
        elsif query[0].casecmp("insert") != 0
            return false
        elsif query[1].casecmp("into") != 0
            return false
        elsif query[3].casecmp("values") != 0 &&
              query[4].casecmp("values") != 0  
            return false
        # TODO 
        # check that the number of columns matche the number of values
        end
        return true
    end
    
    ##################### valid_select? ################
    def valid_select?(query)
        if (query.length() < 4)
            return false
        elsif (!iskeyword?(query[0]))
            return false
        elsif (!valid_from?(query))
            return false
        elsif (!valid_select_where?(query, find_keyword_idx(query, 'where')))
            return false
        elsif (!valid_join?(query, find_keyword_idx(query, 'join')))
            return false
        else 
            return true
        end
    end


    ##################### valid_from ##################
    # Checks the correctness of the FROM keyword.
    # @param {String[]} query. Original query split by words. 
    # @return {Boolean}
    def valid_from?(query)
        if  query.length() >= 4         && 
            count_from(query) == 1      &&
            query[2].casecmp("from") == 0
                return true
        else 
            false
        end
    end

    ##################### count_from ##################
    # @param {String[]} query. Original query split by words. 
    # Counts the number of FROM keywords.
    # @return {Integer}
    def count_from(query) 
        count = 0
        query.each do |w|
            if w.casecmp("from") == 0
                count += 1
            end
        end
        count
    end


    ##################### valid_join? ##################
    def valid_join?(query, idx) 
        #there is no join keyword
        if idx == nil
            return true
        end
        if (query.size() - 1 - idx[0]) != 5
            return false
        elsif query[idx[0] + 2].casecmp("on") != 0
            return false     
        elsif query[idx[0] + 4] != '='
            return false;
        else
            return true
        end

    end

    
    ##################### valid_update_delete_where? ##################
    def valid_update_delete_where?(query, idx)
        #there is no where keyword
        if idx == nil
            return true
        end
        if (query.size() - 1 - idx[0]) != 3
            return false
        elsif query[idx[0] + 2] != '='
            return false     
        else
            return true
        end
    end

    ##################### valid_select_where? ##################
    def valid_select_where?(query, idx)
        #there is no where keyword
        if idx == nil
            return true
        end
        if (query.size() - 1 - idx[0]) < 3
            return false
        elsif query[idx[0] + 2] != '='
            return false     
        elsif (query.size() - 1 - idx[0]) > 3 && !iskeyword?(query[idx[0] + 4])
            return false;
        else
            return true
        end
    end


    ##################### get_where_cndt ##################
    # @param {String[]} query. Original query split by words. 
    # @param {Query} query_class. Query class object.
    # Gets where condition.
    def get_where_cndt(query, query_class) 
        where_idx = find_keyword_idx(query, 'where')
        if where_idx == nil
            return true
        end
        # if (!where_idx.empty?() && where_idx[0] != 4)
        #     return false
        # els
        if (!where_idx.empty?()) 
            query_class.where = Array.new
            where_idx.each do |where_loc|
                where_cndt = Array.new
                #add three words after where
                where_cndt.push(query[where_loc + 1])
                # skip equal sign and add criteria
                where_cndt.push(query[where_loc + 3]) 
                query_class.where.push(where_cndt)        
            end
        end
        return true
    end
    
    ##################### get_join_cndt ##################
    # @param {String[]} query. Original query split by words. 
    # @param {Query} query_class. Query class object.
    # Gets join condition.
    def get_join_cndt(query, query_class) 
        join_idx = find_keyword_idx(query, 'join')
        if join_idx == nil
            return nil
        end          
        if (!join_idx.empty?())
            join_cndt = Array.new
            join_loc = join_idx[0]
            join_cndt.push(query[join_loc + 3])
            join_cndt.push(query[join_loc + 1])
            # skip equal sign
            join_cndt.push(query[join_loc + 5])
            query_class.join = join_cndt
        end
    end

    ##################### get_query ##################
    # @param {String[]} query. Original query split by words. 
    # @return {Query}. The object of the query class.  
    def get_query(query)
        #add columns to 'select' and table name to 'from'
        q = Query.new();
        if query[0].casecmp("select") == 0
            q.select = query[1].split(',')
            q.from = query[3];
            get_join_cndt(query, q)
        elsif query[0].casecmp("update") == 0
            q.update = query[1]
            data = {}
            # find the start of set
            start = find_keyword_idx(query, 'set')[0] + 1
            finish = query.size()
            while (start < finish && !iskeyword?(query[start]))
                data[query[start]] = query[start + 2]
                start += 3
            end
            q.set = data
        elsif query[0].casecmp("delete") == 0
            q.delete = true
            q.from = query[2]
        elsif query[0].casecmp("insert") == 0
            q.insert = query[2]
            data = {}
            vals = Array[]
            keys = Array[]
            has_values = 0
            if (query[3].casecmp("values") != 0) 
                keys = query[3].split(',')
                has_values = 1
            end
                 
            vals = query[query.length - 1].split(',')
            vals.length.times do |i|
                if (has_values == 0)
                    key = "generic_header_" + (i + 1).to_s
                    data[key] = vals[i]
                else
                    data[keys[i]] = vals[i]
                end
            end
            q.values = data
        end
        get_where_cndt(query, q) 
        q       
    end

    ##################### find_where_idx ##################
    # Finds locations of all WHERE keywords in the query.
    #
    # Returns an array of indeces or empty array.
    def find_keyword_idx(query, keyword) 
        keyword_idx = Array.new    
        count = 0
        query.each do |w|
            if w.casecmp(keyword) == 0
                keyword_idx.push(count)
            end
            count += 1
        end
        if keyword_idx.empty?() 
            return nil
        else
            return keyword_idx
        end
    end

    ##################### run_cli ##################
    def run_cli() 
        query = get_text()
        if query.casecmp("quit") == 0 
            q = Query.new();
            q.quit = true;
            return q
        end
        keyword = query[0..5] #extract first six chars
        if  (keyword.casecmp("select") == 0 ||
            keyword.casecmp("update") == 0 ||
            keyword.casecmp("delete") == 0 ||
            keyword.casecmp("insert") == 0)
                query.gsub!(", ", ",")
                query.gsub!(" ,", ",")
                query.gsub!("(", " ")
                query.gsub!(")", " ")
                query.gsub!("\n", " ")
        else
            return nil
        end
        words = split_string_by_words(query)
        # p words
        if !errors?(words)
            return get_query(words)
        else
            return nil
        end
    end

end

def split_string_by_words(str)
    words = []
    word = ""
    inside_quotes = false
  
    str.each_char do |char|
      if char == ' ' && !inside_quotes
        words << word unless word.empty?
        word = ""
      elsif char == '"' || char == '\''
        inside_quotes = !inside_quotes
      else
        word << char
      end
    end
  
    words << word unless word.empty?
    words
  end
  
# include QueryMethods

# p run_cli()
