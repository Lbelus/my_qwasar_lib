"""
Description
Given a chemical formula (given as a string), return the count of each atom.

An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

Example 1:

**Input:** formula = "H2O"

**Output:**"H2O"

**Explanation:** The count of elements are {'H': 2, 'O': 1}.
Example 2:

**Input:** formula = "Mg(OH)2"

**Output:**"H2MgO2"

**Explanation:** The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
Example 3:

**Input:** formula = "K4(ON(SO3)2)2"

**Output:**"K4N2O14S4"

**Explanation:** The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
Note:

All atom names consist of lowercase letters, except for the first character which is uppercase.
The length of formula will be in the range [1, 1000].
formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.

"""

"""
:type  param_1: {String}
:rtype: string
"""
def is_closing(bracket):
    if bracket == ')':
        return True
    return False

def is_open(bracket):
    if bracket == '(':
        return True
    return False

def get_atom(str):
    stack = []
    stack.append('(') 
    index = 1
    strlen = len(str)
    while index < strlen and stack:
        if is_open(str[index]):
            stack.append(str[index])
        elif is_closing(str[index]) and stack:
            stack.pop()
        index += 1
    while index < strlen and str[index].isdigit():
        index += 1
    return str[:index ]

def get_multiplier(str):
    num_str = ""
    for ch in reversed(str):
        if not ch.isdigit():
            break
        num_str += ch
    num_str = num_str[::-1]
    num = int(num_str)
    return int(num)

def get_subatoms(strlen, str):
    stack = []
    index = 0
    while index < strlen:
        if str[index].isupper():
            tmp = str[index]
            index += 1
            while index < strlen and (str[index].islower() or str[index].isdigit()):
                tmp += str[index]
                index += 1
            stack.append(tmp)
        elif is_open(str[index]):
            tmp = get_atom(str[index:])
            stack.append(tmp)
            index += len(tmp)
            if tmp[-1].isdigit():
                num = get_multiplier(tmp)
                stack.pop()
                for jdnex in range(num):
                    stack.append(get_subatoms(len(tmp[1:]),tmp[1:]))
        else:
            index += 1
    return stack

def flatten(arr, multiplier=1):
    flat_stack = []
    for item in arr:
        if isinstance(item, list):
            flat_stack.extend(flatten(item, multiplier))
        else:
            element = ''.join(filter(str.isalpha, item))
            local_multiplier = int(''.join(filter(str.isdigit, item))) if any(char.isdigit() for char in item) else 1
            total_multiplier = local_multiplier * multiplier
            flat_stack.append(f"{element},{total_multiplier}")
    return flat_stack

def rebuild_atom(flat_stack):
    dict = {}
    for elem in sorted(flat_stack):
        tokens = elem.split(',') 
        if tokens[0] in dict:
          dict[tokens[0]] += int(tokens[1])
        else:
            dict[tokens[0]] = int(tokens[1])
    formula = ''.join(f"{element}{count}" if count > 1 else element for element, count in dict.items())
    return formula

def number_of_atoms(str):
    strlen = len(str)
    stack = get_subatoms(strlen, str)
    flat_stack = flatten(stack)
    return rebuild_atom(flat_stack)