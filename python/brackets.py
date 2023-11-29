##
##
## QWASAR.IO -- brackets
##
##
## @param {String} param_1
##
## @return {integer}
##

"""
Write a function that one string as argument. The function returns 1
if the expression is correctly bracketed, otherwise it returns 0.

Symbols considered as 'brackets' are brackets '(' and ')', square brackets '['
and ']'and braces '{' and '}'. Every other symbols are simply ignored.

An opening bracket must always be closed by the good closing bracket in the
correct order. A string which not contains any bracket is considered as a
correctly bracketed string.


Input: "(johndoe)"
Output: 1


Input: "([)]"
Output: 0


Input "{[(0 + 0)(1 + 1)](3*(-1)){()}}"
Output: 1

Input ""
Output: 1

"""


def is_closing(bracket):
    if bracket == ')' or bracket == ']' or bracket == '}':
        return True
    return False

def is_open(bracket):
    if bracket == '(' or bracket == '[' or bracket == '{':
        return True
    return False

def match_closing(bracket):
    bracket_pairs = {'(': ')', '[': ']', '{': '}'}
    return bracket_pairs.get(bracket, None)


def brackets(str):
    stack = []
    for ch in str:
        if is_open(ch):
            stack.append(ch)
        elif is_closing(ch) and stack:
            o_bracket = stack.pop()
        if match_closing(o_bracket) == ch:
            continue
        else:
            return False
    return True