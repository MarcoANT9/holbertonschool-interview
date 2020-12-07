#!/usr/bin/python3

def checkKeys(key, boxes, open_boxes):
    """This is the function to use recursion."""
    for element in boxes[key]:
    
        if (element < len(boxes) and open_boxes[element] == False and boxes[key] != []):
            open_boxes[element] = True
            open_boxes = checkKeys(element, boxes, open_boxes)
        else:
            break

    return open_boxes


def canUnlockAll(boxes):
    """This function returns True if all the boxes can be unlocked and False if they cannon."""
    lis_en = len(boxes)

    if boxes == None or lis_en == 0:
        return False

    open_boxes = [False] * lis_en
    open_boxes[0] = True

    for key in boxes[0]:
        if (key < lis_en and open_boxes[key] == False):
            open_boxes[key] = True
            open_boxes = checkKeys(key, boxes, open_boxes)
        else:
            continue

    if (False in open_boxes):
        return (False)
    return (True)
