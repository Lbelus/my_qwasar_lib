def my_roman_numerals_converter(nbr)
    roman_map = {
        (1000) => "M",
        (900) => "CM",
        (500) => "D",
        (400) => "CD",
        (100) => "C",
        (90) => "XC",
        (50) => "L",
        (40) => "XL",
        (20) => "XX",
        (10) => "X",
        (9) => "IX",
        (5) => "V",
        (4) => "IV",
        (1) => "I"
    }
    str= ""
    while nbr > 0
        roman_map.each do |range, letter|
            if (nbr % range) != nbr
                nbr -= range
                str << letter
                break
            end
            if (nbr % range) == 0
                nbr = 0
                break
            end
        end
    end
    str
end
  
#   test = 2022
  # 14 XIV
  # 79
  # 845 DCCCXLV
  # 2022 MMXXII
#   p my_roman_numerals_converter(test)