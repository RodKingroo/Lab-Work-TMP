from BitString import BitString

import sys

a = BitString()
b = BitString()

# print("a: ", end = ' ')
# a.output()
# print("b: ", end = ' ')
# b.output()
# print("a & b: ", end = ' ')
# c.output()

if len(sys.argv)<2:
    a.bitInput()
    b.bitInput()

else: 
    a.filebitInput(sys.argv[1])
    b.filebitInput(sys.argv[2])

c = a.conjaction(b)

print("Результат: ", end = ' ') 
c.output()

if len(sys.argv) == 4:
    c.fileOutput(sys.argv[3])