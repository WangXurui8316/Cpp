#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int countVowels(const char* p) {
    int count = 0;
    while (*p != '\0') {
        char ch = tolower(*p); // 转换为小写统一判断
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
        p++; // 移动指针
    }
    return count;
}

int main() {
    cout << "统计元音字母" << endl;
    
    string input;
    cout << "请输入一行字符串: ";
    getline(cin, input);
    
    int vowelCount = countVowels(input.c_str());
    cout << "元音字母个数: " << vowelCount << endl;

    return 0;
}
