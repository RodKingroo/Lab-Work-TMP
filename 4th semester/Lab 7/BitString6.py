import sys #for command line arguments proceed
from MyBitString6 import MyBitString

bs1=MyBitString()
bs2=MyBitString()
if len(sys.argv) <3:
    bs1.inp()
    bs2.inp()
    print('a & b = ', bs1& bs2)
    d=bs1&bs2
    #print(d[2])
    #d[7]=3
    print(d)
else:
    bs1.f_inp(sys.argv[1]) #file input
    bs2.f_inp(sys.argv[2])
    print('a = ', bs1) 
    print('b = ', bs2)
    bs3=bs1 & bs2 #conjunction
    print('a & b = ', bs3)
    bs3.f_outp(sys.argv[3]) #file output