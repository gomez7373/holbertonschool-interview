#!/usr/bin/python3
"""Module that parses HTTP access logs from stdin and prints metrics."""

import sys

total_size = 0
status_codes = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0,
}


def print_stats():
    """Print the collected statistics."""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


if __name__ == "__main__":
    line_count = 0
    try:
        for line in sys.stdin:
            line = line.strip()
            parts = line.split()
            if len(parts) >= 7:
                try:
                    status = parts[-2]
                    size = int(parts[-1])
                    total_size += size
                    if status in status_codes:
                        status_codes[status] += 1
                except Exception:
                    pass
            line_count += 1
            if line_count % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        pass
    finally:
        print_stats()
