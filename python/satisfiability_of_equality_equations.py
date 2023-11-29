
"""
Description
Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b". Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

Example 1:
**Input:** ["a==b","b!=a"]

**Output:** false

**Explanation:** If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second. There is no way to assign the variables to satisfy both equations.
Example 2:

**Input:** ["b==a","a==b"]

**Output:** true

**Explanation:** We could assign a = 1 and b = 1 to satisfy both equations.
Example 3:

**Input:** ["a==b","b==c","a==c"]

**Output:** true
Example 4:

**Input:** ["a==b","b!=c","c==a"]

**Output:** false
Example 5:

**Input:** ["c==c","b==d","x!=z"]

**Output:** true

"""


class UnionFind:
    def __init__(self):
        self.parent = {}
        self.rank = {}

    def find(self, item):
        if self.parent[item] != item:
            self.parent[item] = self.find(self.parent[item])
        return self.parent[item]

    def union(self, x, y):
        if x not in self.parent:
            self.parent[x] = x
            self.rank[x] = 0
        if y not in self.parent:
            self.parent[y] = y
            self.rank[y] = 0

        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            elif self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1

    def connected(self, x, y):
        if x not in self.parent or y not in self.parent:
            return False
        return self.find(x) == self.find(y)

"""
:type  param_1: {String[]}
:rtype: boolean
"""

def check_vars(equ, uf):
    if "==" in equ:
        vars = equ.split("==")
        return uf.connected(vars[0], vars[1])
    elif "!=" in equ:
        vars = equ.split("!=")
        if vars[0] == vars[1]:
            return False
        elif not uf.connected(vars[0], vars[1]):
            return True
        else:
            return False

def satisfiability_of_equality_equations(equs):
    uf = UnionFind()
    for equ in equs:
        if "==" in equ:
            vars = equ.split("==")
            uf.union(vars[0], vars[1])
    for equ in equs:
        if not check_vars(equ, uf):
            return False
    return True