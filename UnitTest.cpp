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


	TEST_CLASS(AddMatrixTest)
	{
	public:
		TEST_METHOD(AddMatrixTest1)
		{
			MatrixCalc* testMatrix1 = new MatrixCalc(-1, -1);
			MatrixCalc* testMatrix2 = new MatrixCalc(-1, -1);
			Assert::IsNull(testMatrix1->addMatrix(testMatrix1, testMatrix2));
		}
		TEST_METHOD(AddMatrixTest2)
		{
			int** testCostMatrix1 = new int* [3]{	new int[6]{ 1, 2, 3, 4, 5, 6 },
													new int[6]{ 7, 8, 9, 10, 11, 12 },
													new int[6]{ 13, 14, 15, 16, 17, 18 }
			};
			MatrixCalc* testMatrix1 = new MatrixCalc(3, 6, testCostMatrix1);

			int** testCostMatrix2 = new int* [3]{	new int[6]{ 1, 2, 3, 4, 5, 6 },
													new int[6]{ 7, 8, 9, 10, 11, 12 },
													new int[6]{ 13, 14, 15, 16, 17, 18 }
			};
			MatrixCalc* testMatrix2 = new MatrixCalc(3, 6, testCostMatrix2);

			int** costResult = new int* [3]{			new int[6]{ 2, 4, 6, 8, 10, 12 },
													new int[6]{ 14, 16, 18, 20, 22, 24 },
													new int[6]{ 26, 28, 30, 32, 34, 36 }
			};

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 6; j++)
					Assert::AreEqual(testMatrix1->addMatrix(testMatrix1, testMatrix2)->matrix[i][j], costResult[i][j]);
		}
		TEST_METHOD(AddMatrixTest3)
		{
			int** testCostMatrix1 = new int* [2]{ new int[6]{ 1, 2, 3, 4, 5, 6 },
													new int[6]{ 7, 8, 9, 10, 11, 12 },
			};
			MatrixCalc* testMatrix1 = new MatrixCalc(2, 6, testCostMatrix1);

			int** testCostMatrix2 = new int* [3]{ new int[6]{ 1, 2, 3, 4, 5, 6 },
													new int[6]{ 7, 8, 9, 10, 11, 12 },
													new int[6]{ 13, 14, 15, 16, 17, 18 }
			};
			MatrixCalc* testMatrix2 = new MatrixCalc(3, 6, testCostMatrix2);

			Assert::IsNull(testMatrix1->addMatrix(testMatrix1, testMatrix2));
		}
	};
}