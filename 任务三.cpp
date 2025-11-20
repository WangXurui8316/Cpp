#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double a;
    double b;
    double c;
public:
    void Init(double a1, double b1, double c1) {
        a = a1;
        b = b1;
        c = c1;
    }

    double getSideA() { return a; }
    double getSideB() { return b; }
    double getSideC() { return c; }

    void setSideA(double a1) { a = a1; }
    void setSideB(double b1) { b = b1; }
    void setSideC(double c1) { c = c1; }

    bool isTriangle() {
        return (a > 0 && b > 0 && c > 0) && (a + b > c) && (a + c > b) && (b + c > a);
    }

    double perimeter() {
        return isTriangle() ? (a + b + c) : 0;
    }

    double area() {
        if (!isTriangle()) return 0;
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    int typeTriangle() {
        if (!isTriangle()) return -1;

        double x = a, y = b, z = c;
        // C++98 手动交换（避免依赖C++11的swap优化）
        if (x > z) { double tmp = x; x = z; z = tmp; }
        if (y > z) { double tmp = y; y = z; z = tmp; }

        double x2 = x * x, y2 = y * y, z2 = z * z;
        if (fabs(x2 + y2 - z2) < 1e-6) return 0;
        return (x2 + y2 > z2) ? 1 : 2;
    }
};

int main() {
    Triangle tri;
    double a, b, c;
    double newA, newB, newC; // C++98 变量声明放在块开头
    int type;

    cout << "请输入三角形三边长度（空格分隔）：";
    cin >> a >> b >> c;

    tri.Init(a, b, c);
    if (!tri.isTriangle()) {
        cout << "输入的边长不能构成三角形！" << endl;
        return 0;
    }

    cout << "\n三角形基本信息：" << endl;
    cout << "边长：a=" << tri.getSideA() << ", b=" << tri.getSideB() << ", c=" << tri.getSideC() << endl;
    cout << "周长：" << tri.perimeter() << endl;
    cout << "面积：" << tri.area() << endl;

    type = tri.typeTriangle();
    cout << "三角形类型：";
    if (type == 0) cout << "直角三角形" << endl;
    else if (type == 1) cout << "锐角三角形" << endl;
    else if (type == 2) cout << "钝角三角形" << endl;

    cout << "\n请输入新的三边长度：";
    cin >> newA >> newB >> newC;
    tri.setSideA(newA);
    tri.setSideB(newB);
    tri.setSideC(newC);
    if (tri.isTriangle()) {
        cout << "修改后面积：" << tri.area() << endl;
        type = tri.typeTriangle();
        cout << "修改后类型：" << (type == 0 ? "直角" : (type == 1 ? "锐角" : "钝角")) << "三角形" << endl;
    } else {
        cout << "修改后的边长不能构成三角形！" << endl;
    }

    return 0;
}
