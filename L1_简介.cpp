//
// Created by admin on 2023/2/26.
//

#include <iostream> //引入标准输入/输出流
#include <string> //引入字符串

//using namespace std; //使用命名空间std
using std::cin;
using std::cout;
using std::string;
using std::endl;

#include "L1_简介.h"


void function_in_out();

void const_cast_demo();

void default_params_demo(int, int, int);

void const_and_normal_ref();

void ref_init_demo();

void SwapValue(int, int);

void SwapRef(int &, int &);

void SwapTest();

int &RefValueFunc(int &x);

void RefValueFuncTest();

int main() {
//    function_in_out();
//    const_cast_demo();
//    default_params_demo(1,2,3);
//    const_and_normal_ref();
//    ref_init_demo();
//    SwapTest();
    RefValueFuncTest();

    return 0;
}

/*
 * Target
 * 1.了解C++发展历史，了解C++与C之间的异同点；
 * 2.掌握C++程序结构，能够正确使用头文件及命名空间；
 * 3.掌握C++基本输入/输出语句，实现程序的输入/输出工呢；
 * 4.掌握函数的声明，参数传递方式，参数默认值，内敛函数等相关知识，并灵活运用；
 * 5.理解函数重载的概念，能够根据调用语句识别出调用的函数版本；
 * 6.理解const含义及作用，理解指针及引用的概念；掌握C++中动态内存分配及释放的方法，并灵活运用；
 * 7.掌握string类的基本功能，能够声明string类对象，能够调用string类中成员函数进行基本操作；
 *
 *
 * --------------------------------------------------------------------------------------------------
 *
 * Section 1 C++语言的发展
 *
 * 通常根据是否可以直接操作计算机底层硬件，将程序设计语言分为低级语音、中级语言和高级语言；
 * 机器语言和汇编语言属于低级语言，因为它们能够直接操作计算机的寄存器和内存；
 * 机器语言是一种依赖于CPU的指令系统，使用机器指令的二进制代码编写程序，能够直接被计算机识别；
 * 汇编语言使用能够代表指令的助记符来编写程序，可以看作是符号化了的机器语音；
 * 这类语言会因为计算机指令系统的不同而不同，通用型差；
 * 在计算机诞生初期，使用低级语言编程是主要的开发形式；
 *
 * 高级语言是面相用户的语言，很多语言在形式上接近于算术语言和自然语言，程序员编写方便；
 * 使用高级语言编写的程序易读且通用型强，但大部分不能直接与硬件打交道，也不能直接在计算机上运行，需要系统软件支持，
 * 如需要编译程序及链接程序将高级语音编译链接为机器指令后才能运行；
 * 第一代高级语音以Fortran和ALGOL60语音为代表，它们的出现使得程序设计的难度降低，计算机应用的领域得到扩展，C++也属高级程序设计语音；
 *
 * C语言既有高级语音的形式，也能在一定程度上以特定的方法直接操作硬件；
 * 有些教材认为C语音为中级语言，还有一些将C语音视为高级程序设计语言；
 *
 * C++语音由Bjarne Stroustrup于1979年在美国贝尔实验室开始设计开发的；
 * 1985年，推出C++1.0版本；
 * 1989年和1993年增加了很多新功能的C++2.0及C++3.0版相继问世；
 * 1998年，C++的ANSI/ISO标准被投入使用，这是C++标准第一版，称为C++98；
 * 通常，C++98被认为是标准C++，所有主流C++编译器都支持这个版本；
 * C++标准第二版、第三版、第四版、第五版分别于2003、2011、2014、2017年发布；
 * 这四个标准分别称为c++03、C++11、C++14、C++17，都是目前C++编程语言的正式标准；
 *
 * C语音是C++语音的前身，C++语音最初被命名为带类的C语言，可见俩者之间的渊源；
 * 知道1983年才更名为C++语言；
 * 可以将C++语言看作C语言的一个超集，C语言中的绝大部分语法成分都被保留了下来，其实标准的C程序也可以在C++语音的开发环境下运行；
 *
 * Section 2 C++语言的特点
 *
 * C++语言是一种编译式的、通用的、大小写敏感的编程语言，完成支持面相对象的开发模式；
 * C++语言的主要特点表现在俩个方面：首先，它是C语言的继承，尽量兼容C语言，既保持了C语言的简洁和高效，可以像C语言那样进行结构化程序设计，
 * 同时也增强了C语言对类型的处理。其次加入了面相对象的特征，可以进行以抽象数据类型为特点的基于对象的程序设计，还可以进行以继承和多态为
 * 特点的面相对象的程序设计；
 *
 * 从程序运行的稳定性来说，C++语言比C语言更安全，它支持过程化编程、面相对象变成和泛型编程；因为支持面相对象的开发模式，所以C++语言应用
 * 领域更加广泛；
 *
 * C++语言可以运行于多种平台上，如Windows、MAC操作系统以及UNIX的多种版本；
 *
 * C++语言加入面相对象的概念，虽然C语言的语法绝大部分都被保留，但C++的程序结构与C语言的程序结构存在很大差别；
 *
 * 一、基本的输入/输出
 * 在C语言中，标准的键盘输入和屏幕输出功能分别为scanf()和printf()；
 * 在C++语言中，类库中提供了输入流istream和输出流ostream；
 * cin和cout分别是istream和ostream类的对象，用来实现基本的键盘输入和屏幕输出；
 *
 * 在输入流中获取数据的操作称为提取操作，向输出流中添加数据的操作称为插入操作；
 * 运算符">>"和"<<"是位移运算符，在C++类库提供的头文件中已经对">>"和"<<"进行了重载，使之分别作为流提取运算符和流插入运算符，
 * 用来输入和输出C++标准类型的数据；
 *
 * 在C++中，可以使用流提取符">>"从标准输入设备键盘取得数据。例如，"cin>>x;"从键盘获取输入数据并赋值给x；
 * 使用cin可以活的多个来自键盘的输入值；
 * cout是标准输出流对象，使用流插入运算符"<<"向输出设备屏幕输出信息；
 * 当程序中用到cin和cout时，需要在程序中包含头文件<iostream>；
 * 用户自定义的类型的数据，不能直接使用">>"和"<<"进行输入/输出，必须对">>"和"<<"进行运算符重载才可使用；
 * cin的一般格式如下：
 * cin>>变量1>>变量2>>..>>变量n;
 * cout的一般格式如下：
 * cout<<表达式1<<表达式2<<...<<表达式n;
 * 其中，cin变量可以是任何基本类型的变量，当连续输入时，以空格、制表符(tab)、或Enter作为分隔符；
 * 当第一个字符是空格、tab或enter时，cin会忽略并清除掉，继续读取下一个字符；
 * cout语句中可以是各种基本类型的变量、常量、以及组合得到的正确表达式；
 *
 * 输入/输出示例 见function_in_out();
 */

