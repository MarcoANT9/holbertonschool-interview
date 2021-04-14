#!/usr/bin/python3


"""
This function calculates the amount of water that's retained
after it rains.

Walls - List of positive integers, each number represents a wall
of width 1 and walls[i] height.
"""


def rain(walls):
    """This returns the amount of stored water or 0 if the list is empty."""

    if len(walls) < 1:
        return 0

    rainWater = 0


    for element in range(len(walls)):
        first = walls[element]
        for wal in range(element):
            first = max(first, walls[wal])
        last = walls[element]
        for wal in range(element + 1, len(walls)):
            last = max(last, walls[wal])
        rainWater += (min(first, last) - walls[element])
    return rainWater
