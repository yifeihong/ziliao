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

11.  assert 
宏的原型定义在 assert.h 中，其作用是如果它的条件返回错误，则终止程序执行。
#include "assert.h" 
void assert( int expression );
assert 的作用是现计算表达式 expression ，如果其值为假（即为0），那么它先向 stderr 打印一条出错信息,然后通过调用 abort 来终止程序运行。
使用 assert 的缺点是，频繁的调用会极大的影响程序的性能，增加额外的开销
每个assert只检验一个条件,因为同时检验多个条件时,如果断言失败,无法直观的判断是哪个条件失败

12. （1）typedef  oldname  newname
  （2）typedef  struct  stu{
          char  name[20];
          int  age;
          char  sex;
  } STU;
STU是struct  stu的别名，可以用STU定义结构体变量
   （3）typedef  char  ARRAY20[20];    ARRAY20是char [20]的别名
        ARRAY20  a1,  a2,  a3;     等价于 char  a1[20],  a2[20],  a3[20];
   （4）*_t是typedef定义的表示标志，是结构的一种标注。即我们所看到的 uint8_t、uint16_t、uint32_t都不是新的数据类型，而是通过typedef给类型起的别名。

13. typedef enum
（1）typedef enum则是用来定义一个数据类型，那么该类型的变量值只能在enum定义的范围内取
   Typedef  enum  {jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec}  Day;
   Day  a, b;
定义的枚举类型 a ,b的取值只能是那12个变量中的一个，如果赋予了其他的变量，编译器就会报错

14.更改vscode字体大小：
文件 – 首选项 – 设置 – 常用设置-（font size）

15. __attribute__ ((packed))
 struct my_packed_struct
{
char c;
int i;
}__attribute__ ((__packed__));
__attribute__ ((packed)) 的作用就是告诉编译器取消结构在编译过程中的优化对齐,按照实际占用字节数进行对齐，是GCC特有的语法。这个功能是跟操作系统没关系，跟编译器有关，gcc编译器不是紧凑模式的，我在windows下，用vc的编译器也不是紧凑的，用tc的编译器就是紧凑的。
GNU C的一大特色就是__attribute__机制。__attribute__可以设置函数属性（Function Attribute）、变量属性（Variable Attribute）和类型属性（Type Attribute）。
__attribute__书写特征是：__attribute__前后都有两个下划线，并且后面会紧跟一对括弧，括弧里面是相应的__attribute__参数

16.封装
（1）封装的意义
  1）将属性和行为作为一个整体，表现生活中的事物 
2）将属性和行为加以权限控制
封装的意义一：
将属性和行为作为一个整体，用来表现生活中的事物，封装一个圆类，求圆的周长

const double PI = 3.14;       //圆周率
class Circle           //class代表设计一个类，后面跟着的是类名
{
public:            //访问权限 公共的权限
int m_r;      //属性  半径
double calculateZC()    //行为  获取到圆的周长
{
return 2 * PI * m_r;       //获取圆的周长
}
};
int main() {
Circle c1;   //通过圆类，创建圆的对象  c1就是一个具体的圆
c1.m_r = 10;   //给圆对象的半径 进行赋值操作
cout << "圆的周长为： " << c1.calculateZC() << endl;
system("pause");
return 0;
} 
封装意义二： 
类在设计时，可以把属性和行为放在不同的权限下，加以控制
访问权限有三种：  1. public 公共权限         类内、类外都可以访问
2. protected 保护权限      类内可以访问，类外不可以
3. private 私有权限        类内可以访问，类外不可以
class Person 
{ 
public: 
string m_Name;    //姓名 公共权限
protected: 
string m_Car;   //汽车 保护权限
private: 
int m_Password;    //银行卡密码 私有权限
public: 
void func() 
{  
m_Name = "张三";
m_Car = "拖拉机"; 
m_Password = 123456; 
} 
}; 
int main() 
{    Person p;
 p.m_Name = "李四";
 //p.m_Car = "奔驰";     //保护权限类外访问不到
//p.m_Password = 123;     //私有权限类外访问不到
system("pause");
 return 0; 
}
（2）在C++中 struct和class唯一的区别就在于默认的访问权限不同 
区别： struct   默认权限为公共 
class   默认权限为私有

