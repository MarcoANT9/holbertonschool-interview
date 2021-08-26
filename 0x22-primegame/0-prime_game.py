#!/usr/bin/python3
"""This module is used to determine the winner of the 'Prime Game'"""


def isWinner(x, nums):
    """Defines which player is the winner on the prime game."""

    players = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]
    addPrime(max(nums), primes)

    for round in range(x):
        total = sum((i != 0 and i <= nums[round])
                    for i in primes[:nums[round] + 1])
        if (total % 2):
            winner = "Maria"
        else:
            winner = "Ben"
        if winner:
            players[winner] += 1

    if players["Maria"] > players["Ben"]:
        return "Maria"
    if players["Maria"] < players["Ben"]:
        return "Ben"
    else:
        return None


def addPrime(n, primes):
    """Add all the primes"""
    lastPrime = primes[-1]
    if n > lastPrime:
        for i in range(lastPrime + 1, n + 1):
            if isPrime(i):
                primes.append(i)
            else:
                primes.append(0)


def isPrime(n):
    """Determines if a number is prime"""
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True
