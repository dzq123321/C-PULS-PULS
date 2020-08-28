1、计算机反码和补码

```
    计算机在存储时为什么存储的是补码？愿意在于计算机种，只有加法没有减法。
    例如：1 的源码是   00000000  00000000   00000000  00000001
         -1 的源码是   10000000  00000000   00000000  00000001
      我们知道 1-1是要等于0的，但如果我们源码相加，得到的是
                      10000000  00000000   00000000  00000010   =-2
        不能得到我们想要的结果0，但如果是补码的话
        正数的正反补相同
        1 的补码是   00000000  00000000   00000000  00000001
       -1 的补码是   111111111  111111111   111111111   111111111（负数的补码是反码+1，反码是符号位不变，其他的相反）补码取反加1等于源码
       补码相加      00000000  00000000   00000000  00000000
       
       
    -10  10000000  00000000   00000000   00001010
         111111111 111111111 111111111   11110101
          111111111 111111111 111111111   11110110
```

#### 2、子网掩码

```
子网掩码有两个功能：
1、查找路由 （因特网规定所有的网络必须使用子网掩码，如果不划分子网，则为默认网络号的大小），
2、子网划分（通过与子网掩码按位与可以找到子网的网络号）（划分子网增加了灵活性，减少了能够连接在网络上的主机数）
```

#### 3、虚函数的实现机制. 
```
虚函数是在类中应用的，主要是为了实现多态，在程序运行期间，如果类中有虚函数并实例化了一个对象，则这个对象的首部四位是一个指针，这是一个指针数组指针，一个指向指针数组的指针，这个指针数组就是我们所说的虚函数表，数组里面存放的是各个虚函数的地址（函数指针）。当有子类继承父类的时候，如果子类没有虚函数，则子类中存在一个和父类一样的虚表，如果子类存在虚函数并对父类的虚函数进行的重写，则父类相应位置的虚函数指针变为子类的虚函数指针。其他的按声明的顺序排列。
```
#### 4、结构体对齐
```
结构体需要字节对齐，vs默认的对齐数位8，linux为4字节对齐，
从结构体的第一个成员开始，每个成元需要对齐的字节数都是要对齐到对齐数的整数倍
对齐数是（它自身的大小和默认大小8中的最小值进行比较）
最后总大小需要是最大对齐数的整数倍
struct S
{
char c1;  //对齐数为1  所以为  0-》0   1
char c2;  //对齐数为1  偏移量为1 所以为  1-》1    1
int i;    //对齐数为4，偏移量为2，便宜量要为4的倍数，1+1+2，从第四个地址开始  所以为  4-》7 总的偏移量为8
}
offsetof  计算结构体元素距首地址的偏移量
自定义offsetof（他是一个宏）
#define   Offsetof(s,m)   size_t (( &((S*)0)->m))  
struct S
{
	char a;//0
	char b;//1
	int c;//4
}stu;
int main()
{
	printf("%d \n",Offsetof(struct S,a));
	printf("%d \n",Offsetof(struct S,b));
	printf("%d \n",Offsetof(struct S,c));
}
```
####5、Linux  c程序被处理的过程
```
一个c程序被处理的过程
(1) 预编译    gcc -E test.c  -o test.i
                     （删除注释，宏替换，头文件展开，条件编译）
(2)编译       gcc -S test.o  -o test.s
                                 （将c程序变为汇编语言）
(3)汇编        gcc -c test.s  -o test.o
                       （简化汇编语言变为二进制语言，还不能直接被计算器读取） （1,2,3统称编译）
(4)链接        (可执行程序)
静态链接 ：指程序在编译链接时，把库文件的代码全部加入到可执行文件中，因此生成的文件比较大，但在运行时不再需要库文件，运行得比较快，一般以" .a "为后缀
动态链接： 指程序在编译链接时，没有把库文件的代码全部加入到可执行文件中，而是在程序执行时链接文件到加载库，这样节省了系统的开销，一般以 " .so "为后缀.
gcc默认动态链接 （不能独立运行，需要加载库）
 vim  编辑器
gcc  编译器（编译完默认的是release模式）所以无法直接调试
gbd  调试器      （使用方法： 先gcc test.c -o  mytest.c  -g     在gdb mytest.c）
```

#### 6、inline函数

