"""
Description
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.


ex1:

**Input:** words = ["cat","bt","hat","tree"], chars = "atach"

**Output:** 6

**Explanation:** The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6


ex2:

**Input:** words = ["hello","world"], chars = "welldonehoneyr"

**Output:** 10

**Explanation:** The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.

"""



"""
:type  param_1: {String[]}
"""

"""
:type  param_2: {String}
:rtype: integer
"""
import copy

def create_freq(chars):
    freq = [0] * 127
    for char in chars:
        val = ord(char)
        freq[val] += 1
    return freq

def check_freq(word, chars_freq):
    word_freq = create_freq(word)
    index = 0
    for index in range(127):
        chars_freq[index] -= word_freq[index]
        if chars_freq[index] < 0:
            return False
    return True

def find_words_that_can_be_formed_by_characters(words, chars):
    freq = create_freq(chars)
    total_count = 0
    for word in words:
        cpy_freq = copy.deepcopy(freq)
        if check_freq(word, cpy_freq):
            total_count += len(word)
    return total_count