17.std::shared_ptr的主要作用如下：
（1）智能指针主要的用途就是方便资源的管理，自动释放没有指针引用的资源。
（2）使用引用计数来标识是否有多余指针指向该资源。(注意，shart_ptr本身指针会占1个引用)
（3）可以用shared_ptr.use_count()函数查看这个智能指针的引用计数,一旦最后一个这样的指针被销毁，也就是一旦某个对象的引用计数变为0，这个对象会被自动删除

18.auto：
（1）C++11中，标准委员会赋予了auto全新的含义即：auto不再是一个存储类型指示符，而是作为一个新的类型 指示符来指示编译器，auto声明的变量必须由编译器在编译时期推导而得。
（2）使用auto定义变量时必须对其进行初始化，在编译阶段编译器需要根据初始化表达式来推导auto的实际类型。因此auto并非是一种“类型”的声明，而是一个类型声明时的“占位符”，编译器在编译期会将auto替换为变量实际的类型
（3）用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&
(4) 当在同一行声明多个变量时，这些变量必须是相同的类型, auto不能作为函数的参数, auto不能直接用来声明数组
auto b = a;      //b为int
auto c = 'a';     //c为char

19.size_t 
（若是win64则是无符号long  long，否则为无符号整型）
是一些C/C++标准在stddef.h中定义的，size_t 类型表示C中任何对象所能达到的最大长度，它是无符号整数。
它是为了方便系统之间的移植而定义的，不同的系统上，定义size_t 可能不一样。size_t在32位系统上定义为 unsigned int，也就是32位无符号整型。在64位系统上定义为 unsigned long ，也就是64位无符号整形。size_t 的目的是提供一种可移植的方法来声明与系统中可寻址的内存区域一致的长度。
size_t 在数组下标和内存管理函数之类的地方广泛使用。例如，size_t 用做sizeof 操作符的返回值类型，同时也是很多函数的参数类型，包括malloc 和strlen。
在声明诸如字符数或者数组索引这样的长度变量时用size_t 是好的做法。它经常用于循环计数器、数组索引，有时候还用在指针算术运算上。size_t 的声明是实现相关的。它出现在一个或多个标准头文件中，比如stdio.h 和stblib.h

20.namespace
  C++中namespace关键字定义了一个declarative region(声明区域)，所以在一个namespace中声明的标志符和其他namespace中声明的同名标志符是没有名字冲突的
namespace  exp1
{
namespace exp2
{
    int a,b;
}
int c, d;
}
访问的方法三种:
（1）exp1::exp2::a
这种方法最为直观，但只允许单次访问，也就是说我们如果要多次使用，每次都必须用这么长的一段来表示参数a
（2）using  exp1::exp2::a;     （using  declaration申明局部变量与namespace 中的原有成员相同时会报错）
将该成员放入当前的位置。在后面使用中即可直接访问该成员
（3）using  namespace  exp1;    （using directive  申明局部变量与namespace 中的原有成员相同时，不会报错，而是新的声明会覆盖namespace中的成员）