```
1、inline函数主要是增加编译器运行的效率，主要适合那些体积小，但又需要经常调用的函数。
2、inline函数原理就是在编译期间就将函数内嵌到程序中，而普通函数是只有在需要使用的时候才调用。所以有inline的函数都比较大。
3、inline不是用户想使用就使用，还是要看编译器是怎么判断的。
4、类内定义的成员方法默认是inline的，而如果想在类内声明，类外定义，在类外定义的时候需要加inline关键字（也就是说在inline必须在函数定义处加，而不能在函数声明的加）。
5、inline和宏类似，但比宏安全
```

#### 7、main函数之前可以执行的操作

```
1、全局(静态)的变量，全局(静态)的对象的中构造函数和拷贝构造函数。这是因为全局变量和静态变量的生命周期是程序运行期一直存在。
2、gcc中用_attribute_关键字修饰的constructor/destructor._attribute_是修改属性的，constructor属性设置函数在所有函数之前执行，destructor设置函数在所有函数退出后执行。
```

#### 8、HTTPS为什么安全? 

```
（总体来说，是因为HTTPS对HTTP报文的数据进行了加密）我们知道HTTP是一种明文协议，客户或服务器发送的数据基本上实在网络上裸奔。可以想到对数据进行加密，这时我们引入HTTPS,他是在应用层和传输层之间的一种协议，主要用于对数据加密，有SSL和TLS,现在主要使用TLS协议，是要经过四次握手的协议，HTTPS是要经历两次加密，一次是非对称加密对数据加密，这时客户端要把非对称加密的报文发送到服务器段，又要使用非对称加密计算对对称加密的密钥进行加密。所以服务器端要向客户端发送非对称加密的公钥。
```

![https](E:\duzhiqiang\我的编程资料和代码\github\picture\https.png)

#### 9、.c与.cpp如何混合编程, 为什么需要extern “C”? 

```c++
我们都知道，在函数编译的时候系统会在底层从新为函数命名，而在c文件和cpp文件中文件的命名规则是不一样的，这是因为cpp文件存在函数重载的情况。
 一：//C++引用C函数的例子(C++调用C，extern "C" 的作用是：让C++连接器找调用函数的符号时采用C的方式 如)
//test.c
#include<stdio.h>
void mytest()
{
   printf("mytest in .c file ok\n");
}
//main.cpp
#include<iostream>
extern "C"
{
   void mytest();
}
int main()
{
      mytest();
      return 0;
}
二：//在C中引用C++函数(C调用C++，使用extern "C"则是告诉编译器把cpp文件中extern "C"定义的函数依照C的方式来编译封装接口，当然接口函数里面的C++语法还是按C++方式编译)
    //test.cpp
#include<iostream>
extern "C"
{
  void mytest()
  {
    printf("mytest in .cpp file ok\n");
  }
}
//main.c
#include<stdio.h>
void mytest();
int main()
{
   mytest();
   return 0;
}
但我们一般都是将函数定义在头文件，而无论是c或cPP实现，都要被c或CPP调用，所以在定义函数时，需要加入宏
分为两种情况，
1、在cpp中调用c的函数
#include<iostream>
#ifdef _CPPPLUSPLUS
extern "c" {
#endif // _CPPPLUSPLUS
#include"t5.h"
#include"t5.c"
	int add(int a, int b);
#ifdef _CPPPLUSPLUS
}
#endif // _CPPPLUSPLUS

#include<stdlib.h>
using namespace std;
int main()
{	
	cout << add(3, 4) << endl;
}

2、在c中调用cpp的函数
//t5.h
#ifdef __cplusplus
#include<stdio.h>
extern "C"
{
#endif
	void mytest();
#ifdef __cplusplus
}
#endif
//t6.cpp
#include"t5.h"
#include<iostream>
using namespace std;
	void mytest()
	{
		cout << "mytest in .cpp file ok\n" << endl;
	}

//t5.c
#include<stdio.h>
#include"t5.h"
void mytest();
int main()
{
	mytest();
	return 0;
}

```

#### 10、xss漏洞

```
xss漏洞是一种web上的漏洞，攻击者会在web页面上插入恶意的代码，而用户在加载页面时代码执行，从而达到恶意攻击的目的。之恶要是因为浏览器不会对服务器返回来的html代码进行安全性校验。危害：泄露cookie信息，篡改网页，控制客户服务器
```

