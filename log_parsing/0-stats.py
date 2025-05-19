#!/usr/bin/python3
"""
Log parsing script that reads stdin line by line and computes metrics:
- Total file size
- Count of each status code
"""

import sys

# Track total file size and counts of specific status codes
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
                pass  # If size conversion fails or other error, skip this line

        line_count += 1
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    pass

finally:
    print_stats()

