#!/usr/bin/env ruby

require_relative 'my_sqlite/cli'

class MySqliteInstance
    include QueryMethods
    
    def _execute_(object, hash)
        # object
        # p hash
        hash.each do |method, argument|
            if object.respond_to?(method)
                if method == "where" or method == "order" or method == "join" and argument != nil
                    object.send(method, *argument[0])
                elsif method == "delete" and argument == true
                    object.send(method)
                elsif method == "quit" and argument == true
                    return object.send(method)
                elsif argument != nil
                    object.send(method, argument)
                end
            else
                p "#{method} does not belong to my_sqlite"
            end
        end
        true
    end

    def instanciation(database_name = nil)
        result = true
        while result
            result = run_cli
            if result == nil
                result = true
                next
            end
            request = MySqliteRequest.new(result)
            result = _execute_(request, request.options)
            if result != false
                request.state += 1
                request.run
            end
        end
    end

end

def my_sqlite(database_name = nil)
    sqlite_object = MySqliteInstance.new
    sqlite_object.instanciation
end

require_relative 'my_sqlite/my_sqlite_request'
# require_relative 'InvertedIndex'

# my_sqlite