#### 11、ICMP

```
ICMP这个协议是ip层的一个协议，主要是用于测试网络环境的，比如刚搭建了一个新的网络，由于IP协议是不可靠的协议，丢包后不会重传，所以使用ICMP协议，分为ICMP询问报文和ICMP差错控制报文。
ping(测试网络联通，应用层直接使用IP层)使用ICMP询问报文，回送请求和回送应答

/traceroute（跟踪一个分组从源点到终点的路径(使用无法交付的UDP报文， TTL=1，返回时间超出差错报文..TTL=2 返回时间超出差错报文...,  ...  ,到达终点，UDP无法交付，返回不可交付差错报文）
```

#### 12、FTP

```
文件传输协议，应用层的协议。
```

#### 13、硬链接和软连接

```
inode是存储文件的元信息的区域，比如文件的大小，user id,group id,...,每个文件都会对应一个inode节点
硬链接：（不占空间）硬连接不会产生真正的inode，也就是说不会再磁盘上开辟真正的空间。新建立的文件inode不变，只是inode的链接数+1，只有在inode=1时删除才是真正的删除。新建立的文件名和原始的文件名是平等的。
软连接：（开辟空间）链接产生新的inode,在磁盘上开辟真正的空间，存储的是原始文件名的根路径。原始文件名和新建立的文件名是主从关系，删除原始文件名，新的文件名还是存在但会指向一个无效链接。
```

#### 14、inode和文件描述符的区别

```
inode主要是用于操作系统查找磁盘上文件的索引，类似于目录，
文件描述符是用户打开文件产生的索引，用户利用文件描述符来操作这个文件，我们都知道每个进程都有一个pcb（进程控制块），在pcb中有一个filestruct,是个指针数组，类似于虚表，存放指向文件(inode)的指针,而对应的数组下标是文件描述符，所以可以多个用户打开一个文件，即一个文件描述符可以指向多个inode，
```

![inode](E:\duzhiqiang\我的编程资料和代码\github\picture\inode.png)

#### 15、死锁

```
指两个或两个以上的进程或线程因为竞争资源而处于的一种阻塞状态，分为两种情况：
#1#、一个线程需要加锁两次，在第一次调用完成之后，资源已经加锁，所以会进行等待别人释放锁，但锁又被自己占用，  则自己被挂起无法释放锁，造成死锁。
#2#、两个线程A获得锁1，B获得锁2，接下来线程A需要锁2，所以挂起等待B释放锁2，而B需要锁1，挂起等待线程A释放锁1，这时两个线程都处于等待状态而无法释放锁，造成死锁。
#3#、多线程环境下，A线程加锁，B线程等待，B线程fork子进程，子进程在获取锁时死锁
```

#### 16、锁的应用

```c++
1、mutex互斥锁  适合多线程环境下只能有一个线程操作临界资源，其他线程阻塞的情况。 与条件变量结合起来，在生产者消费者模型中应用
2、自旋锁  在mutex锁中，在其他线程得知临界资源被占有时，必须阻塞等待锁释放，随后系统通知这些线程，而自旋锁是自己以轮询的方式查看锁资源是否被释放，适合那些要求反应速度快的应用，比如中断。
4、读写锁 适合读的操作次数大于写的操作次数多的情况
```

#### 17、如何处理直播中的高并发问题

```
https://baijiahao.baidu.com/s?id=1642344491322172963&wfr=spider&for=pc
```

#### 18、get post

```
get 请求访问指定url资源的实体，服务器解析url后将资源返回给客户
1、get方法不安全，其把用户名和密码都包含URL中，而且有长度限制，只需请求一次，效率高
2、post方法安全，其把用户名和密码都包含数据区，无长度限制，需请求2次（一次header，一次data），效率低
GET历史参数保留在浏览器历史中。POST参数不会保存在浏览器历史中。
post 用于传输文件实体，虽然get也可以传输，但不常用
```

#### 19、深浅拷贝的两种写法

```
https://blog.csdn.net/W_J_F_/article/details/82717894
```

#### 20、用户态和内核态

```
用户态和内核态本质上是具有不同操作权限的程序的集合，内核态可以直接操作计算机的硬件，而用户态必须通过内核态的接口才能操作。用户态进入内核态三种方法：库函数调用  程序异常  外设中断
```

#### 21、指针和引用

