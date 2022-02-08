class BitString:
    def mas_from_string(self, st):
        self.mas =""
        for b in st:
        
            if b!='0' and b!='1':
        
                print('Некорректный ввод!')
                exit()
            else:
                self.mas+=b



    def bitInput(self):
  
        m = input('Введите bit string:')
        self.mas_from_string(m)

        
    def filebitInput(self, filename):
        try:
            file = open(filename, 'r')
        except:
           
            print("Невозможно открыть файл")
            exit()

        m=file.readline()
        self.mas_from_string(m)
        file.close
    
    def output(self):
        print(self.mas)
    
    def fileOutput(self, filename):
        try:
            file = open(filename, 'w')
        except:
            print("Невозможно открыть файл")
            exit()
        file.write(self.mas)
        file.close()

    def conjaction(self, b):

        result = ''
        la = len(self.mas)
        lb = len(b.mas)
        
        lm = la
        if la>lb:
            lm = lb
                    
        i=0
        while (i<lm):

            
            if self.mas[la-i-1]== '1' and b.mas[lb-i-1]== '1':
                result+='1'
            else:
                result+='0'

            i+=1
        result = result[::-1]

        return BitString(result)

    def __init__(self, init_str = None):
        
        if init_str != None:
        
            self.mas_from_string(init_str)
        

