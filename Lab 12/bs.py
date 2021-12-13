from MyBitString import MyBitString
import sys, os

try:
    choose_user = str(input("What input method do you want to use?[console/file]: "))
    if choose_user == "console":
        string_1 = MyBitString()
        string_1.input_str()
        string_2 = MyBitString(str(input("Write bit string 2: ")))
        string_3 = string_1 & string_2
        print("Result of conjunction:", end=" ")
        print(string_3)
    if choose_user == "file":
        string_f1 = MyBitString()
        string_f1.filebitInput("input_file1.txt")
        string_f2 = MyBitString()
        string_f2.filebitInput("input_file2.txt")
        string_f_res = string_f1.conjaction(string_f2)
        string_f_res.fileOutput("output_file.txt")
except Exception as error:
    print(error)

os.system("pause")
