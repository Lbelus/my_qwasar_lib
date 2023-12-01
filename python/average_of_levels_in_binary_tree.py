"""
Description
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 00:

Input:
  3
 / \
9   20
    / \
   15  7

Output:
[3, 14.5, 11]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:

The range of node's value is in the range of 32-bit signed integer.
"""
"""
:type  param_1: {Treenode}
:rtype: float[]
"""

def height(node):
    if node is None:
        return 0
    else:
        left_height = height(node.left)
        right_height = height(node.right)
        return max(left_height, right_height) + 1

def traverseTree(node, level, average):
    if node is None:
        return   
    if level == 1:
        average.append(node.val)
    elif level > 1:
        traverseTree(node.left, level-1, average)
        traverseTree(node.right, level-1, average)

def average_of_levels_in_binary_tree(root):
    root_height = height(root)
    averages = []
    for index in range(1, root_height + 1):
        average = []
        traverseTree(root, index, average)
        tmp = sum(average) / len(average)
        averages.append(tmp)
    return averages