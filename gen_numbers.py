#!/usr/bin/env python3
import sys
import random

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <number_of_integers>")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("Please enter a valid integer.")
        sys.exit(1)

    if n <= 0:
        print("Number of integers must be positive.")
        sys.exit(1)

    range_min, range_max = -10000, 10000
    possible_values = range_min, range_max
    total_unique = range_max - range_min + 1

    if n > total_unique:
        print(f"Cannot generate {n} unique integers in the range [{range_min}, {range_max}].")
        sys.exit(1)

    numbers = random.sample(range(range_min, range_max + 1), n)
    print(' '.join(str(num) for num in numbers))

if __name__ == "__main__":
    main()
