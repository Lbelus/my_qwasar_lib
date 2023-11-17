##
##
## QWASAR.IO -- my_data_transform
##
##
## @param {String} param_1
##
## @return {string[]}
##

# csv = "Gender,FirstName,LastName,UserName,Email,Age,City,Device,Coffee Quantity,Order At\nMale,Carl,Wilderman,carl,wilderman_carl@yahoo.com,29,Seattle,Safari iPhone,2,2020-03-06 16:37:56\nMale,Marvin,Lind,marvin,marvin_lind@hotmail.com,77,Detroit,Chrome Android,2,2020-03-02 13:55:51\nFemale,Shanelle,Marquardt,shanelle,marquardt.shanelle@hotmail.com,21,Las Vegas,Chrome,1,2020-03-05 17:53:05\nFemale,Lavonne,Romaguera,lavonne,romaguera.lavonne@yahoo.com,81,Seattle,Chrome,2,2020-03-04 10:33:53\nMale,Derick,McLaughlin,derick,mclaughlin.derick@hotmail.com,47,Chicago,Chrome Android,1,2020-03-05 15:19:48\n"

def my_csv_parser(param_1)
    tokens = param_1.split("\n")
    matrix = tokens.map { |token| token.split(",")}
end

def get_provider(matrix, col_no)
    matrix.map do |row|
        index = row[col_no].index("@")
        if index != nil
            row[col_no].slice!(0, index + 1)
        end
    end
end

def replace_data(matrix, group_map, col_no)
    matrix.map.with_index do |row, index|
        if index > 0
            row[col_no] = group_map.each do |range, group|
                if range.include?(row[col_no].to_i)
                    break group
                end
            end
        end
    end
end

def replace_time(matrix, group_map, col_no)
    matrix.map.with_index do |row, index|
        if index > 0
            row[col_no] = group_map.each do |range, group|
                hour_str = row[col_no].split(" ")[1].split(":")[0]
                if range.include?(hour_str.to_i)
                    break group
                end
            end
        end
    end
end

def merge_tokens(matrix)
    merge_token = ""
    merged_matrix = matrix.map { |row| row.join(",") }
end

def my_data_transform(param_1)
    age_map = {
        (1..20) => "1->20",
        (21..40) => "21->40",
        (41..65) => "41->65",
        (66..99) => "66->99"
    }
    time_map = {
        (6..11) => "morning",
        (12..18) => "afternoon",
        (18..23) => "evening"
    }
    matrix = my_csv_parser(param_1)
    replace_data(matrix, age_map, 5)
    replace_time(matrix, time_map, 9)
    get_provider(matrix, 4)
    merge_tokens(matrix)
end