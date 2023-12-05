"""
Description
Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary number (from most-significant-bit to least-significant-bit.)

Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

Example 1:

**Input:** [0,1,1]

**Output:** [true,false,false]

**Explanation:** The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10. Only the first number is divisible by 5, so answer[0] is true.
Example 2:

**Input:** [1,1,1]

**Output:** [false,false,false]
Example 3:

**Input:** [0,1,1,1,1,1]

**Output:** [true,false,false,false,true,false]
Example 4:

**Input:** [1,1,1,0,1]

**Output:** [false,false,false,false,false]

example 5:

**input:** [1, 1, 0, 0, 0, 1, 0, 0, 1]
**Output:** [false, false, false, false, false, false, false, false, false]

example 6:

**input:** [1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0]
**Output:** [false, false, false, false, false, true, false, false, false, true, false, false, true, false, false, false, false, true, true]


"""


"""
:type  param_1: {Integer[]}
:rtype: boolean[]
"""

def isdivby5(bin_num):
  index = len(bin_num) - 1
  result = 0
  r = []
  while index >= 0:
    bits = bin_num[-(index + 1)]
    result += bits  * pow(2 , index)
    r.append(result)
    index -= 1
  result %= 5
  return result == 0

def binary_prefix_divisible_by_(bin_num):
  arr_len = len(bin_num)
  index = 0
  result = []
  while index < arr_len:
    result.append(isdivby5(bin_num[:index + 1]))
    index += 1
  return result