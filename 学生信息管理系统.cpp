#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    cout << "学生信息管理系统" << endl;
    
    int n;
    cout << "请输入学生人数: ";
    cin >> n;
    
    string *names = new string[n];
    double **scores = new double*[n];
    double *averages = new double[n];
    
    // 输入学生信息
    for (int i = 0; i < n; i++) {
        scores[i] = new double[3];
        cout << "请输入第" << i+1 << "个学生的信息(姓名 语文 数学 英语): ";
        cin >> names[i] >> scores[i][0] >> scores[i][1] >> scores[i][2];
        
        // 计算平均分
        averages[i] = (scores[i][0] + scores[i][1] + scores[i][2]) / 3.0;
    }
    
    // 输出成绩表
    cout << "\n学生成绩信息表:" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << left << setw(15) << "姓名" 
         << setw(10) << "语文" 
         << setw(10) << "数学" 
         << setw(10) << "英语" 
         << setw(10) << "平均分" 
         << "备注" << endl;
    cout << "-------------------------------------------------" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << names[i]
             << setw(10) << fixed << setprecision(1) << scores[i][0]
             << setw(10) << scores[i][1]
             << setw(10) << scores[i][2]
             << setw(10) << fixed << setprecision(2) << averages[i];
        
        if (averages[i] >= 90.0) {
            cout << "Excellent";
        }
        cout << endl;
    }
    
    // 释放内存
    for (int i = 0; i < n; i++) {
        delete[] scores[i];
    }
    delete[] names;
    delete[] scores;
    delete[] averages;
    
    return 0;
}
