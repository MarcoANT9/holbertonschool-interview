#!/usr/bin/python3

"""
Rotate a 2D Matrix 90°
"""


def rotate_2d_matrix(matrix):
    """
    Function to rotate matrix
    """
    tmp_mat = matrix.copy()

    for i in range(len(matrix[0])):
        tmp = []
        for row in reversed(tmp_mat):
            tmp.append(row[i])
        matrix[i] = tmp
