import unittest
from MyBitString6 import MyBitString

class MyBitStringTestCase(unittest.TestCase):

	def test_m2str(self):
		self.o3.mas_from_str('10101011')
		self.assertEqual(self.o3.mas,'10101011')
		self.o3.mas_from_str('')
		self.assertEqual(self.o3.mas,'')
		#self.o3.mas_from_str('01010')
		#self.assertEqual(self.o3.mas,'123')
		self.assertRaises(ValueError, self.o3.mas_from_str, '123')

	def setUp(self):
		self.o1=MyBitString('10101011')
		self.o2=MyBitString('00101011')
		self.o3=MyBitString()

	def test_finp(self):
		self.assertRaises(FileNotFoundError, self.o3.f_inp, '123')

	def test_foutp(self):
		self.assertRaises(FileNotFoundError, self.o3.f_outp, 'c:\windows\123')

	def test_and(self):
		self.assertEqual(str(self.o1&self.o2),'101011')

	def test_get_bit(self):
		#self.assertEqual(self.o1[1],'1',"First")
		#self.assertEqual(self.o1[2],'0',"Second")
		self.assertRaises(IndexError, self.o1.__getitem__,10)

	def test_set_bit(self):
		self.assertRaises(ValueError, self.o1.__setitem__,1,2)
		self.assertRaises(IndexError, self.o1.__setitem__,10,2)
		#self.o1[1]=0
		#self.assertEqual(str(self.o1),'10101001')

if __name__ == '__main__':
	unittest.main()