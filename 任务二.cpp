#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year;
    int month;
    int date;
    string getWeekdayStr(); // C++98 需提前声明私有函数
public:
    void Init(int y, int m, int d) {
        year = y;
        month = m;
        date = d;
    }

    int getYear() { return year; }
    int getMonth() { return month; }
    int getDate() { return date; }

    void setYear(int y) { year = y; }
    void setMonth(int m) { month = m; }
    void setDate(int d) { date = d; }

    void display() {
        cout << year << "年" << month << "月" << date << "日，" << getWeekdayStr() << endl;
    }

    int calWeekday() {
        int y = year;
        int m = month;
        if (m <= 2) {
            y--;
            m += 12;
        }
        int d = date;
        return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    }
};

// C++98 私有成员函数需在类外定义（类内仅声明）
string Date::getWeekdayStr() {
    string weekdays[7] = { "星期日", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六" };
    return weekdays[calWeekday()];
}

int main() {
    Date myDate;
    int y, m, d;
    int newY, newM, newD; // C++98 变量声明放在块开头
    cout << "请输入日期（年 月 日，空格分隔）：";
    cin >> y >> m >> d;

    myDate.Init(y, m, d);
    cout << "当前日期信息：";
    myDate.display();

    cout << "\n请输入新日期（年 月 日）：";
    cin >> newY >> newM >> newD;
    myDate.setYear(newY);
    myDate.setMonth(newM);
    myDate.setDate(newD);
    cout << "修改后日期信息：";
    myDate.display();

    return 0;
}
