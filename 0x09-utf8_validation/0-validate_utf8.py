#!/usr/bin/python3
"""
This program checks if a given data set represents a UTF-8 encoding.
"""


def validUTF8(data):
    """This function takes a data set (just a list) and determines
    if it represents a UTF-8 encoding.

    Input: Data - A list of integers.

    Output: Bool
                -> True if the data set represents a UTF-8 Encoding
                -> False if the data set doesn't represent a UTF-8 encoding.
    """
    utf = 0
    for element in data:
        element = format(element, "#010b")[-8:]
        if utf != 0:
            utf -= 1
            if not element.startswith("10"):
                return False
        elif element[0] == "1":
            if utf == 1 or utf > 4:
                return false
            utf = len(element.split("0")[0])
            utf -= 1

    if utf == 0:
        return True
    return False
