import os


class MyBitString():
    def __init__(self, init_str=None):
        if init_str is not None:
            self.mas_from_string(init_str)
        else:
            self.mas = ""

    def __and__(self, string):
        return self.conjanction(string)

    def __getitem__(self, i):
        if (i >= 0) and (i < len(self.mas)):
            return self.mas[i]
        raise IndexError("Index out of range")

    def __setitem__(self, i, value):
        if (i >= 0) and (i < len(self.mas)):
            if (str(value) == "0") and (str(value) == "1"):
                self.mas = self.mas[:i] + str(value) + self.mas[i+1:]
            raise ValueError("Invalid value")
        raise IndexError("Index out of range")

    def mas_from_string(self, string):
        self.mas = ""
        for elem in string:
            if elem != '1' and elem != '0':
                raise ValueError("Incorrect input string")
            else:
                self.mas += elem

    def input_str(self):
        temp = input("Write bit string: ")
        self.mas_from_string(temp)

    def conjanction(self, second_string):
        c = ""
        ma = len(self.mas)
        mb = len(second_string.mas)
        ml = ma
        if ml > mb:
            ml = mb
        for i in range(ml):
            if self.mas[ma - 1 - i] == '1' and second_string.mas[mb - 1 - i] == '1':
                c += '1'
            else:
                c += '0'
        c_r = c[::-1]
        if c_r.find("1") != -1:
            c_r = c_r[c_r.find("1"):]
        else:
            c_r = "0"
        return MyBitString(c_r)

    def show_result(self):
        print(self.mas)

    def FileInput(self, filename):
        try:
            file = open(filename, "r")
        except FileNotFoundError:
            raise FileNotFoundError("File" + format(filename) + " not found")
        temp = file.readline()
        self.mas_from_string(temp)
        print(f"String was obtained from file({self.mas})")
        file.close()

    def FileOutput(self, filename):
        try:
            file = open(filename, "w")
        except FileNotFoundError:
            raise FileNotFoundError("File" + format(filename) + " not found")
        file.write("Result of conjunction: {}".format(self.mas))
        print("Result was written to a file:".format(filename))
        file.close()

    def __str__(self):
        return self.mas

