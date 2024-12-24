#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
using namespace std;

// Function to validate input
void validateInput(float x, float n) {
    if (x <= 0 || n <= 0) {
        throw invalid_argument("Both x and n must be greater than 0.");
    }
}

// Function to calculate result when x >= 6
float calculateWhenXGreaterOrEqual6(float x, float n) {
    float sum = 0, dif = 0;
    int i = 5, j = 1;

    // Вычисление суммы
    while (i < 7) {
        sum += x * i;  // Сумма произведений x и i
        i++;
    }

    // Вычисление разницы
    while (j < n) {
        dif += (x - j) / (x + 6);  // i фиксирован как 6 после завершения первого цикла
        j++;
    }

    // Возвращаем результат с округлением
    return roundf((sum - dif) * 100) / 100;  // Округляем результат до двух знаков
}



// Function to calculate result when x < 6
float calculateWhenXLess6(float x, float n) {
    float sum = 0;

    for (int i = 0; i < n; i++) {
        float dif = 0;  // Инициализация как суммы для текущего i
        for (int j = 0; j < n + 1; j++) {
            float denominator = (10 * x + 1);
            if (denominator == 0) {
                throw invalid_argument("Denominator cannot be zero.");
            }
            dif += (pow(j, 2) + pow(i, 2)) / denominator;  // Изменено: вместо умножения
        }
        sum += dif;  // Добавляем результат внутреннего цикла
    }

    return roundf(sum * 100000) / 100000;  // Округление результата
}



// Main function
int main() {
    float x, n;

    try {
        cout << "Input x and n (x, n > 0): ";
        cin >> x >> n;

        // Validate the input
        validateInput(x, n);

        // Calculate and display the result
        if (x >= 6) {
            float result = calculateWhenXGreaterOrEqual6(x, n);
            cout << "Result: " << result << endl;
        } else {
            float result = calculateWhenXLess6(x, n);
            cout << "Result: " << result << endl;
        }

    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}