void function_in_out() {
    int oneInt1, oneInt2;
    char strArray[20];
    string str;
    double oneDouble;
    char oneChar = 'a';

    cout << "输入俩个整型值，一个字符，一个字符串，和一个浮点数，";
    cout << "以空格、tab货enter分隔;" << endl;
    cin >> oneInt1 >> oneInt2 >> oneChar >> strArray >> oneDouble;
    str = strArray;
    cout << "输入的数据是:" << endl; //endl的作用是换行
    cout << "字符串是: \t\t" << str << endl //\t是制表符
         << "俩个整型值是: \t" << oneInt1 << " 和 " << oneInt2 << endl
         << "字符是: \t\t\t" << oneChar << "\n" //\n是换行符，与endl效果相同
         << "浮点值是: \t\t" << oneDouble << endl;
}

/*
* 二、头文件和命名空间
* C语言中使用头文件保存程序中用到的声明，例如函数声明、常量定义等，C++也是；
* 使用#include指令包含了头文件iostream；
* iostream是C++的标准输入/输出流，当在程序中使用cin或cout时，必须在头文件中包含这个流；
* 每条#include指令仅可以包含一个头文件；
* 在C++中，头文件不再以".h"结尾。以".h"结尾的头文件是C语言中常用的头文件；
* 常用的头文件有以下：
* 标准输入输出流：<iostream>;
* 标准文件流：<fstream>;
* 标准字符串处理函数：<string>;
* 标准数学函数：<cmath>;
*
* 除了系统提供的头文件，还可以自定义头文件，通常，使用尖括号在系统中提供的头文件，使用双引号引入自定义头文件；
* 使用尖括号时，C++编译器首先在C++系统设定的目录中寻找要包含的文件，如果没有，再到指令中指定的目录去寻找；
* 采用双引号时，C++编译器首先在用户当前目录下或指令中指定的目录下需要；
* 例如，要包含e:\myprog目录下的头文件ex1.h相应的语句如下:
* #include "e:\myprog\ex1.h"
*
* using namespace std;表示使用命名空间std；
* 一个大型程序通常由不同的模块构成，各个模块有可能是由不同的人开发，不同模块中出现的标识符之间可能有重名现象，
* 这就会引发错误。C++中为了避免名字定义冲突，特别引入了"命名空间"的定义，即namespace，命名空间是为了消除同名引起的歧义；
* 定义一个命名空间的语法如下：
* namespace 命名空间名
* {
*      命名空间内的各种声明（函数声明、类声明.......）
* }
* 命名空间也成为名字空间，这是C++的一种机制，使用关键字namespace把大量有逻辑联系的程序实体组合在一个标识符下；
* 例如：C++标准库中的所有标识符都定义在一个名为std的命名空间中。当程序使用标准程序库中的标识符时，如果没有语句
* "using namespace std;"，泽cin和cout都没有定义，string也是如此，甚至endl也不能识别；
* using 命名空间名::标识符；
* using namespace 命名空间名；
* 前一种形式表示直接使用指定标识符；后一种表示使用指定命名空间内所有标识符；
*
* 三、强制类型转换运算符
* 当不同类型的量进行混合算术运算时，系统会自动进行合理的类型转换，也可以在程序中使用强制类型转换运算符
* static_cast或const_cast进行转换；
* static_cast用于将一种数据类型转换为另一种数据类型：
* static_cast<类型名>(表达式)
* 如下四种写法都是正确的：
*/

