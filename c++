C++笔记
#include<iostream>	
using std::cout;		//尽量不用using namespace std; 声明变量太多时
using std::endl;		//可能会发生冲突
int main(){
	cout << “hello world!” << endl;
	system(“pause”);
	return 0;
}

#include<iostream>	//input output stream的简写，意思为标准的输入输出流头文件

1.(1)输出      
cout<<”输出”<<endl;
  输出运算符（<<）接受两个运算对象，左侧必须是一个ostream对象，右侧的运算对象是要打印的值
 (2)输入      cin>>v1>>v2
 (3)std::cout  使用作用域运算符（：：）来指出我们想使用定义在命名空间std中的名字cout
(4)additems <infile >outfile   
  additems 是可执行文件，命令从一个名为infile的文件读取数据，并将输出结果写入到outfile文件中

2.float  
float=3.14f   float后面加f，不加默认是double
（默认情况，输出小数，输出六位有效数字）
cout<<sizeof(float)<<endl;  看类型占的空间，
float 占4字节，double占8字节

3.（1）（int）a    强制转换，把a转换为int类型
  （2）赋给无符号类型一个超出范围的值时，结果是初始值对无符号类型表示总数取模后的余数
（3）赋给带符号类型一个超出表示范围的值时，结果是未定义的，不可知
（4）算数表达式中既有无符号数又有int值时，int会转换成无符号数

4.字符串：
char str[ ]=”hello”
         string  str=”hello”  (C++风格，要包含头文#include<string>)

C的字符串和C++的字符串是不一样的。有时需要类型转换

5.布尔bool类型，0为假，非0为真（即使是负数也是真）

6.初始化：
创建变量时赋予其一个初始值
赋值：把对象的当前值擦除，以一个新值来替代
使用列表初始化且初始值存在丢失信息的风险，编译器会报错
long  double  ld = 3.14159265
int  a{ld} , b = {ld}       //错误，转换未执行，因为存在丢失信息的危险
int  c(ld) , b = ld         //正确，转换执行，且丢失了部分信息

7.C++是一种静态类型（statically typed）语言，其含义是在编译阶段检查类型
 标识符：用户自定义的标识符中 （1）不能连续出现两个下划线
                              （2）不能以下划线紧连大写字母开头
                              （3）定义在函数体外的标识符不能以下划线开头

8.cout <<::reused <<endl     
当全局变量和局部变量都定义了reused变量时，显示使用全局变量
当作用域操作符（：：）左侧为空时，向全局作用域发出请求获取作用域操作符右侧名字对应的变量

9.引用：为对象起的另一个名字（引用不是对象）
int ival = 1024;
int &refval = ival;      //refval指向ival（是ival的另一个名字）
int &refal2;            //错误，引用必须初始化
int &refal3 = 10；      //错误，引用类型的初始值必须是一个对象
double dval = 3.14;   
int &refval4 = dval;    //错误，需是int,类型要匹配

10.（1）int *p = &val    //p存放变量val的地址，或者说p是指向val的指针
语句中，&和*用于组成复合类型；在表达式中，他们的角色又转变成运算符
空指针     *p = nullptr / 0 / NULL;
（2）把int变量直接赋给指针是错误的操作，即使int变量的值恰好等于0也不行
int zero = 0;  
pi = zero;           //错误，不能把int变量直接赋值给指针

