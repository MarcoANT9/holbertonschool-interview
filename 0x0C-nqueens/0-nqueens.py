#!/usr/bin/python3
"""
Main Module for the N Queens problem.
"""

import sys


def nQueens(N, r, queenList):
    """This program prints all the possible solutions for the NxN Queens problem,
    the conditions are:
        * You must place N queens in a NxN chessboard.
        * None of the Queens are place in a position in which they attack another Queen.
    """
    for i in range (N):
        flag = 0
        for j in queenList:
            if abs(i - j[1]) == abs(r - j[0]):
                flag = 1
                break
            if i == j[1]:
                flag = 1
                break
        if flag == 0:
            queenList.append([r, i])
            if r != N - 1:
                nQueens(N, r + 1, queenList)
            else:
                print(queenList)
            queenList.pop()



if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    
    if isinstance(sys.argv[1], int):
        print("N must be a number")
        exit(1)
    
    N = sys.argv[1]
    if (N < 4):
        print("N must be at least 4")
        exit(1)
    
    r = 0
    queenList = []
    nQueens(N, r, queenList)