void cast_demo() {
    int oneInt1;
    double oneDouble;

    oneInt1 = static_cast<int>(oneDouble);
    oneInt1 = int(oneDouble);
    oneInt1 = (int) oneDouble;
    oneInt1 = oneDouble;//自动类型转换
}

/*
 * const_cast用于去除指针和引用的常量性，但不能去除变量的常量性。
 * const_cast<类型名>(表达式);
 * 这个运算符的功能是，将常量指针转换成非常量的指针，并且仍然指向原来的对象；
 * 或将常量引用转换成非常量的引用，并且仍然指向原来的对象；
 *
 * 见如下示例：
 */
using namespace std;

void const_cast_demo() {
    int a = 10;
    const int *p = &a; //不能使用常量指针p修改a的值
    const int ca = 30; //被const修饰
    int *q;
    cout << "a的地址为：\t\t" << &a << "\ta 的值为：\t" << a << endl;
    cout << "*p指向的地址为：\t" << p << "\t*p的值为：\t" << *p << endl;
    q = const_cast<int *>(p); //去除p的常量性赋给q，如果写q=p;会报错
    *q = 20; //如果写*p=20;是错误的
    cout << "a的地址为：\t\t" << &a << "\ta的值为：\t" << a << endl;
    cout << "*p指向的地址为：\t" << p << "\t*p的值为：\t" << *p << endl;
    cout << "*q指向的地址为：\t" << q << "\t*q的值为：\t" << *q << endl;
    cout << "分界线" << endl;
    p = &ca; //ca的值不能修改
    q = const_cast<int *>(p); //去除p的常量性赋给q，如果写q=p;会报错
    *q = 40; //*p=40;是错误的
    cout << "ca的地址为：\t\t" << &ca << "\tca的值为：\t" << ca << endl;
    cout << "*p指向的地址为：\t" << p << "\t*p的值为：\t" << *p << endl;
    cout << "*q指向的地址为：\t" << q << "\t*q的值为：\t" << *q << endl;
}

