//
// Created by admin on 2023/2/28.
//

#include "L4_运算符重载.h"
#include <iostream>

using namespace std;

int main() {
    cout << "L4 运算符重载" << endl;
    return 0;
}

/*
 * Target:
 * 1.理解运算符重载
 * 2.掌握运算符重载作为成员函数和友元函数的俩种方式；
 * 3.对自己定义的类重载加法运算符(+)、减法运算符(-)、赋值运算符(=)、流插入运算符(>>)和流提取运算符(<<)；
 * 4.能够对特定的类重载前置和后置形式下的自增、自减运算符；
 * 5.理解浅拷贝和深拷贝的概念，能够根据浅拷贝和深拷贝的要求重载赋值运算符；
 *
 *
 * --------------------------------------------------------------------------------------------------
 *
 * Section 1 结构化程序设计
 */




/*
 * C++重载运算符和重载函数
 * C++允许在同一作用域中的某个函数和运算符指定多个定义，分别称为函数重载和运算符重载。
 * 重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但它们的参数列表和定义(实现)不同。
 * 当调用一个重载函数或重载运算符时，编译器通过把你所使用的参数类型与定义中的参数类型比较，决定选用合适的定义。
 * 选择合适的重载函数或运算符的过程，称为重载决策。
 */


/*
 * C++中的函数重载
 * 在同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数(指参数的个数、类型或顺序)必须不同。
 * 不能仅通过返回类型不同来重载函数。
 * 示例如下：
 */
#include <iostream>

using namespace std;

class printData {
public:
    void print(int i) {
        cout << "整数为" << i << endl;
    }

    void print(double f) {
        cout << "浮点数为" << f << endl;
    }

    void print(char c[]) {
        cout << "字符串为" << c << endl;
    }
};

int main112509() {
    printData pd;

    //输出整数
    pd.print(5);
    //输出浮点数
    pd.print(500.253);
    //输出字符串
    char c[] = "Hello C++";
    pd.print(c);
    return 0;
}

/*
 * C++中的运算符重载
 * 可以重定义或重载大部分C++内置的运算符。这样，就能使用自定义类型的运算符。
 * 重载的运算符是带有特殊名称的函数，函数名是由关键字operator和其后要重载的运算符符号构成的。
 * 与其他函数一样，重载运算符有一个返回类型和一个参数列表。
 * Box operator+(const Box&);
 * 声明加法运算符用于把俩个Box对象相加，返回最终的Box对象。
 * 大多数的重载运算符可以被定义为普通的非成员函数或被定义为类成员函数。
 * 如果我们定义上面的函数为类的非成员函数，那么需要为每次操作传递俩个参数，如下所示：
 * Box operator+(const Box&, const Box&);
 *
 * 下面示例使用成员函数演示了运算符重载的概念。在这里，对象作为参数进行传递，对象的属性使用this运算符进行访问：
 */
#include <iostream>

using namespace std;

class MyBox {
private:
    double length;//长度
    double width;//宽度
    double height;//高度
public:
    double getVolume() const {
        return length * width * height;
    }

    void setLength(double len) {
        length = len;
    }

    void setWidth(double wid) {
        width = wid;
    }

    void setHeight(double hei) {
        height = hei;
    }

    //重载+运算符，用于把俩个MyBox相加
    MyBox operator+(MyBox &b) {
        MyBox box;
        box.length = this->length + b.length;
        box.width = this->width + b.width;
        box.height = this->height + b.height;
        return box;
    }
};

int main165602() {
    MyBox box1;
    MyBox box2;
    MyBox box3;
    double volume = 0.0;

    //MyBox1
    box1.setLength(6.0);
    box1.setWidth(7.0);
    box1.setHeight(5.0);

    //MyBox2
    box2.setLength(12.0);
    box2.setWidth(13.0);
    box2.setHeight(10.0);

    //box1 体积
    volume = box1.getVolume();
    cout << "Volume of box1: " << volume << endl;

    //box2 体积
    volume = box2.getVolume();
    cout << "Volume of box2: " << volume << endl;

    //把俩个对象相加，得到box3
    box3 = box1 + box2;

    //box3 体积
    volume = box3.getVolume();
    cout << "Volume of box3: " << volume << endl;

    return 0;
}

/*
 * 可重载运算符
 * 双目算术运算符	+ (加)，-(减)，*(乘)，/(除)，% (取模)
 * 关系运算符	==(等于)，!= (不等于)，< (小于)，> (大于)，<=(小于等于)，>=(大于等于)
 * 逻辑运算符	||(逻辑或)，&&(逻辑与)，!(逻辑非)
 * 单目运算符	+ (正)，-(负)，*(指针)，&(取地址)
 * 自增自减运算符	++(自增)，--(自减)
 * 位运算符	| (按位或)，& (按位与)，~(按位取反)，^(按位异或),，<< (左移)，>>(右移)
 * 赋值运算符	=, +=, -=, *=, /= , % = , &=, |=, ^=, <<=, >>=
 * 空间申请与释放	new, delete, new[ ] , delete[]
 * 其他运算符	()(函数调用)，->(成员访问)，,(逗号)，[](下标)
 *
 * 不可重载运算符
 * .：成员访问运算符
 * .*, ->*：成员指针访问运算符
 * ::：域运算符
 * sizeof：长度运算符
 * ?:：条件运算符
 * #： 预处理符号
 *
 * 值得注意的是
 * 1.运算符重载不可以改变语法结构哦
 * 2.运算符重载不可以改变操作数的个数
 * 3.运算符重载不可以改变优先级
 * 4.运算符重载不可以改变结合性
 */