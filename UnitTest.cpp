#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixCalc/MatrixCalc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(MatrixConstructorTest)
	{
	public:
		TEST_METHOD(MatrixConstructorTest1)
		{
			MatrixCalc* testMatrix = new MatrixCalc(-1, -1);

			Assert::IsNull(testMatrix->matrix);
		}
		TEST_METHOD(MatrixConstructorTest2)
		{
			MatrixCalc* testMatrix = new MatrixCalc(3, 6);

			Assert::IsNotNull(testMatrix->matrix);
			Assert::AreEqual(testMatrix->n, 3);
			Assert::AreEqual(testMatrix->m, 6);
		}
		TEST_METHOD(MatrixConstructorTest3)
		{
			int** testCostMatrix = new int* [3]{ new int[6]{ 1, 2, 3, 4, 5, 6 },
													new int[6]{ 7, 8, 9, 10, 11, 12 },
													new int[6]{ 13, 14, 15, 16, 17, 18 }
			};
			MatrixCalc* testMatrix = new MatrixCalc(3, 6, testCostMatrix);

			for (int i=0; i<3; i++)
				for (int j=0; j<6; j++)
					Assert::AreEqual(testMatrix->matrix[i][j], testCostMatrix[i][j]);
			Assert::AreEqual(testMatrix->n, 3);
			Assert::AreEqual(testMatrix->m, 6);
		}
	};
}