/*
 * 程序说明：其中定义了俩个指针，p是常量性的，q不是常量性的。如果将p赋值给q，会报错，正如程序组注释所标注的。
 * 使用强制类型转换后，赋值成功；并且可以使用指针q对其所指地址的内容进行修改。这是程序前半段的运行情况，"分界线"之前显示了运行结果；
 * 接下来，使用同样的操作，处理ca，变量ca有const属性，因此ca的值是不会被程序所改变的。即使将指向ca的指针p的const属性去掉，重新赋值给q，
 * 并通过q进行修改，将q所指地址的内容修改为另一个值，也不会改变ca的值。所以这里出现了变量ca地址和指针q指向地址相同，但值不同的现象。
 *
 * 四、函数参数的默认值
 * 在C++语言中，可以在声明函数时为形参指定默认值。当调用有默认参数值的函数时，调用语句可以不给出对应的实参，相当于调用该函数时，以
 * 默认值为参数。指定默认值时不仅可以用常数，还可以用任何有定义的表达式作为参数的默认值。但不允许是函数内定义的局部变量。
 *
 * 定义带有默认值的函数，见如下示例：
 */

void default_params_demo(int a = 11, int b = 22, int c = 33) {
    cout << "a=" << a << ",b=" << b << ",c=" << c << endl;
}

/*
 * 运行结果未达到预期，大致能猜到，可能是环境原因；
 *
 * 函数调用示例：
 * void defaultValue(int = 2,double = 3.0);
 * void defaultValue(int a,double b = 3.0);
 * void defaultValue(int a = 2, double b);
 * void func(int a,int b = 2,int c = 3);
 * void func(int a = 1,int b,int c = 3);
 * void func(int a = 1,int b = 2,int c)
 *
 * 第一组函数，前俩个是正确的，可以没有变量名。但如果给出默认值，必须按从右到左的次序依次给出，不能给出左侧参数的默认值而忽略右侧。
 * 第二组函数同理，只有第一个是正确的。
 *
 * 假设给出以下函数：
 * void func(int a,int b=2,int c=3);
 * 下列那些函数调用是正确的？
 * func(1,22,333); //正确，全参且类型都是匹配的
 * func();         //错误，参数a没有默认值，必须给出实参
 * func(10,20);    //正确，c采用默认值
 * func(5,,9);     //错误，调用时给出的实参应是连续排列的
 *
 * 调用示例(二)示例：
 * 假设给出如下函数及变量声明：
 * int Max(int m,int n);
 * int a,b;
 * void func(int x,int y=Max(a,b),int z=a-b){......};
 * 则下列函数调用中哪些正确？
 * func(4);
 * func(4,9);
 * func()的定义中使用表达式作为形参y和z的默认值，这些表达式在调用时都有结果，所以俩个调用是正确的。
 *
 * 函数参数的默认值可以写在声明函数的地方，也可以写在定义函数的地方，但不能俩个地方都写。
 *
 * 五、引用和函数参数的传递
 * 1.引用的定义
 * 引用相当于给变量起了个别名。变量对应与某个内存地址，如果给某个变量起了别名，相当于变量和这个引用都对应到同一个地址。
 * 程序中使用哪个名字都是可以的。在C++中，"引用"的定义格式如下：
 * 类型名 &引用名 = 同类型的某变量名；
 * 举例如下：
 * int oneInt;
 * int &aname = oneInt; //声明引用
 * 这样定义后，aname就是一个引用，它的类型是int &。声明引用后，系统并不为aname分配内存空间，aname与oneInt对应的是一个内存地址。
 * 对于类型T而言，类型为T &的引用和类型为T的变量是完全兼容的，可以互相赋值。例如，如果变量oneInt的值保存在0x5ffddc地址中，
 * 则&aname是0x5ffddc。如果"oneInt = 3"，那么执行下列语句时，会输出值3：
 * cout<<aname<<endl;
 * 声明引用aname时，变量oneInt必须进行了初始化。在C++98标准下，系统自动将oneInt初始化为0。另外，不能有空引用，即引用
 * 必须指向某个已存在的内存区域的首地址。也不能声明引用的应用，例如，这样的声明"int &b = &aname;"是错误的；
 * 同一个变量的引用可以有多个，例如，变量oneInt还可以有另一个引用bname。此时，即可以使用变量来进行引用初始化，也可以使用
 * 引用aname为另一个引用bname进行初始化；
 * 定义引用时，可以在定义的前面加const关键字，表明该引用是"常引用"，例如：
 * int oneInt;
 * const int &cname = oneInt;
 * 这两行定义了常引用，它的类型是const int &。
 *
 * 常引用和普通引用的区别在于：不能通过常引用去修改其引用的变量。在下面程序中，定义了普通引用ref和常引用refc，它们都是值为1的
 * 整形变量oneInt的引用。通过普通引用ref可以修改oneInt的值，但不能通过常引用refc改变oneInt的值。
 */

