#include "pch.h"
#include "CppUnitTest.h"
#include "../71 re/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71rek
{
	TEST_CLASS(UnitTest71rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2;
			int colCount = 2;

			int** d = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				d[i] = new int[colCount];
			d[0][0] = 2;
			d[1][0] = -1;
			d[0][1] = -2;
			d[1][1] = 0;
			int S = 0;
			int k = 0;
			Calc(d, rowCount, colCount, S, k, 0, 0);
			for (int i = 0; i < rowCount; i++)
				delete[] d[i];
			delete[] d;

			Assert::AreEqual(k, 1);
			Assert::AreEqual(S, 2);

		}
	};
}
