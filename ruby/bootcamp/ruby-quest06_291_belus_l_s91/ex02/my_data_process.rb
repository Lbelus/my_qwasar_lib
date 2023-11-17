##
##
## QWASAR.IO -- my_data_process
##
##
## @param {String[]} param_1
##
## @return {string}
##

# discard the column FirstName, LastName, UserName and Coffee Quantity

require 'json'

# csv = ["Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At", "Male,Carl,Wilderman,carl,yahoo.com,21->40,Seattle,Safari iPhone,2,afternoon", "Male,Marvin,Lind,marvin,hotmail.com,66->99,Detroit,Chrome Android,2,afternoon", "Female,Shanelle,Marquardt,shanelle,hotmail.com,21->40,Las Vegas,Chrome,1,afternoon", "Female,Lavonne,Romaguera,lavonne,yahoo.com,66->99,Seattle,Chrome,2,morning", "Male,Derick,McLaughlin,derick,hotmail.com,41->65,Chicago,Chrome Android,1,afternoon"]

def delete_col(matrix, col_no)
    matrix.map do |row|
        row.delete_at(col_no)
    end
end

def my_data_process(param_1)
    matrix = param_1.map { |token| token.split(",")}
    column_to_remove = [1, 2, 3, 8]

    column_to_remove.each_with_index do |x, index|
        delete_col(matrix, x - index)
    end
    headers = matrix.shift

    grouped_data = {}
    
    matrix.each do |row|
      headers.each_with_index do |header, index|
        if index >= 0
          grouped_data[header] ||= {}
          grouped_data[header][row[index]] ||= 0
          grouped_data[header][row[index]] += 1
        end
      end
    end
    json_string = JSON.generate(grouped_data)
end

# my_data_process(csv)