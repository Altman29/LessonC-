//
// Created by admin on 2023/2/28.
//

#include "L5_obj_继承与派生.h"
#include <iostream>
using namespace std;

int main(){
    cout << "L4 类的继承与派生" << endl;

    return 0;
}

/*
 * Target:
 * 1.理解类的继承与派生的概念，掌握派生类的定义方法，了解3中继承方式下，派生类能从基类继承的元素有哪些；
 * 2.了解继承关系中友元和静态成员变量的派生特点；
 * 3.了解单重继承与多重继承的概念和异同点，了解派生层次；
 * 4.掌握访问权限控制符的含义，掌握基类与派生类之间的访问方式；
 * 5.掌握派生类的构造函数和析构函数的定义方法，了解基类与派生类构造函数与析构函数的调用次序；
 * 6.了解类之间的关系，能够定义封闭类的派生类，掌握封闭类的派生类的构造函数与析构函数的调用次序；
 * 7.掌握基类与派生类指针的含义，能够实现互相转换；
 *
 *
 * --------------------------------------------------------------------------------------------------
 *
 *
 */



/*
 * C++继承
 * 面向对象程序设计中最重要的一个概念是继承。继承允许我们依据另一个类来定义一个类，
 * 这使得创建和维护一个应用程序变得更容易。这样做，也达到了重用代码功能和提高执行效率的效果
 *
 * 当创建一个类时，您不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为基类，新建的类称为派生类。
 * 继承代表了 is a 关系。例如，哺乳动物是动物，狗是哺乳动物，因此，狗是动物，等等。如下所示：
 *
 * //基类
 * class Animal{
 *      //eat()函数
 *      //sleep()函数
 * };
 *
 * //派生类
 * class Dog: public Animal{
 *      //bark()函数
 * };
 *
 *
 * 基类&派生类
 * 一个类可以派生自多个类，这意味着，它可以从多个基类继承数据和函数。定义一个派生类，我们使用一个类派生列表来指定基类。
 * 类派生列表以一个或多个基类命名，形式如下：
 * class derived-class : access-specifier base-class
 * 其中，访问修饰符 access-specifier 是 public、protected 或 private 其中的一个，
 * base-class 是之前定义过的某个类的名称。如果未使用访问修饰符 access-specifier，则默认为 private。
 *
 * 假设有个基类Shape，Rectangle是它的派生类，如下所示：
 */
#include <iostream>

using namespace std;

//基类
class Shape {
protected:
    int width;
    int height;
public:
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }
};

//派生类
class Rectangle : public Shape {
public:
    int getArea() {
        return width * height;
    }
};

int main182001() {
    Rectangle rect;

    rect.setWidth(5);
    rect.setHeight(7);

    //输出面积
    cout << "Total area: " << rect.getArea() << endl;
    return 0;
}

/*
 * 访问控制和继承
 * 派生类可以访问基类中所有的非私有成员。因此基类成员如果不想被派生类的成员所访问，则应在基类中声明private。
 * 可以根据访问权限总结不同的访问类型：
 *
 *  访问           public          protected           private
 * 同一个类         yes             yes                 yes
 *  派生类          yes             yes                 no
 *  外部的类        yes             no                  no
 *
 *  一个派生类继承了所有的基类方法，但也有例外：
 *      基类的构造函数、析构函数和拷贝构造函数。
 *      基类的重载运算符。
 *      基类的友元函数。
 *
 *
 * 继承类型
 * 当一个类派生自基类，该基类可以被继承为 public、protected 或 private 几种类型。继承类型是通过上面讲解的访问修饰符 access-specifier 来指定的。
 * 我们几乎不使用 protected 或 private 继承，通常使用 public 继承。当使用不同类型的继承时，遵循以下几个规则：
 *      公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，
 *                      基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
 *      保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
 *      私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。
 *
 *
 * 多继承
 * 多继承即一个子类可以有多个父类，它继承了多个父类的特。
 * C++类可以从多个类继承成员，语法如下：
 * class <派生类名>: <继承方式1><基类名1>,<继承方式2><基类名2>,...
 * {
 *      <派生类类体>
 * };
 *
 * 其中访问修饰符继承方式是public、protected或private其中的一个，用来修饰每个基类，各个基类之间用逗号隔开，
 * 示例如下：
 */
#include <iostream>

using namespace std;

//基类 Shape
class Shape1 {
protected:
    int width;
    int height;
public:
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }
};

//基类 PaintCost
class PaintCost {
public:
    int getCost(int area) {
        return area * 70;
    }
};

//派生类
class Rectangle1 : public Shape1, public PaintCost {
public:
    int getArea() {
        return width * height;
    }
};

int main102702() {
    Rectangle1 rect;
    int area;

    rect.setWidth(5);
    rect.setHeight(7);

    area = rect.getArea();

    //输出对象的面积
    cout << "Total area: " << rect.getArea() << endl;

    //输出总花费
    cout << "Total paint cost: $" << rect.getCost(area) << endl;
}