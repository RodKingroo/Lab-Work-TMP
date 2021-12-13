class MyBitString:

	def mas_from_string(self, st):

		self.mas=""

		for b in st:

			if b!='0' and b!='1':
				
				print('Incorrect input')
				exit()

			else:

				self.mas+=(b)

	def bitInput(self):

		m=input('Введите bit string : ')
		self.mas_from_string(m)


	def filebitInput(self,filename):

		try:
			file=open(filename, 'r')
		
		except:
			print("Невозможно открыть файл")
			exit()
		
		m=file.readline()
		self.mas_from_string(m)
		file.close()

	def output(self):

		print(self.mas)

	def fileOutput(self, filename):
		file=open(filename,'w')
		file.write(self.mas)
		file.close()


	def conjaction(self, b):
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
			
		c=c[c.find("1"):]
		return MyBitString(c)

	def __init__(self, init_str=None):
		if init_str!=None:
			self.mas_from_string(init_str)

	def __and__(self, b):
		return self.conjaction(b)

	def __getitem__(self, i):
		if (i<0) or (i>=len(self.mas)):
			return -1
		else:
			return self.mas[i]

	def __setitem__(self, i, x):
		if (i>=0) and (i<len(self.mas)):
			self.mas=self.mas[:i]+str(x)+self.mas[i+1:]

	def __str__(self):
		return self.mas