```
1、引用必须初始化，而指针可以是NULL
2、引用等价于变量的别名，对sizeof或+1等价于求的是原始数据，但指针sizeof=4，+1加的是指针的步长
3、引用不能对数组进行引用，而指针可以由指针数组，函数指针。。。
4、引用不单独开辟空间，但指针有自己的空间
```

#### 22、引用

```
将 “ 引用 ” 作为函数返回值类型的格式、好处和需要遵守的规则 ? 
格式：类型标识符 & 函数名（形参列表及类型说明） { // 函数体 } 
好处：在内存中不产生被返回值的副本；（注意：正是因为这点原因，所以返回一个局部变量的引用是不可取的。因为随着该局部变量生存期的结束，相应的引用也会失效，产生 runtime error! 注意事项： 
（ 1 ）不能返回局部变量的引用。这条可以参照 Effective C++[1] 的 Item 31 。主要原因是局部变量会在函数返回后被销毁，因此被返回的引用就成为了 " 无所指 " 的引用，程序会进入未知状态。 
（ 2 ）不能返回函数内部 new 分配的内存的引用。这条可以参照 Effective C++[1] 的 Item 31 。虽然不存在局部变量的被动销毁问题，可对于这种情况（返回函数内部 new 分配内存的引用），又面临其它尴尬局面。例如，被函数返回的引用只是作为一个临时变量出现，而没有被赋予一个实际的变量，那么这个引用所指向的空间（由 new 分配）就无法释放，造成 memory leak 。 
（ 3 ）可以返回类成员的引用，但最好是 const 。这条原则可以参照 Effective C++[1] 的 Item 30 。主要原因是当对象的属性是与某种业务规则（ business rule ）相关联的时候，其赋值常常与某些其它属性或者对象的状态有关，因此有必要将赋值操作封装在一个业务规则当中。如果其它对象可以获得该属性的非常量引用（或指针），那么对该属性的单纯赋值就会破坏业务规则的完整性。 
（ 4 ）流操作符重载返回值申明为 “ 引用 ” 的作用： 
流操作符 << 和 >> ，这两个操作符常常希望被连续使用，例如： cout << "hello" << endl; 　因此这两个操作符的返回值应该是一个仍然支持这两个操作符的流引用。可选的其它方案包括：返回一个流对象和返回一个流对象指针。但是对于返回一个流对象，程序必须重新（拷贝）构造一个新的流对象，也就是说，连续的两个 << 操作符实际上是针对不同对象的！这无法让人接受。对于返回一个流指针则不能连续使用 << 操作符。因此，返回一个流对象引用是惟一选择。这个唯一选择很关键，它说明了引用的重要性以及无可替代性，也许这就是 C++ 语言中引入引用这个概念的原因吧。 赋值操作符 = 。这个操作符象流操作符一样，是可以连续使用的，例如： x = j = 10; 或者 (x=10)=100; 赋值操作符的返回值必须是一个左值，以便可以被继续赋值。因此引用成了这个操作符的惟一返回值选择。 
```

#### 23、进程间通信

```
管道是面向字节流的，和tcp类似，有可能读端读出的100个字节中写端是多次写入的。而且当fd关闭后，还在管道里的文件将会丢弃。
posix消息队列和system消息队列可以认为是消息链表，足够写权限的线程可往队列中放置消息，有足够读权限的
线程可从队列中取走消息。
posix消息队列和systemV消息队列主要如下差异：
1、一般来说posix的接口要比systemV的简单，但是systemV的可已移植性更好几乎所有的unix系统都支持。
2、对posix消息队列的读总是返回最高优先级的最早消息，对systemV消息队列的读则可以返回任意指定优先级的消息。
3、当往一个空队列放置一个消息时，posix消息队列允许产生一个信号或者启动一个线程，systemV消息队列则不提供类似的机制。
相比于管道，消息队列具有的优点是：1、消息队列是随内核的，只有调用函数删除了链表消息是真正的删除（）。2、可以给每个消息赋予更多的属性（数据长度，数据优先级）
posix消息队列限制 限定消息队列中的最大消息数和每个消息的最大字节数MQ_OPEN_MAX：一个进程能同时打开的消息队列的最大数目，POSIX要求为8，MQ_PRIO_MAX：消息的最大优先级，POSIX为32；

```

