#!/usr/bin/python3
"""
    This module determines if all boxes can be unlocked
"""


def canUnlockAll(boxes):
    """Determine if all boxes can be unlocked."""
    if not boxes or not isinstance(boxes, list):
        return False

    n = len(boxes)
    unlocked = [False] * n  # Track if each box is unlocked
    unlocked[0] = True  # First box is unlocked by default
    keys = [0]  # Start with the key for the first box

    while keys:
        current_key = keys.pop()

        for new_key in boxes[current_key]:
            if 0 <= new_key < n and not unlocked[new_key]:
                unlocked[new_key] = True
                keys.append(new_key)

    return all(unlocked)

