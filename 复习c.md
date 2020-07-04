#### 1、计算机反码和补码

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

![https](E:\duzhiqiang\比特51c语言\github\picture\https.png)

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

![inode](E:\duzhiqiang\比特51c语言\github\picture\inode.png)

#### 15、死锁

```
指两个或两个以上的进程或线程因为竞争资源而处于的一种阻塞状态，分为两种情况：
1、一个线程需要加锁两次，在第一次调用完成之后，资源已经加锁，所以会进行等待别人释放锁，但锁又被自己占用，则自己被挂起无法释放锁，造成死锁。
2、两个线程A获得锁1，B获得锁2，接下来线程A需要锁2，所以挂起等待B释放锁2，而B需要锁1，挂起等待线程A释放锁1，这时两个线程都处于等待状态而无法释放锁，造成死锁。
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