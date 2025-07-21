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

    numbers = [random.randint(-1000, 1000) for _ in range(n)]
    print(' '.join(str(num) for num in numbers))

if __name__ == "__main__":
    main()
