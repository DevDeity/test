#include <iostream>
#include <locale>

using namespace std;

struct MathQuestion {
    float value1;
    float value2;
    char sign;

    MathQuestion(float _value1, char _sign, float _value2) {
        value1 = _value1;
        sign = _sign;
        value2 = _value2;
    }

    float AddNumber() {
        return value1 + value2;
    }

    float MinusNumber() {
        return value1 - value2;
    }

    float Division() {
        return value1 / value2;
    }

    float Multiplication() {
        return value1 * value2;
    }

    float Result() {
        switch (sign) {
        case '+':
            return AddNumber();
        case '-':
            return MinusNumber();
        case '/':
            return Division();
        case '*':
            return Multiplication();
        default:
            break;
        }
        return 0;
    }
};

int main() {
    setlocale(0, "Russian");

    float value1, value2, value3;
    char operand, operand2;

    cout << "Введите выражение для расчета: <value1><signSymbol1><value2><signSymbol2><value3>\n";
    cin >> value1 >> operand >> value2 >> operand2 >> value3;

    MathQuestion pCalculator1{ value1 , operand, value2 };
    MathQuestion pCalculator2{ pCalculator1.Result(), operand2, value3 };

    float result = pCalculator2.Result();

    cout << "Подсчет успешен: " << value1 << " " << operand << " " << value2 << " " << operand2 << " " << value3 << " = " << result << endl;

    return 0;
}
