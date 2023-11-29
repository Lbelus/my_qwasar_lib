"""
Description
Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

  Example 1:

  **Input:** arr = [1,2,3,4], difference = 1

  **Output:** 4

  **Explanation:** The longest arithmetic subsequence is [1,2,3,4].
  Example 2:

  **Input:** arr = [1,3,5,7], difference = 1

  **Output:** 1

  **Explanation:** The longest arithmetic subsequence is any single element.
  Example 3:

  **Input:** arr = [1,5,7,8,5,3,4,2,1], difference = -2

  **Output:** 4

  **Explanation:** The longest arithmetic subsequence is [7,5,3,1].
"""

"""
:type  param_1: {Integer[]}
"""
"""
:type  param_2: {Integer}
:rtype: integer
"""

def longest_arithmetic_subsequence_of_given_difference(arr, difference):
    dp = {}
    max_len = 0
    for elem in arr:
        if elem - difference in dp:
            dp[elem] = dp[elem - difference] + 1
        else:
            dp[elem] = 1
        max_len = max(max_len, dp[elem])
    return max_len