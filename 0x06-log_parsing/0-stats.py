#!/usr/bin/python3
"""This program reads the STDout line by line and computes responses
and file sizes"""

import sys


values = {"Size": 0, "Codes": {"200": 0, "301": 0, "400": 0, "401": 0,
                               "403": 0, "404": 0, "405": 0, "500": 0}}


def printLines():
    """Function to print fileSize and status codes"""

    print("File size: {}".format(values["Size"]))

    for code, count in sorted(values["Codes"].items()):
        if count != 0:
            print("{}: {}".format(code, count))

if __name__ == "__main__":

    try:
        lines = 1
        for line in sys.stdin:
            info = line.split(" ")

            try:
                size = int(info[-1])
                code = info[-2]

                if code in values["Codes"]:
                    values["Codes"][code] += 1

                values["Size"] += size

            except:
                pass

            if lines % 10 == 0:
                printLines()

            lines += 1

    except KeyboardInterrupt:
        printLines()
        raise

    printLines()
