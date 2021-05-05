#!/usr/bin/python3
"""This program queries the Reddit API, parses the title of all hot articles
and prints the sorted count of given keywords (case-insensitive, delimited by
spaces)"""

from requests import get


API = "https://www.reddit.com/"
headers = {'user-agent': 'MarcoAnt9'}


def count_words(subreddit, keywords, after="", word_dict={}):
    """This is the recursive function that gets the keywords"""

    if not word_dict:
        for word in keywords:
            word_dict[word] = 0

    if after is None:
        keywords = [[key, value] for key, value in word_dict.items()]
        keywords = sorted(keywords, key=lambda x: (-x[1], x[0]))
        for word in keywords:
            if word[1]:
                print("{}: {}".format(word[0].lower(), word[1]))
        return None

    url = API + "r/{}/hot/.json".format(subreddit)
    params = {'limit': 100, 'after': after}
    r = get(url, headers=headers, params=params, allow_redirects=False)

    if r.status_code != 200:
        return None

    try:
        jSon = r.json()

    except Exception:
        return None

    try:
        data = jSon.get("data")
        after = data.get("after")
        children = data.get("children")

        for child in children:
            dato = child.get("data")
            title = dato.get("title")
            lower = [s.lower() for s in title.split(' ')]
            for word in keywords:
                word_dict[word] += lower.count(word.lower())

    except Exception:
        return None
    count_words(subreddit, keywords, after, word_dict)
