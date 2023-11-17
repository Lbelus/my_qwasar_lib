##
##
## QWASAR.IO -- my_csv_parser
##
##
## @param {String} param_1
## @param {String} param_2
##
## @return {string[][]}
##

csv = "a,b,c,e\n1,2,3,4\n"
csv2 = "1,2,3\n4,5,6\n7,8,9" 
delimiter = ","


def my_csv_parser(param_1, param_2)
    tokens = param_1.split("\n")
    matrix = tokens.map { |token| token.split(param_2)}
end