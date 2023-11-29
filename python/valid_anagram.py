"""

Description
Given two strings s and _t _, write a function to determine if t is an anagram of s.


**Input:** _s_ = "anagram", _t_ = "nagaram"

**Output:** true

**Input:** _s_ = "rat", _t_ = "car"

**Output:** false


"""

"""
:type  param_1: {String}
"""
"""
:type  param_2: {String}
:rtype: boolean
"""

def valid_anagram(dest, src):
    if len(dest) != len(src):
        return False
    freq1 = [0]*127
    freq2 = [0]*127
    for char1, char2 in zip(dest, src):
        val1 = ord(char1)
        val2 = ord(char2)
        freq1[val1] += 1
        freq2[val2] += 1
    index = 0
    while index < 127:
        if freq1[index] != freq2[index]:
            return False
        index += 1
    return True