void const_and_normal_ref() {
    int oneInt = 1;
    int &ref = oneInt;                      //ref是oneInt的引用，ref等价于oneInt
    const int &refc = oneInt;               //定义常引用
    ref = 2;                                //修改ref也即修改了oneInt
    cout << "oneInt = " << oneInt << "," << "ref = " << ref << endl;    //输出oneInt=2，ref=2
    cout << "refc = " << refc << endl;      //输出refc=2
    oneInt = 3;                             //修改oneInt也即修改了ref
    cout << "ref = " << ref << endl;        //输出ref=3
    cout << "refc = " << refc << endl;      //输出refc=3
    int &ref2 = ref;                        //ref2和ref都是oneInt的引用
    cout << "ref2 = " << ref2 << endl;      //输出ref2=3
    //refc = 5;                             //错误，不能使用常引用对所引用的变量进行修改
}

/*
 * const T &和T &是不同的类型。当声明变量并进行初始化时，同类型之间进行初始化是允许的，不同类型之间进行初始化，有些情况是允许的。
 * 例如，使用T类型的变量货T &类型的引用，均可以初始化const T &类型的引用和T &类型的引用。
 * 但是，使用const T类型的常变量和const T &类型的常引用却不能直接用原来初始化T &类型的引用。如果必须这样做，则需要强制转换。
 * 以整形类型为例，关于初始化的各种组合情况，参照如下示例：
 */

void ref_init_demo() {
    const int cInt = 30;
    int oneInt = 50;
    int &ref = oneInt;          //T& <- T
    const int &rc1 = cInt;      //CT& <- CT,CT&表示类型T的常引用
    const int &rc2 = oneInt;    //CT& <- T
    const int &rc3 = ref;       //CT& <- T&
    int dInt = ref;             //T <- T&
    int eInt = cInt;            //T <- CT, CT表示常量类型
    int fInt = rc1;             //T <- CT&
    const int gInt = oneInt;    //CT <- T
    int &ref1 = ref;            //T& <- T&
    const int hInt = ref;       //CT <- T&
    const int jInt = cInt;      //CT <- CT
    const int &mInt = rc1;      //CT& <- CT&
    const int nInt = rc2;       //CT <- CT&
    cout << "OK" << endl;
    int &r2 = (int &) rc1;      //T& <- CT& 需要强制类型转换
    int &r3 = (int &) cInt;     //T& <- CT 需要强制类型转换
}

/*
 * 其中，T表示类型，CT表示常量类型， T&表示类型T的引用，CT&表示类型T的常引用。
 * 以上列出了变量、变量引用、常变量及常引用之间的各种初始化情况，大多数都是允许的，只有最后俩种情况需要通过强制类型转换来初始化；
 *
 * 2.引用在函数中的使用
 * 在程序中，不仅可以定义变量的引用，还可以将引用用在函数中。引用即可以作为函数的参数使用，也可以作为函数的返回值使用。
 *
 * 在C++中，函数调用时参数的传递有俩种方式：传值和传引用。传值，实际上是传递对象的值。传引用，是传递对象的首地址。
 * 如果函数的形参不是引用，那么调用时实参传递给形参通常采用的是传值的方式，即将实参的值拷贝给形参。在函数执行过程中，都是对这个
 * 拷贝进行操作的，函数执行完毕返回后，形参的值并不拷贝回实参，也就是说函数内部对形参的改变不会影响到函数外实参的值。
 *
 * why? 调用一个函数时，他的形参及函数内部定义的局部变量被分配在称为栈的内存空间中。这与实参所在的空间不同。传值时，将实参的值
 * 拷贝到栈中对应的形参的地址中，函数内部对形参的操作，其实是对这个地址操作，而不是对实参所占用的地址进行操作的。函数执行完毕时，
 * 并不将这个地址中的值拷贝出去，所以实参的值不会收到影响。
 *
 * 如果函数的形参是引用，则调用时实参传递给形参采用的是传引用的方式。函数调用时，实参对象名传递给形参对象名，形参对象名就成为了
 * 实参对象名的别名，即形参是对应实参的引用，它们是等价的，代表同一个对象，也可以看作是将实参的地址传递给了形参。在函数内部
 * 对形参的操作，都是对这个地址的内容进行的，相当于对实参的值进行了操作。所以，实参的变化被保留了下来。
 *
 * 不同的参数传递方式，见如下示例：
 */

