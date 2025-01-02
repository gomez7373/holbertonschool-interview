#!/usr/bin/python3
"""
    This program checks if a collection of boxes
    has the necessary keys to unlock every box.
"""


def canUnlockAll(boxes):
    """ Determines if all the boxes can be unlocked """
    if boxes:
        keys = [0]
        keysNeeded = [i[0] for i in enumerate(boxes)]

        # will Collect the keys from all the un-lockable boxes that beginnings with 0
        collectKeys(boxes, keys)

        # Will return true or false if keys present match key needed or not 
        return sorted(keys) == keysNeeded
    else:
        return True


def collectKeys(boxes, keys, key=0):
    # Will recursively collect all the unique keys from all the boxes 
    for newKey in boxes[key]:
        if newKey not in keys and newKey < len(boxes):
            keys.append(newKey)
            collectKeys(boxes, keys, newKey)
