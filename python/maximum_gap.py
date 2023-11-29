"""

Description
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

**Input:** [3,6,9,1]

**Output:** 3

**Explanation:** The sorted form of the array is [1,3,6,9], either   (3,6) or (6,9) has the maximum difference 3.


**Input:** [10]

**Output:** 0

**Explanation:** The array contains less than 2 elements, therefore return 0.

"""

"""
:type  param_1: {Integer[]}
:rtype: integer
"""
def dumb_sort(arr):
  index = 0
  jndex = 0
  arrlen = len(arr)
  while index < arrlen:
    jndex = index
    while jndex < arrlen:
        if arr[jndex] < arr[index]:
            tmp = arr[index]
            arr[index] = arr[jndex]
            arr[jndex] = tmp
        jndex += 1
    jndex = 0
    index += 1
  return arr


def maximum_gap(arr):
    sorted_arr = dumb_sort(arr)
    index = 0
    arrlen = len(sorted_arr)
    max_diff = 0
    while index < arrlen:
        if index + 1 < arrlen:
            new_diff = arr[index + 1] - arr[index]
        if new_diff > max_diff:
            max_diff = new_diff
        index += 1
    return max_diff