21.g_strdup_printf
sfilename = g_strdup_printf("arm.core%d.%s.txt", thread_id, filename);
g_strdup_printf是一个和sprintf差不多的函数，但是 g_strdup_printf更安全和智能，并且在释放的时候也只能用 g_free ，没必要像sprintf()一样创建和指定一个缓冲区，GLib将这些自动做了
（1）sprintf(s, "%d", 123);    // 产生"123"
（2）sprintf(s, "%8d%8d", 123, 4567);    // 产生："    123    4567"
（3）sprintf(s, "%10.3f", 3.1415626);      // 产生："     3.142″ （总宽度是10，3位小数）
（4）sprintf 能够一次连接多个字符串（自然也可以同时在它们中间插入别的内容）
char *who = "I";
char *whom = "52PHP";
sprintf(s, "%s love %s.", who, whom);   // 产生："I love 52PHP. "
（5） char a1[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
char a2[] = {'H', 'I', 'J', 'K', 'L', 'M', 'N'};
sprintf(s, "%.7s%.7s", a1, a2);    // 产生："ABCDEFGHIJKLMN"
这可以类比打印浮点数的“%m.nf”，在“%m.ns”中，m表示占用宽度（字符串长度不足时补空格，超出了则按照实际宽度打印），n才表示从相应的字符串中最多取用的字符数。通常在打印字符串时m没什么大用，还是点号后面的n用的多
（6）sprintf 返回了本次函数调用最终打印到字符缓冲区中的字符数目，snprintf() 的返回值是欲写入的字符串长度，而不是实际写入的字符串度。如：
#include <stdio.h>
 
int main(int argc, char **argv)
{
    char  test[8];
    int  ret = snprintf(test, 5, "1234567890");    //返回值是”1234567890”的长度
    printf("%d|%s\n", ret, test);
 
    return 0;
}
输出： 10|1234

22.fprintf(sfile, "%s", record);      
//sfile是打开文件的指针，将record的内容以字符串格式写入打开文件
     
最终gz.txt中写入了10,a,12

23.虚函数、构造函数、析构函数
（1）虚函数的定义
虚函数就是在基类中被关键字 virtual 说明，并在派生类中重新定义的函数。
虚函数的作用是允许在派生类中重新定义与基类同名的函数，并且可以通过基类指针或引用来访问基类和派生类中的同名函数。
虚函数的定义是在基类中进行的，它是在基类中在那些需要定义为虚函数的成员函数的声明中冠以关键字 virtual 。定义虚函数的方法如下：
virtual 函数类型 函数名(形参表)  {
	        函数体；
}
在基类中的某个成员函数被声明为虚函数后，此虚函数就可以在一个或多个派生类中被重新定义。在派生类中重新定义时，其函数原型，包括函数类型、函数名、参数个数、参数类型的顺序，都必须与基类中的原型完全相同。

（2）纯虚函数
语法：virtual 返回值类型 函数名(参数列表)=0，当类中有了纯虚函数，这个类也称为抽象类。抽象类特点:无法实例化对象，子类必须重写抽象类中的纯虚函数，否则也属于抽象类。

（3）虚析构函数
在 C++ 中，不能声明虚构造函数，但是可以声明虚析构函数。
对于虚析构，就是在析构函数前加virtual关键字
防止内存泄露，定义一个基类的指针p，在delete p时，如果基类的析构函数是虚函数，这时只会看p所赋值的对象，如果p赋值的对象是派生类的对象，就会调用派生类的析构函数（毫无疑问，在这之前也会先调用基类的构造函数，在调用派生类的构造函数，然后调用派生类的析构函数，基类的析构函数，所谓先构造的后释放）；如果p赋值的对象是基类的对象，就会调用基类的析构函数，这样就不会造成内存泄露。
如果基类的析构函数不是虚函数，在delete p时，调用析构函数时，只会看指针的数据类型，而不会去看赋值的对象，这样就会造成内存泄露。

（4）构造函数：
主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用
构造函数语法： 类名(){} 
1）. 构造函数，没有返回值也不写void 
2）. 函数名称与类名相同 
3）. 构造函数可以有参数，因此可以发生重载 
4）. 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次

（5）析构函数：
主要作用在于对象销毁前系统自动调用，执行一些清理工作。
析构函数语法： ~类名(){} 
1. 析构函数，没有返回值也不写void 
2. 函数名称与类名相同,在名称前加上符号 ~ 
3. 析构函数不可以有参数，因此不可以发生重载 
4. 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次

24.（1）重写(Override)概念  （外壳不变，核心重写）
重写是子类对父类的允许访问的方法的实现过程进行重新编写, 返回值和形参都不能改变。即外壳不变，核心重写！
重写的好处在于子类可以根据需要，定义特定于自己的行为。 也就是说子类能够根据需要实现父类的方法。
重写方法不能抛出新的检查异常或者比被重写方法申明更加宽泛的异常。例如： 父类的一个方法申明了一个检查异常 IOException，但是在重写这个方法的时候不能抛出 Exception 异常，因为 Exception 是 IOException 的父类，只能抛出 IOException 的子类异常。
（2）重载   （外壳变，核心不变）
从简单说，就是函数或者方法有相同的名称，但是参数列表不相同的情形，这样的同名不同参数的函数或者方法之间，互相称之为重载函数或者重载方法。在Java中同一个类中的2个或2个以上的方法可以有同一个名字，只要它们的参数声明不同即可。这种情况下，该方法就被称为重载，这个过程称为方法重载
方法重载的主要好处就是不用为了对不同的参数类型或参数个数，而写多个函数。多个函数用同一个名字，但参数表，即参数的个数或(和)数据类型可以不同，调用的时候，虽然方法名字相同，但根据参数表可以自动调用对应的函数
    重载的最直接作用是方便了程序员可以根据不同的参数个数，顺序，类型，自动匹配方法，减少写过个函数名或方法名的重复步骤

25.（1） 继承：
如果一个类A继承于另一个类B，那么将A称做派生类或者子类，将B称作基类或者父类,继承可以让子类具有父类的各种变量和函数，所以不需要在进行编写父类的代码，即父类的成员（变量、函数）都会变成子类的一部分。成员函数存在代码段中
（2）继承的语法：class 子类 ： 继承方式 父类
    （3）继承方式一共有三种：
    1）公共继承(public)    class A : public B
       父类(B)中的公共权限和保护权限的内容继承到子类(A)中后，其权限不变，原来是保护在子类中也是保护，原来是公共在子类中也是公共。父类中的私有权限内容，子类虽然继承了，但是无访问权限
    2）保护继承(protected)    class A : protected B
       父类(B)中的公共权限和保护权限的内容继承到子类(A)中后，无论这些内容在父类中是公共还是保护权限，到子类中全部变为保护权限。父类中的私有权限内容，子类虽然继承了，但是无访问权限
    3）私有继承(private)     class A : private B
       父类(B)中的公共权限和保护权限的内容继承到子类(A)中后，无论这些内容在父类中是公共还是保护权限，到子类中全部变为私有权限。父类中的私有权限内容，子类虽然继承了，但是无访问权限

26.（1）fwrite
 size_t   fwrite(const void* buffer,  size_t size,  size_t count,  FILE* stream);
将缓冲区buffer的内容写入stream指向的文件，共写count组数据,每组数据有size个字节
注意：这个函数以二进制形式对文件进行操作，不局限于文本文件
返回值：返回实际写入的数据块数目
1）buffer：是一个指针，对fwrite来说，是要输出数据的地址；
2）size：要写入内容的单字节数；
3）count:要进行写入size字节的数据项的个数；
4）stream:目标文件指针；
5）返回实际写入的数据项个数count。
说明：
写入到文件的哪里？ 这个与文件的打开模式有关，如果是w+，则是从file pointer指向的地址开始写，替换掉之后的内容，文件的长度可以不变，stream的位置移动count个数；如果是a+，则从文件的末尾开始添加，文件长度加大。
fseek对此函数有作用，但是fwrite[1]函数写到用户空间缓冲区，并未同步到文件中，所以修改后要将内存与文件同步可以用fflush（FILE *fp）函数同步。
（2）fopen
FILE * fopen(const char * path,const char * mode);
参数path字符串包含欲打开的文件路径及文件名，参数mode字符串则代表着流形态。
文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开失败则返回NULL，并把错误代码存在errno 中

27.初始化：
int  a = 0;
int  a = {0};
int  a{0};	
int  a(0);       （都可以把int型变量a初始化为0；）
  C++提供了不同的初始化方式，大多数情况下这些初始化方式可以相互等价地使用，例外情况有：
  （1）使用拷贝初始化（即使用=）时，只能提供一个初始值
  （2）如果提供的时一个类内初始值（创建对象时，类内初始值将用于初始化数据成员），则只能使用拷贝初始化或使用花括号的形式初始化
  （3）如果提供的是初始元素值的列表，则只能把初始值都放在花括号里进行列表初始化，而不能放在圆括号里

28.vector:
必须包含适当的头文件：
#include<vector>
using std::vector;           //没有这个会报错

 （1） 表示对象的集合，因为“容纳着”其他对象，所以也常被称作容器
  vector<int>  ivec;       //ivec保存int类型的对象，初始状态为空
  vector<vector<string>>  file;      //元素是vector对象
  vector<string>  v1{“a”,”an”};     //初始值要放花括号里，不能用圆括号
  vector<int>  v1(10);     //v1有10个元素，每个值都是0
  vector<int>  v2{10};     //v2有一个值为10的元素
  vector<int>  v3(10，1);     //v3有10个元素，每个值都是1
  vector<int>  v4{10，1};     //v4有10，1两个元素
  v1.push_back(i);       //把i值放到v1尾端
//v1.emplace_back(i)  替换push_back()更好，很多时候少一次拷贝
  v.empty();             //如果v中不含有任何元素，返回真，否则返回假
  v.size();              //返回v中元素的个数
  v[n]                   //返回v中第n个位置上元素的引用
v1.assign(set.begin() , set.end())        //把set全部赋值给v1
  v1.assign(ls.begin() , ls.begin()+9)       //把ls的前九个赋值给v1
  v1.assign(10 , 7)                     //把10个7赋值给v1
 vector对象的下标从0开始计算，但是不能用下标添加元素

（2）for语句处理vector对象中的所有元素
  vector<int>  v{1,2,3,4,5};
  for  (auto  &i : v)         //遍历v中的每个元素，注意i是一个引用
  		i *= i;               //求元素值的平方
  for  (auto i : v)           //遍历v中的每个元素
        cout<<i<<” “;       //输出该元素
  第一个循环把控制变量i定义成引用类型，这样就能通过i给v的元素赋值，i的类型由auto关键字指定

（3）计算vector内对象的索引
   //以10分为一个分数段统计成绩的数量
vctor<unsigned>  scores(11,0);   //11个分数段，全部初始化为0
unsigned  grade;
while  (cin >> grade) {
if (grade <= 100)
     ++scores[grade/10];    //将对应分数段的计数值加1
}
注意：
   ++scores[grade/10];       //将对应分数段的计数值加1
   等价于：
   auto ind = grade/10;        //计算索引
   scores[ind] = scores[ind] + 1;    //索引到的值加1
（4）不能用下标形式添加元素
vector<int>  ivec;
for (decltype(ivec.size()) ix=0; ix!=10; ++ix)
    ivec[ix] = ix;       //错误，ivec不包含任何元素

for (decltype(ivec.size()) ix=0; ix!=10; ++ix)
        ivec.push_back(ix);      //正确，添加一个新元素。该元素的值是ix
注意：
vector对象（以及string对象）的下标运算符可用于访问已存在的元素，而不能用于添加元素
（5）decltype 类型指示符  ： 选择并返回操作数的数据类型
1）decltype(f())  sum = x;     //sum的类型就是函数f的返回类型
2）const  int  ci = 0 , &cj = ci ;
decltype(ci)  x = 0;            //x的类型是const  int
decitype(cj)  y = x;            //y的类型是const  int&, y绑定到变量x
decltype(cj)  x;               //错误：z是一个引用，必须初始化
3）int  i = 42, *p = &i, &r = i;
  decltype (r+0)  b;            //正确，结果是int,因此b是int型
decltype(*p)  c;             //错误，c是int&,必须初始化
4）decltype((i))  d;            //错误，d是int&,必须初始化
   decltype(i)  e;             //正确，e是一个未初始化的int
注意：
decltype((variable)) （注意是双层括号）的结果永远是引用，而decltype(variable)结果只有当variable本身就是一个引用时才是引用。

（6）vector 查找：
vector<int>::iterator result = find( L.begin( ), L.end( ), 3 ); //查找3
    if ( result == L.end( ) ) //没找到
        cout << "No" << endl;
    else //找到
        cout << "Yes" << endl;

（7）vector 排序
1）普通类型：int    string  等
   sort(v.begin() , v.end());
2) 自定义类型，按其中一个项排序
  sort(v.begin() , v.end() , comp)    //como是自己写的比较函数
