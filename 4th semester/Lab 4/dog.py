from PyInt import IPet

class Dog(IPet):
    
    def setName(self, name):
    
        self.name = name

    def getName(self):

        return self.name

    def play(self):
        
        print(self.name, "любит много плавать")