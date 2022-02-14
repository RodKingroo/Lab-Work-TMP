from Product import Product

class Buy(Product):
    def __init__(self, name="", price=0.0, weight=0.0, s=0):
        super().__init__(name,price,weight)
        if s>0: self.s=s
        else: self.s=0
    @property
    def sPrice(self):
        return self.s*self.price
    @property
    def sWeight(self):
        return self.s*self.weight