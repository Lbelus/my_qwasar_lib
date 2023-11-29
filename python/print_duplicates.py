"""
:type  param_1: {Integer[]}
"""
"""
:type  param_2: {Integer}
"""

"""
:type  param_3: {Integer[]}
"""

"""
:type  param_4: {Integer}
:rtype: integer[]
"""
def print_duplicates(param_1, param_2, param_3, param_4):
    index = 0
    jndex = 0
    result = []
    while index < param_2 and jndex < param_4:
        if (param_1[index] == param_3[jndex]):
            result.append(param_1[index])
            index += 1
            jndex += 1
        elif param_1[index] < param_3[jndex]:
            index += 1
        elif param_1[index] > param_3[jndex]:
            jndex += 1
    return result