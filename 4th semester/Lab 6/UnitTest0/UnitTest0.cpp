#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab 6\BitString.h"
#include "..\Lab 6\BitString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0
{
	TEST_CLASS(UnitTest0)
	{
	public:
		
		TEST_METHOD(DefautConstuctTest)
		{
			BitString o1;
			Assert::IsTrue(o1.getLen() == 0);
			Assert::IsTrue(o1.getMas() == 0);
		}
		TEST_METHOD(InitConstuctTest)
		{
			string str("10001");
			BitString o1(str);
			Assert::IsTrue(o1.getLen() == 5);
			for (int i = 0; i < o1.getLen(); i++) Assert::IsTrue(o1.getMas()[i] == str[i]);

		//**Некорректная обработка строки 0010001**//
			//BitString o2("0010001");
			//Assert::IsTrue(o2.getLen() == 5,L"incorrect");
			//for (int i = 0; i < o2.getLen(); i++) Assert::IsTrue(o2.getMas()[i] == str[i]);
		}

		TEST_METHOD(CopyConstuctTest)
		{
			BitString o1("10001");
			BitString o2=o1;
			Assert::IsTrue(o1.getLen() == o2.getLen());
			for (int i = 0; i < o1.getLen(); i++) Assert::IsTrue(o1.getMas()[i]==o2.getMas()[i]);

			BitString o3("0010001");
			BitString o4 = o3;
			Assert::IsTrue(o1.getLen() == o2.getLen());
			for (int i = 0; i < o3.getLen(); i++) Assert::IsTrue(o3.getMas()[i] == o4.getMas()[i]);
		}

		TEST_METHOD(file_inpTest)
		{
			BitString o1;
			try {
				o1.FileInput("x.txt");
			}
			catch (exception e) {
				Assert::AreEqual(e.what(), "Can't open file");
			}
		}

		TEST_METHOD(file_outTest)
		{
			BitString o1;
			try {
				o1.FileOutput("d:\\project\\x.txt");
			}
			catch (exception e) {
				Assert::AreEqual(e.what(), "Can't open file");
			}
		}

		TEST_METHOD(operatorEQTest)
		{
			BitString o1("10001");
			BitString o2("100");
			o2 = o1;
			Assert::IsTrue(o1.getLen() == o2.getLen());
			for (int i = 0; i < o1.getLen(); i++) Assert::IsTrue(o1.getMas()[i] == o2.getMas()[i]);
		}

		TEST_METHOD(operatorAccessTest)
		{
			string str("10001");
			BitString o1("10000");
			char t = o1[4];
			Assert::IsTrue(t == '1');
			o1[0] = '1';
			for (int i = 0; i < o1.getLen(); i++) Assert::IsTrue(o1.getMas()[i] == str[i]);
			try {
				o1[10] = '0';
			}
			catch (exception e) {
				Assert::IsTrue(e.what(), L"Index out of range");
			}
		}

		TEST_METHOD(operatorAndTest)
		{
			string str("101");
			BitString o1("10101");
			BitString o2("1101");
			BitString o3 = o1 & o2;
			for (int i = 0; i < o3.getLen(); i++) Assert::IsTrue(o3.getMas()[i] == str[i]);

		}


	};
}
