#
#
# QWASAR.IO -- capitalize
#
#
# @param {String} param_1
#
# @return {integer}
#
"""
Write a function that takes one string and capitalizes the first character of each word
(If it's a letter, obviously), the rest will be in lowercase, and returns the result.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]


Input: "a FiRSt LiTTlE TESt"
Output: "A First Little Test"


Input: "__second Test A Little Bit   Moar Complex"
Output: "__second Test A Little Bit   Moar Complex"


Input "   But... This iS not THAT COMPLEX"
Output: "   But... This Is Not That Complex"


Input "     Okay, this is the last 1239809147801 but not    the least    t"
Output: "     Okay, This Is The Last 1239809147801 But Not    The Least    T"


Input ""
Output: ""

"""


"""
:type  param_1: {String}
:rtype: string
"""


def capitalize(string):
    tokens = string.split(' ')
    result = []
    for token in tokens: 
        tmp = token[:1].upper() + token[1:].lower()
        result.append(tmp)
    return ' '.join(result)