#### 24 sql语句执行很慢的原因

```
1、大多数情况下很正常，偶尔很慢，则有如下原因
(1)、数据库在刷新脏页，例如 redo log 写满了需要同步到磁盘。
(2)、执行的时候，遇到锁，如表锁、行锁。
2、这条 SQL 语句一直执行的很慢，则有如下原因。
(1)、没有用上索引：例如该字段没有索引；由于对字段进行运算、函数操作导致无法用索引。	
(2)、数据库选错了索引。
```

#### 25 mysql 事务 mysql锁机制

```mysql
create table testkey (
    -> id int primary key,
    -> a char(1));
alter table user9 add index(name); --加普通索引
insert into testkey (id ,a) values
    -> (1,a),(2,b),(3,c),(4,d),(5,a),(6,a),(7,c); 
 开启事务 begin;commit;
 设置事务隔离级别  set session transaction isolation level read uncommitted;（repeatabale read）
 脏读
 不可重复读  是1事务修改数据，2事务读数据前后两次不一样
  幻读  是1事务插入删除数据 2事务两次查询不一样  （mysql可重复读有可能发生幻读现象，但innodb不会，加了间隙锁）
select @@tx_isolation;
////////////// read committed  下加锁/////////////////////////
MVCC实现：readview（针对select(不加锁)）和锁实现(update)
每行还存放的隐藏列  rowid transaction_id(版本号)  roll_point（回滚指针）在undo_log日志中，有一个版本链，根据readview进行查找对应的版本,每次select会更新readview
读锁：（S锁）
select ... lock in shared mode 
(加读锁）允许其他事务获取读锁，但不能获取写锁)
写锁（X锁） 排他锁  delete insert update
select...for update
innodB下的读已提交如果锁的是不是索引列的行，其他行不会上锁
          可重复读如果锁的是不是索引列的行，其他行也会上锁，防止幻读现象       
mysiam
select 读锁
update insert delete 写锁

mysiam
///////表锁
lock tables t1 read;（读锁共享）
lock tables t1 write;（读写锁不能共存）
unlock tables; --解锁
innodb（使用行锁必须是索引查询）
索引查询加锁是行锁
非索引查询加锁是行锁，但实际上加的是表锁
悲观锁和乐观锁（概念性的锁）
悲观锁：假设事务会出错，提前加锁。行锁，表锁
乐观锁:出现问题再加锁（一般是加一个版本标识）没有加锁解锁开销，效率高
update user set name='123' where id =1 and version=1; 
意向锁：防止死锁
行锁粒度下，容易死锁。
已经存在了一个意向读锁，意向读锁开始匹配，
兼容规则：
兼容：加读锁。不产生死锁
不兼容：加读锁。产生死锁
///////////////////////////////////
MyIsam 支持全文索引，不支持事务和外键，B+树，只有表锁
innodb 不支持全文索引，支持事务，主要是面向在线事务处理方面的应用，特点是行锁设计，支持外键。innodb采用聚集索引的方式。当没有主键索引，唯一索引时会根据每行的一个隐藏列中的row_id，创建主索引 （有主索引和辅助索引之分）
memory
将数据放在内存中，如果数据库重启或者宕机，表数据会丢失。适合存储一些临时表，默认的是哈希索引，不是B+树索引。varchar()默认时按照char()存储的，浪费内存。不支持text和blob类型。如果数据中有text和blob类型，数据库会把这些数字转换到磁盘上。
/////
Archive
只支持insert和select操作，使用压缩算法将数据进行压缩，一般适合数据量大，查询少。存放日志数据
```

![1598598327671](E:\duzhiqiang\我的编程资料和代码\github\picture\存储引擎.png)

```
innodb  主索引（存储索引和对应行的数据）和辅助索引（存贮主索引的索引值）
MyIsAM  主索引（存储索引和对应行的地址，适合索引值不重复）和辅助索引（存存储索引和对应行的地址，适合索引值重复）
#2、索引的优化
那些应该建立索引：
1、查询多 2、主键外键 3、用于连接两个表的字段 4、经常需要排序的字段
5、经常需要查询的
那些不应该建立索引：
1、查询少 2、数值少 3、大文本字段  4、修改密集型
索引的注意事项：
短索引   使用where语句在有索引不要在使用order by
#3、组合索引(最左匹配原则)
```

ACID

