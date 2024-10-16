#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestS0)
        {
            int K = 1, N = 10;
            double expected = 0;
            for (int i = K; i <= N; i++)
            {
                expected += ((1.0 + (static_cast<double>(i) / N)) / (i * i * 1.0));
            }
            double result = S0(K, N);
            Assert::AreEqual(expected, result, 0.00001);
        }
	};
}