void SwapValue(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << "在SwapValue()函数中：\t\ta = " << a << ",b = " << b << endl;
}

void SwapRef(int &a, int &b) {  //a、b值互换
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << "在SwapRef()函数中：\t\ta = " << a << ",b = " << b << endl;

}

void SwapTest() {
    int a = 10, b = 20;
    cout << "数据交换前：\t\ta = " << a << ",b = " << b << endl << endl;
    SwapValue(a, b);
    cout << "调用SwapValue()后：\t\ta = " << a << ",b = " << b << endl << endl;
    SwapRef(a, b);
    cout << "调用SwapRef()后：\t\ta = " << a << ",b = " << b << endl << endl;
}

/*
 * 总结以下，在传值调用函数的情况下，形参是实参的副本，形参的改变不会影响到实参。但调用时生成临时变量完成值的复制，
 * 这需要一定的时间和空间。在传引用调用函数的情况下，形参的改变就意味着实参的改变。
 * 可以用const引用作为函数的参数，这样做，既可以避免赋值形参时所需要的开销，又能放置实参在函数执行过程中被改变。
 *
 * 引用还可以作为函数的返回值。变量是可以作为赋值语句的左值存在的，既然引用可以看作变量的别名，那么引用也可以作为赋值语句的左值，
 * 即可以放在赋值语号的左侧。
 *
 * 在赋值语句中，赋值号左侧的表达式称为左值，右侧的表达式称为右值。左值表达式即能出现在赋值号的左侧，也能出现在赋值号的右侧。
 * 变量、引用、指针都可以作为左值。例如，对于整形变量x和y，可以写x=3;和x=y;。对于整形指针（指向整形的指针，即int *p）,可以
 * 写"*p = &x;"和"*p = 5;"。
 *
 * 返回引用的函数格式如下：
 * 数据类型 & 函数名(参数列表)；
 *
 * 具体见如下示例：
 */
int &RefValueFunc(int &x) {
    return x;
}

void RefValueFuncTest() {
    int oneX = 10;
    int oneY = 20;
    RefValueFunc(oneX) = 30;            //返回值是引用，可以作为左值使用
    cout << "oneX = " << oneX << endl;     //输出oneX = 30
    RefValueFunc(oneY) = 40;
    cout << "oneY = " << oneY << endl;     //输出oneY = 40
}

/*
 * RefValueFunc()函数的返回值是一个引用，所以可以作为赋值语句的左值使用。
 * 函数的返回值还可以是指针，这样的函数称为指针函数，函数的格式如下：
 * 类型标识符 * 函数名(参数列表);
 *
 * 六、const与指针共同使用
 * 与C语音一样，C++也可以使用const限定访问权限，告诉编译器，它所修饰的量是不能改变的，也就是不能作为左值使用；
 * 程序中使用指针时，涉及的量有俩个：一个是指针本身，另一个是指针所指向的内容；
 * 当const与指针共同使用时，其确切的含义是什么？是说指针本身不能改变，即不能让其指向其他地址？
 * 还是指针所指向的内容不能改变？亦或是俩个含义多有？
 * 其实，当const与指针共同使用，其书写位置不同造成的语句语义也不同。
 *
 * const修饰指针变量时，基本含义如下：
 * 1)如果唯一的const位于符号*的左侧，表示指针所指数据是常量，数据不能通过本指针改变，但可以通过其他方式进行修改，
 * 指针本身是变量，可以指向其他的内存单元；
 * 2)如果唯一的const位于符号*右侧，表示指针本身是常量，不能让该指针指向其他内存地址，指针所指向的数据可以通过本指针修改；
 * 3)在符号*左右各有一个const时，表示指针和指针所指向数据都是常量，既不能让指针指向其他地址，也不能通过指针修改所指向的内容；
 *
 * P43
 */



