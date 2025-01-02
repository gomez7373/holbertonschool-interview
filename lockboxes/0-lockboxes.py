#!/usr/bin/python3
"""
    This program checks if a collection of boxes
    has the necessary keys to unlock every box.
"""


def can_unlock_all(boxes):
    """
    Determines if all the boxes can be unlocked.
    
    Args:
        boxes (list of list of int): A list where each element is a list of keys.
    
    Returns:
        bool: True if all boxes can be unlocked, False otherwise.
    """
    if not boxes:
        return True

    keys = [0]
    keys_needed = list(range(len(boxes)))

    # Collect keys from all unlockable boxes starting with box 0
    collect_keys(boxes, keys)

    # Check if all required keys are collected
    return sorted(keys) == keys_needed


def collect_keys(boxes, keys, current_key=0):
    """
    Recursively collect all unique keys from the boxes.
    
    Args:
        boxes (list of list of int): A list where each element is a list of keys.
        keys (list of int): List of collected keys.
        current_key (int): Current box being unlocked.
    """
    for new_key in boxes[current_key]:
        if new_key not in keys and new_key < len(boxes):
            keys.append(new_key)
            collect_keys(boxes, keys, new_key)
