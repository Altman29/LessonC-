//
// Created by admin on 2023/3/5.
//

#include "test.h"


#include <iostream>

using namespace std;

class B {
private:
    int x = 0;
    int y = 1;
public:
    void fun1(int) {
        x = x + 1;
    };
};

class X {
    int a;
    void fun1();

public:
    void fun2();
};



//设计题1
int main() {
//    int n;
//    cout << "请输入n的值" << endl;
//    cin >> n;
//    string *arr = new string[n];
//    for (int i = 0; i < n; i++) {
//        cout << "请输入第" << i + 1 << "个参数：" << endl;
//        cin >> arr[i];
//    }
//    cout << "开始打印数组" << endl;
//    for (int i = 0; i < n; i++) {
//        cout << "arr[" << i << "]=" << arr[i] << endl;
//    }
//    delete[]arr;

    X objX;

    return 0;
}
