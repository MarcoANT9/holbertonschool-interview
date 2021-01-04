#!/usr/bin/python3
"""
Main file for the operation counting.
"""

def minOperations(n):
    """This program uses the module operation to determine when to copy the
    string, if the module between the number n and the lenght of the current
    output will be copied and pasted, if the module is not zero it will only
    paste."""

    count = 0
    if (n < 2):
        return count

    string = "h"
    while (len(string) < n):
        if (n % len(string) == 0):
            copy = string
            count += 1
        string = string + copy
        count += 1

    return count

if __name__ == "__main__":
    main()