例如： 
bool  comp(const  student &a, const  student &b){
	return  a.score < b.score;

29.new
（1）C++中利用new操作符在堆区开辟数据 
堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete
语法： new 数据类型 
利用new创建的数据，会返回该数据对应的类型的指针
（2）int  *a = new  int(10);       delete  a;        
创建、删除整型数据，整型数据是10，用的是（）
（3）int  *arr = new  int[10];      delete[]  arr;     
创建、删除整型数组，包含10个元素，用的是[],删除时delete后面也要加上[]
（4）int  *a = new  int[2]();
     创建一个包含两个整型元素的数组，且初始化为0
（5）int  *a = new  int[3]{10,2,}
     创建一个包含三个整型元素的数组，前两个初始化为10和2，即（10，2，0）

30.继承
（1）继承的好处：可以减少重复的代码
语法： class A : public B; 
A 类称为子类 或 派生类 
B 类称为父类 或 基类 
派生类中的成员，包含两大部分： 
一类是从基类继承过来的，一类是自己增加的成员。 
从基类继承过过来的表现其共性，而新增的成员体现了其个性。
（2）继承方式一共有三种： 公共继承 保护继承 私有继承
 
（保护等级取高的）
（3）继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
（4）当子类与父类出现同名的成员时：
1）子类对象可以直接访问到子类中同名成员 
2）子类对象加作用域可以访问到父类同名成员 
3）当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中 同名函数

31.shared_ptr 类
make_shared 函数：在动态内存中分配一个对象并初始化它，返回指向此对象的shared_ptr
（1）shared_ptr<T>  sp       //sp空智能指针，可以指向类型为T的对象

（2）shared_ptr<int>  p3 = make_shared<int>(42);  
//p3指向一个值为42的int的shared_ptr

（3）shared_ptr<string>  p4 = make_shared<string>(10,’9’);  
//p4指向一个值为“9999999999”的string

（4）shared_ptr<int>  p5 = make_shared<int>();
//p5指向一个值初始化的int，即值为0

（5）auto  p6 = make_shared<vector<string>>();
//p6指向一个动态分配的空vector<string>

（6）拷贝一个shared_ptr,计数器会递增
shared_ptr<T>p(q)
   //p是shared_ptr  q的拷贝，此操作会递增q中的计数器，p和q指向相同的对象

（7）shared_ptr赋予一个新值或是被销毁时，计数器会递减，一旦计数器变为0，就会自动释放自己所管理的对象
    auto  r = make_shared<int>(42);    //r指向的int只有一个引用者
r = q ;        //给r赋值，令他指向另一个地址，
            // 递增q指向的对象的引用计数，递减r原来指向的对象的引用计数
            //若r原来指向的对象已没有引用者，会自动释放

（8）shared_ptr的析构函数会递减它所指向的对象的引用计数，如果引用计数变为0，shared_ptr的析构函数就会销毁对象，并释放它占用的内存

32.SPtr<InsnFatRecord>  getInst()  const  { return inst; }    
（SPtr 是 shared_ptr的别名）

//返回InsnFatRecord类型的智能指针
//把整个函数修饰为const，意思是“函数体内不能对成员数据做任何改动”
 
（1）如果你声明这个类的一个const实例，那么它就只能调用有const修饰的函数， const对象只能调用const成员函数
（2）const对象的值不能被修改，在const成员函数中修改const对象数据成员的值是语法错误，在const函数中调用非const成员函数是语法错误
（3）关于Const函数的几点规则：
a.在类中被const声明的成员函数只能访问const成员函数,而非const函数可以访问任意的成员函数,包括const成员函数..
b.在类中被const声明的成员函数不可以修改对象的数据,不管对象是否具有const性质.它在编译时,以是否修改成员数据为依据,进行检查.
c.加上mutable修饰符的数据成员,对于任何情况下通过任何手段都可修改,自然此时的const成员函数是可以修改它的

33.成员函数的声明、定义
成员函数的声明必须在类的内部，它的定义既可以在类的内部也可以在类的外部

34.（1） Friend Classes（友元类）：
在一个类中指明其他的类（或者）函数能够直接访问该类中的private和protected成员。
你可以这样来指明：
friend  class  aClass;   
//（aClass类可以访问声明类中的private和protected成员）
注意：
friend在类中的声明可以在public、protected和private的任何一个控制域中，而不影响其效果。例如，如果你在protected域中有这样的声明，那么aClass类同样可以访问该类的private成员。

（2）Friend Functions（友元函数）
友元函数和友元类的作用是一样的，它允许一个函数不需要通过其public接口就能够访问到类中的private和protected成员变量。
你可以这样去声明：
friend  return_type  class_name::function(args);   
//（function(args)函数可以访问声明类中的private和protected成员）
（3）注意：
1）友元不具有相互性，只具有单项性，若类B是类A的友元，类A不一定是类B的友元，要看在类中是否有相应的声明
    2）友元不能被继承，B是A的友元类，C是B的子类，推不出C是A的友元
    3）友元不具有传递性，B是A的友元，C是B的友元，推不出C是A的友元

35.构造函数
（1）作用：定义了对象被初始化的方式，初始化类对象的数据成员，只要类的对象被创建，就会执行构造函数。
（2）构造函数的名字和类名相同，没有返回值，类可以包含多个构造函数，不同的构造函数之间必须在参数数量或参数类型上有所区别。
（3）构造函数不能被声明成const，构造函数完成初始化，const对象才取得“常量”属性，因此，构造函数在const对象的构造过程中可以向其写值。
（4）没写构造函数时，编译器会创建默认构造函数
     如果存在类内初始值，用它来初始化成员
     否则，默认初始化该成员。
（5）不能依赖默认构造函数的情况：
    1）我们定义了构造函数，除非再定义一个默认的构造函数，否则类将没有默认构造函数
2）默认构造函数可能执行错误操作，定义在块中的内置类型或复合类型（例如数组、指针）的对象被默认初始化，他们的值是未定义的
3）有时候编译器不能为某些类合成默认的构造函数（例如：类中包含一个其他类类型的成员，且这个成员的类型没有默认构造函数）
（6）struct PageRecord {	
    enum Type { Invalid, InstPage, PageTable, DataPage };
    Type type;
    uint32_t size;
    uint64_t pa, va;
uint8_t  *data;     // allocated with new operator  
PageRecord() : type(Invalid), data(nullptr) { }         //构造函数赋初值
    ~PageRecord() { if (data) delete data; }               //析构函数
};
注意：
PageRecord() : type(Invalid), data(nullptr) { }        
//构造函数 ：和{}之间的代码称为构造函数初始值列表，负责为新创建的对象的数据成员赋初值，每个名字后面紧跟括号括起来的（或者在花括号内的）成员初始值，不同成员的初始化通过逗号分隔开来。
（7）外部构造函数
class::class()   
    含义是定义class类的成员，它的名字是class，成员名和类名相同，所以它是一个构造函数
（8）有参构造函数创建对象：
     A  a(1);      //栈中分配
     A  b = A(1);      //栈中分配
     A*  C = new  A(1);     //堆中分配






















