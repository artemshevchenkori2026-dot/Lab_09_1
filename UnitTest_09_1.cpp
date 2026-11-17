#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include "../Lab_09_1/var.h"   // вкажи правильний шлях до папки з основним проектом
#include "../Lab_09_1/var.cpp"
#include "../Lab_09_1/dod.h"
#include "../Lab_09_1/dod.cpp"
#include "../Lab_09_1/sum.h"
#include "../Lab_09_1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nsVar;
using namespace nsSum;

namespace UnitTestLab91
{
    TEST_CLASS(UnitTestLab91)
    {
    public:
        TEST_METHOD(TestSumArctg)
        {
            // Задаємо вхідні дані через глобальні змінні
            x = 0.5;
            e = 0.00001;

            // Викликаємо функцію обчислення суми ряду
            sum();

            // Очікуване значення через стандартну функцію atan(0.5) ≈ 0.4636476
            double expected = atan(0.5);

            // Перевіряємо, що обчислена сума s збігається з atan(x) з точністю e
            Assert::AreEqual(expected, s, e);
        }

        TEST_METHOD(TestDodRecurrence)
        {
            // Перевірка першого кроку рекурентності для x = 0.5, n = 1
            // a0 = 0.5; a1 має дорівнювати -0.5^3 / 3 = -0.125 / 3 = -0.0416667
            x = 0.5;
            n = 1;
            a = x;

            nsDod::dod();

            double expected = -pow(0.5, 3) / 3.0;
            Assert::AreEqual(expected, a, 1e-7);
        }
    };
}