```
原子性和持久性是靠日志系统实现
redo log重做日志  ：记录事务将要执行的每个操作
执行事物的时候，先写日志=》在刷新到磁盘
undo log未作日志  ： 保存事务执行过程的每个状态点
一致性和隔离性：是靠锁机制和mvcc实现的
innodb 支持事务 每一天sql就是一个事务
myisam  不支持事务，构建伪事务
```

```

```

触发器

```
事件发生，触发器触发，去执行另外一系列操作。
比如：统计一张表的个数
insert 到来，变量+1
delete -1
----
create trigger tri_name
tri_time（before/after）
tri_event (insert,delete update)
on tablename
for each row 
tri_stmt;--时机
==============================
insert 到来，之后变量+1 
设置
create trigger tri_1
after 
insert 
on test
for each row
begin
   set @count=@count+1;//；数据库的结束符，begin和end无法分离
   insert;
   delete;
end

所以无法直接处理
所以从新设置结束符号
delimiter $$ 结束符变为$$
delimiter ; 结束符修改回；
set @count=0;设置变量名

1、一张表，同类型的触发器最多存在一个
类型：tri_time+tri_event  6个
2、哪些事件可以触发触发器
insert  (load 大批量插入,replace(是等价于delete+insert/insert))
delete  delete
update update

```

存储函数（存储函数） 一系列特定的流程，写成存储过程

```
create proceduce pro_name(arg_list)
begin
  pro_stmt;
 end
 
 arg_list:参数列表  
 参数属性（in out inout） 参数名称 参数类型
 create proceduce pro_1(IN tmp int)
begin
 select tmp;
 tmp=100;
  select tmp;
 end
 也需要修改结束符
 
 使用 call调用 call pro_1(@tmp)
```



#### 项目：

```c++
1、项目介绍：
2、项目思路：
（1）本地搜索，封装成sql语句，执行sql语句
（2）监控，监控本地目录是否发生变化，若发生变化，则调整数据库的内容	
3、公共模块 ： Common.h
系统工具模块 ： Sysutil.h Sysutil.cpp
数据管理模块 ： DataManager.h DataManager.cpp
扫描管理模块 ： ScanManager.h ScanManager.cpp
系统驱动模块 ： DocFastSearchTool.cpp
4、everything在实现这个模块时，使用了扫描+监控的实现方式，这两种方式是一种互补的方式。
1. 文件系统监控是利用系统文件系统的接口可以监控某个目录下的文档变化，有点是效率高实
时性强，缺点是监控是实时的，如果在监控程序没有启动期间的，文档的变化无法获取。
2. 文件系统扫描是通过系统接口，遍历获取目录下的所有文档跟数据库中的文档进行对比，获
取文档变化，优点是监控程序启动前，变化的文档也能对比出来，缺点是性能低实时性不
强。
我们这里呢，为了简单一点，我们使用了简单粗暴的扫描。如有需要大家可以下去扩展实现可以
加上监控。
5、数据持久化我们使用了轻量级的一个数据库sqlite管理，使用sqlite需要去下载sqlite的源码或者源
码。
create table if not exists tb_doc (id INTEGER PRIMARY KEY autoincrement,
doc_path text, doc_name text, doc_name_pinyin text, doc_name_initials
text）；
6、中间逻辑层
everything没有实现拼音相关的搜索功能，实际中很多应用软件的搜索部分都实现了这个功能，
这里我们类比我们常用的软件qq实现了拼音全拼和拼音首字母并且高亮的功能。
7、拼音全拼搜索
存储时将文件名转换成一个拼音全拼存在数据库表的doc_name_pinyin字段中，搜索时也将关键
字转换成拼音，然后使用数据库的模糊匹配搜索
8、拼音首字母搜索
存储时将文件名转换成一个拼音首字母存在数据库表的doc_name_initials字段中，搜索时也将关
键字转换成拼音首字母，然后使用数据库的模糊匹配搜索
```

#### 实现

