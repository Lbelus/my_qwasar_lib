#
#
# QWASAR.IO -- str_maxlenoc
#
#
# @param {String} param_1
#
# @return {integer}
#

"""

Description
Write a function that takes an array of strings and returns
the longest string that appears in every parameter's strings. If more that one
string qualifies, it will return the one that appears first in the first
parameter. Note that the empty string technically appears in any string.


Input: ["ab", "bac", "abacabccabcb"]
Output: 
Return Value: "a"


Input: ["bonjour", "salut", "bonjour", "bonjour"]
Output: 
Return Value: "u"


Input: ["xoxAoxo", "xoxAox", "oxAox"]
Output: 
Return Value: "oxAox"

"""

"""
:type  param_1: {String[]}
"""
"""
:type  param_2: {Integer}
:rtype: string
"""
def min_str(array):
    if not array:
        return None
    return min(array, key=len)


def generate_substrings(string):
    substrings = []
    for start in range(len(string)):
        for end in range(start + 1, len(string) + 1):
            substrings.append(string[start:end])
    return substrings

def str_maxlenoc(param_1):
    small_str = min_str(param_1)
    param_1.remove(small_str)
    substr_arr = generate_substrings(small_str)
    arrlen = len(substr_arr)
    index = 0
    substr_arr.sort(key=len, reverse=True)
    for string in param_1:
        while index < arrlen:
            if string.find(substr_arr[index]) == -1:
                substr_arr.remove(substr_arr[index])
                arrlen -= 1
                index = 0
            index += 1
        index = 0
    if substr_arr:
        return max(substr_arr, key=len)
    else:
        return ''