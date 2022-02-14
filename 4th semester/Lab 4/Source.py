from dog import Dog
from cat import Cat
from rabbit import Rabbit

choise = int(input("Какое домашнее животное вы хотели бы завести?\n1. Собака\n2. Кошка\n3. Кролик\n(выберете 1-3): "))

if choise==1: p=Dog()
elif choise==2: p=Cat()
elif choise==3: p=Rabbit()
else: print("Ошибка ввода")

name=input("Придумайте имя своему питомцу: ")
p.setName(name)
p.play()