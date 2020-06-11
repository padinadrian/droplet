#!/usr/bin/env python3

"""
Perform some conversion steps on map and tile data.

Does the following:
* Convert 'unsigned char' arrays to 'const unsigned char'.
* Add an offset of 0x80 to all values.
"""

import sys

def modify_data(filename):

    print("Converting file:", filename)

    with open(filename, "r") as file:
        lines = file.readlines()

    # Change char array to const char array
    for x in range(len(lines)):
        if lines[x].startswith("unsigned char"):
            lines[x] = lines[x].replace("unsigned char", "const unsigned char")

    # Add offset of 0x80 to all values
    lines = [line.replace("0x0", "0x8") for line in lines]
    lines = [line.replace("0x1", "0x9") for line in lines]
    lines = [line.replace("0x2", "0xA") for line in lines]
    lines = [line.replace("0x3", "0xB") for line in lines]
    lines = [line.replace("0x4", "0xC") for line in lines]
    lines = [line.replace("0x5", "0xD") for line in lines]
    lines = [line.replace("0x6", "0xE") for line in lines]
    lines = [line.replace("0x7", "0xF") for line in lines]

    with open(filename, "w") as file:
        for line in lines:
            file.write(line)

if __name__ == "__main__":
    for arg in sys.argv[1::]:
        modify_data(arg)
