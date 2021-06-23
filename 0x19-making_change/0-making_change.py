#!/usr/bin/python3
"""This program is used to determine the minimum ammount of change
it would be needed to return a certain ammount of value."""


def makeChange(coins, total):

    if (total <= 0):
        return (0)

    totalCoins = 0
    mod = -1

    coins.sort(reverse=True)

    for coin in coins:
        tmp = total // coin

        if (tmp == 0):
            continue
        totalCoins += tmp
        total = total % coin  # Residuo de la div. de arriba

    if (total != 0):
        return (-1)
    return (totalCoins)
