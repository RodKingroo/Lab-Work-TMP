class MyBitString:
	def mas_from_str(self, st):
		'''get internal variavle from external string'''
		self.mas=""
		for b in st: 
			if b!='0' and b!='1':
				raise ValueError("Incorrect symbol found")
			else:
				self.mas+=(b)
				
	def inp(self): 
		'''manual input'''
		m=input('Input bit string : ')
		self.mas_from_str(m)
	
	def f_inp(self,filename):
		'''file input'''
		try:
			file=open(filename, 'r')
		except:
			raise FileNotFoundError("Unable to open file: "+filename)
		m=file.readline()
		self.mas_from_str(m)
		file.close()

	def outp(self):
		'''console output'''
		print(self.mas)
		
	def f_outp(self, filename):
		'''file output'''
		try:
			res=open(filename,'w')
		except:
			raise FileNotFoundError("Unable to open file")
		res.write(self.mas)
		res.close()		   

	def conj(self, b):
		'''conjunction'''
		c=''
		mi=self.mas
		ma=b.mas
		if len(ma)<len(mi):
			mi=ma
			ma=self.mas
		sl=len(ma)-len(mi)
		suf='0'*sl
		mi=suf+mi
		i=0
		while (i<len(ma)): 
			if mi[i]=='1' and ma[i]=='1':
				c+='1'
			else:
				c+='0'
			i+=1
		c=c[c.find('1'):]
		return MyBitString(c)
		
	def __init__(self, init_str=None):
		'''constructor'''
		if init_str!=None:
			self.mas_from_str(init_str)

	def __and__(self, b): 
		'''overloading &'''
		return self.conj(b)
	
	def __str__(self): 
		'''overloading str'''
		return self.mas
		
	def __getitem__(self, i):
		'''overloading []'''
		if i>=0 and i<len(self.mas):
			return self.mas[i]
		else:
			raise IndexError("Index out of bounds")
	
	def __setitem__(self, i, x):
		'''overloading []'''
		if i>=0 and i<len(self.mas):
			if (str(x)=='0' or str(x)=='1'):
				i=i-len(self.mas)-1
				self.mas=self.mas[:i]+str(x)+self.mas[i+1:]
			else:
				raise ValueError("Incorrect symbol found")
		else:
			raise IndexError("Index out of bounds")