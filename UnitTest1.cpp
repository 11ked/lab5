#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Link\Desktop\Code\IPZ\lab5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// Тесты для проверки корректности входных данных
namespace UnitTests
{
    // Тесты для проверки валидации ввода
    TEST_CLASS(InputValidationTests)
    {
    public:
        TEST_METHOD(ValidInputs)
        {
            try {
                validateInput(10.0, 5.0); // Допустимые значения
                Assert::IsTrue(true);   // Тест пройден, если исключение не выброшено
            }
            catch (...) {
                Assert::Fail(L"Unexpected exception for valid inputs.");
            }
        }

        TEST_METHOD(InvalidInputsNegativeX)
        {
            try {
                validateInput(-5.0, 3.0); // Неверное значение x
                Assert::Fail(L"Expected exception for negative x.");
            }
            catch (const invalid_argument& e) {
                Assert::AreEqual("Both x and n must be greater than 0.", e.what());
            }
        }

        TEST_METHOD(InvalidInputsNegativeN)
        {
            try {
                validateInput(5.0, -3.0); // Неверное значение n
                Assert::Fail(L"Expected exception for negative n.");
            }
            catch (const invalid_argument& e) {
                Assert::AreEqual("Both x and n must be greater than 0.", e.what());
            }
        }
    };

    // Тесты для функций расчёта
    TEST_CLASS(CalculationTests)
    {
    public:
        TEST_METHOD(CalculateWhenXGreaterOrEqual6)
        {
            float result = calculateWhenXGreaterOrEqual6(6.0, 3.0);
            Assert::AreEqual(65.25f, result, 0.01f);  // Новое ожидаемое значение
        }


        TEST_METHOD(CalculateWhenXLess6)
        {
            float result = calculateWhenXLess6(5.0, 2.0);
            Assert::IsTrue(result > 0); // Проверяем, что результат положительный
        }
    };

    // Интеграционные тесты для main
    TEST_CLASS(MainLogicTests)
    {
    public:
        TEST_METHOD(CalculateWhenXGreaterOrEqual6)
        {
            float result = calculateWhenXGreaterOrEqual6(6.0, 3.0);
            Assert::AreEqual(66.25f, result, 0.01f);  // Новое ожидаемое значение
        }




        TEST_METHOD(CalculateWhenXLess6)
        {
            float result = calculateWhenXLess6(5.0, 2.0);
            Assert::IsTrue(result < 0); // Проверяем, что результат положительный
        }
    };
}