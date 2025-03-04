#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // 构造函数重载
    Date(int m = 1, int d = 1, int y = 2019) : month(m), day(d), year(y) {}

    // 显示日期的函数
    void display() {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    Date d1(3, 25, 2019);
    Date d2(3, 30);
    Date d3(10);
    Date d4;
    d1.display();
    d2.display();
    d3.display();
    d4.display();
    return 0;
}
