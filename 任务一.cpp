#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdio>
using namespace std;

struct Transaction {
    string time;
    string type;
    double amount;
    double afterBalance;
};

class Card {
private:
    string accountId;
    double balance;
    vector<Transaction> transactions;
public:
    Card(string id, double bal) : accountId(id), balance(bal) {}

    string getAccountId() { return accountId; }
    double getBalance() { return balance; }

    void recharge(double amt) {
        if (amt <= 0) {
            cout << "充值金额需大于0！" << endl;
            return;
        }
        balance += amt;
        addTransaction("充值", amt);
        cout << "充值成功！当前余额：" << balance << endl;
    }

    void consume(double amt) {
        if (amt <= 0) {
            cout << "消费金额需大于0！" << endl;
            return;
        }
        if (amt > balance) {
            cout << "余额不足，消费失败！" << endl;
            return;
        }
        balance -= amt;
        addTransaction("消费", amt);
        cout << "消费成功！当前余额：" << balance << endl;
    }

    void queryTransactions() {
        cout << "\n[" << accountId << "] 交易记录：" << endl;
        if (transactions.empty()) {
            cout << "暂无交易记录" << endl;
            return;
        }
        vector<Transaction>::iterator it;
        for (it = transactions.begin(); it != transactions.end(); ++it) {
            cout << it->time << " | " << it->type << " | " << it->amount << " | 余额：" << it->afterBalance << endl;
        }
    }

private:
    void addTransaction(string type, double amt) {
        Transaction t;
        time_t now = time(0);
        tm* local = localtime(&now);
        char timeBuf[20];
        sprintf(timeBuf, "%d-%02d-%02d %02d:%02d:%02d", 
                1900 + local->tm_year, 1 + local->tm_mon, local->tm_mday,
                local->tm_hour, local->tm_min, local->tm_sec);
        t.time = timeBuf;
        t.type = type;
        t.amount = amt;
        t.afterBalance = balance;
        transactions.push_back(t);
    }
};

class CardSystem {
private:
    vector<Card> users;
public:
    void addUser() {
        string id;
        double initBal;
        cout << "\n请输入账户ID：";
        cin >> id;
        vector<Card>::iterator it;
        for (it = users.begin(); it != users.end(); ++it) {
            if (it->getAccountId() == id) {
                cout << "该账户已存在！" << endl;
                return;
            }
        }
        cout << "请输入初始余额：";
        cin >> initBal;
        if (initBal < 0) {
            cout << "初始余额不能为负！" << endl;
            return;
        }
        users.push_back(Card(id, initBal));
        cout << "账户录入成功！" << endl;
    }

    Card* findUser(string id) {
        vector<Card>::iterator it;
        for (it = users.begin(); it != users.end(); ++it) {
            if (it->getAccountId() == id) {
                return &(*it);
            }
        }
        return NULL;
    }

    void showMenu() {
        int choice;
        string id;
        double amt;
        Card* user;
        while (true) {
            cout << "\n===== 高校一卡通系统 =====" << endl;
            cout << "1. 录入账户  2. 充值  3. 消费" << endl;
            cout << "4. 查询余额  5. 交易记录  6. 报表输出  7. 退出" << endl;
            cout << "请选择功能(1-7)：";
            cin >> choice;

            switch (choice) {
            case 1: 
                addUser(); 
                break;
            case 2: 
                cout << "请输入账户ID：";
                cin >> id;
                user = findUser(id);
                if (!user) { cout << "账户不存在！" << endl; break; }
                cout << "请输入充值金额：";
                cin >> amt;
                user->recharge(amt);
                break;
            case 3: 
                cout << "请输入账户ID：";
                cin >> id;
                user = findUser(id);
                if (!user) { cout << "账户不存在！" << endl; break; }
                cout << "请输入消费金额：";
                cin >> amt;
                user->consume(amt);
                break;
            case 4: 
                cout << "请输入账户ID：";
                cin >> id;
                user = findUser(id);
                if (!user) { cout << "账户不存在！" << endl; break; }
                cout << "[" << id << "] 当前余额：" << user->getBalance() << endl;
                break;
            case 5: 
                cout << "请输入账户ID：";
                cin >> id;
                user = findUser(id);
                if (!user) { cout << "账户不存在！" << endl; break; }
                user->queryTransactions();
                break;
            // 关键修改：给case 6加大括号，隔离变量作用域
            case 6: {
                cout << "\n===== 系统报表 =====" << endl;
                cout << "账户总数：" << users.size() << endl;
                double total = 0;
                vector<Card>::iterator it;
                for (it = users.begin(); it != users.end(); ++it) {
                    cout << "ID：" << it->getAccountId() << " | 余额：" << it->getBalance() << endl;
                    total += it->getBalance();
                }
                cout << "所有账户总余额：" << total << endl;
                break;
            }
            case 7: 
                cout << "退出系统成功！" << endl;
                return;
            default: 
                cout << "无效选择，请重新输入！" << endl;
            }
        }
    }
};

int main() {
    CardSystem system;
    system.showMenu();
    return 0;
}
