#!/usr/bin/python3
"""
This module returns a list of integers representing the pascal´s triangle
of n.
"""


def pascal_triangle(n):
    """
    This function creates an array of elements representing the Pascal's
    triangle.
    """

    if n <= 0:
        empty = []
        return (empty)

    macro = [[1]]
    while len(macro) < n:
        vector = macro[-1]
        vector_cpy = [1]
        j = 0
        while j < (len(vector) - 1):
            vector_cpy.append(vector[j] + vector[j + 1])
            j += 1
        vector_cpy.append(1)
        macro.append(vector_cpy)

    return macro