```
三、项目实现
1.系统工具模块实现
1.1 目录扫描
long _findfirst( char *filespec, struct _finddata_t *fileinfo );
int _findnext( long handle, struct _finddata_t *fileinfo );
int _findclose( long handle );

void DirectionList(const string &path, vector<string> &subdir, vector<string> &subfile)
{
	string _path = path;
	_path += "\\*.*";    //必须是_path,表示当前目录下的所有文件
	_finddata_t file;
	//_findfirst,搜索path路径下的第一个参数
	long handle = _findfirst(_path.c_str(), &file);
	if (handle == -1)
	{
		perror("_findfirst");
		return;
	}
	do
	{    //跳过隐藏文件
		if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)
			continue;
		//递归打印目录
		if (file.attrib&_A_SUBDIR)
		{
			//cout << "dir: "<<file.name << endl;
			//string tmp_path = path;
			//tmp_path += "\\";
			//tmp_path += file.name;
			//DirectionList(tmp_path);
			subdir.push_back(file.name);
		}
		else
			//cout << file.name << endl;
			subfile.push_back(file.name);
	} while (_findnext(handle, &file) == 0);
	_findclose(handle);
}
void main()
{
	const string &path = "E:\\duzhiqiang\\背包\\pack-master";
	vector<string> subdir;
	vector<string> subfile;
	DirectionList(path, subdir, subfile);
}
```

#### 汉字转拼音全拼/转首字母

```
网上搜索都有
static std::string ChineseConvertPinYinAllSpell(const std::string&
dest_chinese)
static std::string ChineseConvertPinYinInitials(const std::string&
name)
static void ColourPrintf(const char* str)
```

#### 数据库模块

```
#include "DataManager.h"
#include "sys.h"


SqliteManager::SqliteManager() :m_db(nullptr)
{}
SqliteManager::~SqliteManager()
{
	Close();
}
void SqliteManager::Open(const string &path)
{
	char *zErrMsg = 0;
	int rc = sqlite3_open(path.c_str(), &m_db);
	if (rc)
	{
		//fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_db));
		ERROR_LOG("Can't open database: %s", sqlite3_errmsg(m_db));
		exit(1);
	}
	else
	{
		//fprintf(stderr, "Open database successfully: \n");
		TRACE_LOG("Open database successfully")
	}
}
void SqliteManager::Close()
{
	if (m_db)
	{
		int rc = sqlite3_close(m_db);
		if (rc != SQLITE_OK)
		{
			//fprintf(stderr,"Close database failed: %s\n", sqlite3_errmsg(m_db));
			ERROR_LOG("Close database failed: %s", sqlite3_errmsg(m_db));
		}
		else
			//fprintf(stdout, "Close database successfully\n");
			TRACE_LOG("Close database successfully");
	}
}
void SqliteManager::ExecutedSql(const string &sql)
{
	char *zErrMsg = 0;
	int rc = sqlite3_exec(m_db, sql.c_str(), 0, 0, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		//fprintf(stderr, "SQL error: %s\n", zErrMsg);
		ERROR_LOG("SQL error: %s", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		//fprintf(stdout, "Table created successfully\n");
		TRACE_LOG("SQL executed successfully");
	}
}
void SqliteManager::GetResultTable(const string &sql, int &row, int &col, char **&ppRet)
{
	//char **result;
	//int row;
	//int col;
	char *zErrMsg = 0;
	int rc = sqlite3_get_table(m_db, sql.c_str(), &ppRet, &row, &col, &zErrMsg);//sqlite3_free_table
	if (rc != SQLITE_OK)
	{
		//fprintf(stderr, "Table created error: %s", zErrMsg);
		ERROR_LOG("Table created error: %s", zErrMsg)
			sqlite3_free(zErrMsg);
	}
	else
	{
		//fprintf(stdout, "Table created successfully\n");
		TRACE_LOG("Table created successfully");
	}
}



DataManager& DataManager::GetInstance()
{
	static DataManager inst;
	return inst;
}
DataManager::DataManager()
{
	m_dbmgr.Open(DOC_DB);//创建数据库
	InitSqlite();//创建表
}
DataManager::~DataManager()
{}
void DataManager::InitSqlite()
{
	//string sql=" create table if not exists DOC_TABLE(id integer primary key autoincrement, doc_name text, doc_path text)"
	//这样也行，但是就不能动态的改变我们想创建表的名字，可以通过sprintf
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "create table if not exists %s(id integer primary key autoincrement, doc_name text, doc_path text)", DOC_TABLE);
	//sprintf 将sql之后的字符串自规定的格式打印到sql中
	m_dbmgr.ExecutedSql(sql);
}
void DataManager::InsertDoc(const string &path, const string &doc)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "insert into %s values (null,'%s','%s')", DOC_TABLE,doc.c_str(),path.c_str());
	//sprintf 将sql之后的字符串自规定的格式打印到sql中
	m_dbmgr.ExecutedSql(sql);
}
void DataManager::GetDocs(const string &path, multiset<string> &docs)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "select doc_name from %s where doc_path='%s'", DOC_TABLE,path.c_str());
	//sprintf 将sql之后的字符串自规定的格式打印到sql中
	int row = 0, col = 0;
	char **ppRet = 0;
	m_dbmgr.GetResultTable(sql,row,col,ppRet);
	for (int i = 1; i <= row; ++i)
		docs.insert(ppRet[i]);
	//释放结果表
	sqlite3_free_table(ppRet);
}
void DataManager::DeleteDoc(const string &path, const string &doc)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "delete from %s where doc_name='%s' and doc_path='%s'", DOC_TABLE, doc.c_str(), path.c_str());
	m_dbmgr.ExecutedSql(sql);
	//////////////////删除目录下的文件
	string doc_path = path;
	doc_path += "\\";
	doc_path += doc;
	memset(sql, 0, SQL_BUFFER_SIZE);
	sprintf(sql, "delete from %s where doc_path like '%s%%'", DOC_TABLE, doc_path.c_str());
	m_dbmgr.ExecutedSql(sql);
}
void  DataManager::Search(const string &key, vector<pair<string, string>> &doc_path)
{
	char sql[SQL_BUFFER_SIZE] = { 0 };
	sprintf(sql, "select doc_name,doc_path from %s where doc_name like '%%%s%%'", DOC_TABLE, key.c_str());
	int row = 0, col = 0;
	char **ppRet = nullptr;
	m_dbmgr.GetResultTable(sql, row, col, ppRet);
	doc_path.clear();
	for (int i = 1; i <= row; ++i)
		doc_path.push_back(make_pair(ppRet[i*col], ppRet[i*col + 1]));
}
```

