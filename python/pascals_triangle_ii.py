
"""
Description
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

**Input:** 3

**Output:** [1,3,3,1]
"""

"""
:type  param_1: {Integer}
:rtype: integer[]
"""


def pascals_triangle_ii(size ):
  arr = [[1]]
  for index in range(size):
    row = [1]
    for jndex in range(index):
      row.append(arr[index][jndex] + arr[index][jndex + 1])
    row.append(1)
    arr.append(row)
  return arr[-1]