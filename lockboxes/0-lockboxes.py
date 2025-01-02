#!/usr/bin/python3
"""
    This program checks if a collection of boxes
    has the necessary keys to unlock every box.
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be unlocked.
    
    Args:
        boxes (list of list of int): A list where each element is a list of keys.
    
    Returns:
        bool: True if all boxes can be unlocked, False otherwise.
    """
    if not boxes:
        return True

    n = len(boxes)
    unlocked = [False] * n  # Keep track of unlocked boxes
    unlocked[0] = True  # The first box is unlocked by default
    keys = [0]  # Start with the key for the first box

    while keys:
        current_key = keys.pop()

        for new_key in boxes[current_key]:
            if 0 <= new_key < n and not unlocked[new_key]:
                unlocked[new_key] = True  # Mark the box as unlocked
                keys.append(new_key)  # Add the key to explore further

    # Check if all boxes are unlocked
    return all(unlocked)
