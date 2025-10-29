#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 内联函数：计算平方
inline double square(double x) {
    return x * x;
}

// 带默认参数的函数：计算乘幂
double power(double base, int exponent = 2) {
    return pow(base, exponent);
}

// 重载函数1：double类型的四则运算
double calc(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                cout << "Error: divide by zero" << endl;
                return 0;
            }
            return a / b;
        default:
            cout << "Error: invalid operator" << endl;
            return 0;
    }
}

// 重载函数2：int类型的四则运算
double calc(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                cout << "Error: divide by zero" << endl;
                return 0;
            }
            return static_cast<double>(a) / b;
        default:
            cout << "Error: invalid operator" << endl;
            return 0;
    }
}

int main() {
    cout << "多功能计算器" << endl;
    
    double num1, num2;
    char op;
    
    cout << "请输入两个操作数和一个运算符(例如: 5 3 +): ";
    cin >> num1 >> num2 >> op;
    
    // 调用各个函数
    double sq_result = square(num1);
    double power_result = power(num1);
    double calc_double_result = calc(num1, num2, op);
    double calc_int_result = calc(static_cast<int>(num1), static_cast<int>(num2), op);
    
    // 输出结果
    cout << fixed << setprecision(2);
    cout << num1 << " 的平方: " << sq_result << endl;
    cout << num1 << " 的平方(使用power函数): " << power_result << endl;
    cout << num1 << " " << op << " " << num2 << " = " << calc_double_result << " (double版本)" << endl;
    cout << static_cast<int>(num1) << " " << op << " " << static_cast<int>(num2) 
         << " = " << calc_int_result << " (int版本)" << endl;
    
    return 0;
}
