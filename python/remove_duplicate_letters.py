#
#
# QWASAR.IO -- remove_duplicate_letters
#
#
# @param {String} param_1
#
# @return {integer}
#

"""
Description
Given a string which contains only lowercase letters, 
remove duplicate letters so that every letter appear once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

**Input:**"bcabc"

**Output:**"abc"

**Input:**"cbacdcbc"

**Output:**"acdb"
"""



def remove_duplicate_letters(string):
    freq = [0] * 127
    result = []
    for ch in string:
        value = ord(ch)
        freq[value] += 1
    for ch in string:
        value = ord(ch)
        freq[value] -= 1
        if ch not in result:
            while result and value < ord(result[-1]) and freq[ord(result[-1])]:
                result.pop()
        result.append(ch)
    return ''.join(result)