#### 扫描模块

```
#include "ScanManager.h"
#include "sys.h"

ScanManager::ScanManager()
{}
void ScanManager::StartScan(const string& path)
{
	while (1)
	{
		this_thread::sleep_for(chrono::seconds(3));
		ScanDirectory(path);
	}
}

ScanManager& ScanManager::CreateInstance(const string &path)
{
	static ScanManager inst;
	thread scan_thread(&StartScan, &inst, path);
	scan_thread.detach();
	return inst;
}

void ScanManager::ScanDirectory(const string &path)
{
		//扫描本地文件
	vector<string> local_files;  //本地文件
	vector<string> local_dirs; //本地目录
	DirectionList(path,  local_dirs, local_files);
	set<string> local_set;
	local_set.insert(local_files.begin(), local_files.end());
	local_set.insert(local_dirs.begin(), local_dirs.end());
	//扫描数据库文件系统
	multiset<string> db_set;
	DataManager &m_db = DataManager::GetInstance();
	m_db.GetDocs(path, db_set);
	//对比本地文件和数据库文件
	auto local_it = local_set.begin();
	auto db_it = db_set.begin();
	while (local_it != local_set.end() && db_it != db_set.end())
	{
		if (*local_it < *db_it)
		{
			//本地文件存在，数据库文件不存在，则数据库插入文件
			m_db.InsertDoc(path, *local_it);
			local_it++;
		}
		else if (*local_it > *db_it)
		{
			//本地文件不存在，数据库文件存在，则数据库删除文件
			m_db.DeleteDoc(path, *db_it);
			db_it++;
		}
		else
		{
			//本地文件存在，数据库文件存在，
			local_it++;
			db_it++;
		}
	}
	while (local_it != local_set.end())
	{
		// 本地文件存在，数据库文件不存在，则数据库插入文件
		m_db.InsertDoc(path, *local_it);
		local_it++;
	}
	while (db_it != db_set.end())
	{
		//本地文件不存在，数据库文件存在，则数据库删除文件
		m_db.DeleteDoc(path, *db_it);
		db_it++;
	}
	//递归遍历子目录
	//
	for (const auto &dir : local_dirs)
	{
		string dir_path = path;
		dir_path += "\\";
		dir_path += dir;
		ScanDirectory(dir_path);
	}

}


```

#### 多线程