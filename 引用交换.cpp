#include <iostream>

using namespace std;

// 引用交换函数
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// 重载交换函数（使用指针）
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    cout << "引用交换" << endl;
    
    int a, b;
    cout << "请输入两个整数: ";
    cin >> a >> b;
    
    cout << "交换前: a = " << a << ", b = " << b << endl;
    
    // 使用引用交换
    int a1 = a, b1 = b;
    swap(a1, b1);
    cout << "使用引用交换后: a = " << a1 << ", b = " << b1 << endl;
    
    // 使用指针交换（重载版本）
    int a2 = a, b2 = b;
    swap(&a2, &b2);
    cout << "使用指针交换后: a = " << a2 << ", b = " << b2 << endl;
    
    return 0;
}
