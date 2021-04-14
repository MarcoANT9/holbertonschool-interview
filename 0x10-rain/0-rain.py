#!/usr/bin/python3


"""
This function calculates the amount of water that's retained
after it rains.

Walls - List of positive integers, each number represents a wall
of width 1 and walls[i] height.
"""


def rain(walls):
    """This returns the amount of stored water or 0 if the list is empty."""

    wallsLeng = len(walls)

    if (wallsLeng < 1):
        return 0

    totalRain = 0
    i = 0

    while (i < wallsLeng):
        if ((i - 1) < 0 or i + 1 == wallsLeng):
            i += 1
            continue
        if (walls[i] == 0):
            zeroes = 1
            prevWall = walls[i - 1]
            nextWall = walls[i + 1]

            if (nextWall == 0):
                while (nextWall == 0):
                    i += 1
                    if (i == wallsLeng):
                        zeroes += 1
                        break
                    nextWall = walls[i]
                    zeroes += 1
                zeroes -= 1

            heigh = min(prevWall, nextWall)
            totalRain += heigh * zeroes

        i += 1

    return (totalRain)
