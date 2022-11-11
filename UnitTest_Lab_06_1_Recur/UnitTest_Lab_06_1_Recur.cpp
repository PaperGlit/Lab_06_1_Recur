#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_1_Recur/Lab_06_1_Recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Test(int* a, int* c, const int size, int i, int n, int s)
{
	if (i < size)
	{
		if (a[i] > 0 || a[i] % 2 != 0)
		{
			n++;
			s += c[i];
			a[i] = 0;
		}
		Assert::AreEqual(a[i], c[i]);
		Test(a, c, size, i + 1, n, s);
	}
	else
	{
		Assert::AreEqual(n, Num(c, size, 0, 0));
		Assert::AreEqual(s, Sum(c, size, 0, 0));
	}
}

namespace UnitTestLab061Recur
{
	TEST_CLASS(UnitTestLab061Recur)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			const int n = 27;
			int c[n], Low = -35, High = 25;

			Create(c, n, Low, High, 0);

			int* a = Zero(c, n, 0);

			Test(a, c, n, 0, 0, 0);
		}
	};
}