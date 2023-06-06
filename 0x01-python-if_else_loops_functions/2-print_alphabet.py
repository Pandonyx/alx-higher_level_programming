#!/usr/bin/python3
for i in range(ord('a'), ord('z')+1):
    if chr(i) not in ('q', 'e'):
        print(chr(i), end='')
print()  # To print a new line after the loop ends
