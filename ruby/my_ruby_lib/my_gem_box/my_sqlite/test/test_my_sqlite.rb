require 'minitest/autorun'
require 'mocha/minitest'
require_relative '../lib/my_sqlite'

class MySqliteInstanceTest < Minitest::Test

    def test_cli_select
        quit = ["quit",";"]
        test_array = [
            ["select first_name\nfrom data.csv\nwhere job = Engineer",";"],
            ["select first_name, last_name","from data.csv","where job = Engineer",";"],
            ["select first_name,last_name\nfrom data.csv\nwhere job = Engineer",";"],
            ["select *\nfrom data.csv\nwhere job = Engineer",";"],
            ["select *\nfrom data.csv\n",";"],
        ]
        test_array.each do |_test_|
            puts "/!\\ Testing SELECT against #{_test_}:\n\n"
            MySqliteInstance.any_instance.stubs(:__get_input__).returns(*_test_, *quit)
            sqlite_instance = MySqliteInstance.new
            result = sqlite_instance.instanciation
            puts "\n\n"
        end        
    end

    def test_cli_update
        quit = ["quit",";"]
        test_array = [
            ["update data.csv","set job = пенсионер","where job = Engineer",";"],
            ["update data.csv","set job = пенсионер","age = 20",";"],
            ["update data.csv","set job = пенсионер",";"]
        ]
        test_array.each do |_test_|
            puts "/!\\ Testing UPDATE against #{_test_}:\n\n"
            MySqliteInstance.any_instance.stubs(:__get_input__).returns(*_test_, *quit)
            sqlite_instance = MySqliteInstance.new
            result = sqlite_instance.instanciation
            puts "\n\n"
        end
    # assert_equal 'stubbed value', result
    end

    def test_cli_delete
        quit = ["quit",";"]
        test_array = [
            ["delete","from data.csv","where job = Engineer",";"],
            ["delete","from data.csv",";"]
        ]
        test_array.each do |_test_|
            puts "/!\\ Testing DELETE against #{_test_}:\n\n"
            MySqliteInstance.any_instance.stubs(:__get_input__).returns(*_test_, *quit)
            sqlite_instance = MySqliteInstance.new
            result = sqlite_instance.instanciation
            puts "\n\n"
        end
    # assert_equal 'stubbed value', result
    end

    def test_cli_insert
        quit = ["quit",";"]
        test_array = [
            ["insert into data.csv","VALUES 16, 'Spooder', 'Man', 'ceiling_crawler', 23",";"],
            ["insert into data.csv\nVALUES 16, 'Spooder', 'Man', 'ceiling crawler', 23",";"]
        ]
        test_array.each do |_test_|
            puts "/!\\ Testing INSERT against #{_test_}:\n\n"
            MySqliteInstance.any_instance.stubs(:__get_input__).returns(*_test_, *quit)
            sqlite_instance = MySqliteInstance.new
            result = sqlite_instance.instanciation
            puts "\n\n"
        end
    # assert_equal 'stubbed value', result
    end

    def test_cli_error
        quit = ["quit",";"]
        test_array = [
            ["select error_col","from data.csv",";"],
            ["update data.csv","first_name = Burnault",";"],
        ]
        test_array.each do |_test_|
            puts "/!\\ Testing ERRORS against #{_test_}:\n\n"
            MySqliteInstance.any_instance.stubs(:__get_input__).returns(*_test_, *quit)
            sqlite_instance = MySqliteInstance.new
            begin
                result = sqlite_instance.instanciation
            rescue TypeError => error
                puts "Caught error: #{error}"
            end
                puts "\n\n"
        end
        # assert_equal '', stderr # No error messages
        # assert_equal 'stubbed value', result
    end

    def test_methods
        
        request = MySqliteRequest.new
        puts "/!\\ Testing METHODS FROM_WHERE_DELETE against:\n\n"
        request.from('data.csv').where('job', 'Engineer').delete.run
        puts

        puts "/!\\ Testing METHODS FROM_JOIN against join first_name job:\n\n"
        request = request.from('data.csv').join('first_name', 'data.csv', 'job').run
        puts
        
        puts "/!\\ Testing METHODS FROM ORDER against order job:\n\n"
        request = request.from('data.csv').order(:asc,'job').run
        puts

        puts "/!\\ Testing METHODS SELECT WHERE #01:\n\n"
        request = request.select('first_name').from('data.csv').where('job', 'Engineer').run
        puts
        # request = nil
        # request = MySqliteRequest.new
        puts "/!\\ Testing METHODS SELECT WHERE #02:\n\n"
        request = request.select('*').from('data.csv').where('job', 'Engineer').run
        puts

        insert_data = {
           'index' => 17,
           'first_name' => 'Peter',
           'last_name' => 'Parker',
           'job' => 'Photographer',
           'age' => 23
        }

        update_data = {
           'index' => 15,
           'first_name' => 'Spooder',
           'last_name' => 'Man',
           'job' => 'ceiling crawler'
        }

        set_data = {
            'job' => "пенсионер",
        }
        puts "/!\\ Testing METHODS INSERT :\n\n"
        request = request.insert('data.csv').values(insert_data).run
        puts
        puts "/!\\ Testing METHODS UPDATE VALUE :\n\n"
        request = request.update('data.csv').values(update_data).run
        puts
        puts "/!\\ Testing METHODS SET VALUE :\n\n"
        request = request.update('data.csv').set(set_data).where('job', 'Engineer').run
        puts
    end

end