from Buy import Buy

class Check(Buy):
    
    def printProductInfo(self):
        print("Товар: ", self.name)
        print("Цена: ", self.price)
        print("Вес: ", self.weight)
    
    def printBuyInfo(self):
        print("Товара куплено: ", self.s, " шт.")
        print("На сумму: ", self.sPrice, " руб.")
        print("Общий вес: ", self.sWeight, " кг.")