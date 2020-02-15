#if 1
#include<iostream>
#include<string>
using namespace  std;
//string 对象的构建
//void main()
//{
//	string str1;
//	cout << "str1=" << str1 << endl;
//	const char *s = "Hello bit";
//	string str2(s);
//	cout << "str2=" << str2 << endl;
//	string str3("Hello bit");
//	cout << "str3=" << str3 << endl;
//	string str4(str3);  //浅拷贝
//	cout << "str4=" << str4 << endl;  //这里str2 str3 str4 str4 地址都不相同
//	string str5=str3;//浅拷贝
//	cout << "str5=" << str5 << endl;
//	string str6(10, 'acbq');  //这种方式只适合一个字符，当是字符串时，会发生截断，只打印后面的
//	cout << "str6=" << str6 << endl;
//	string str7 = "浅拷贝";
//	string str8 = str7;//浅拷贝
//	cout << "str8=" << str8 << endl;
//
//}
//string 类对象的容量操作
//void main()
//{
//	string str("figh..");
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.length() " << str.length() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;
//	str.reserve(100);
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;  //capacity=111 是一个比100大的数
//	str.reserve(2);//当是一个比原来的size=6 还小的数时，capacity不发生变化
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;  
//	str.resize(4);//改变长度
//	cout << str << endl;  //发生截断
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;
//	str.resize(10,'*');//源字符串长度不够，指定*来填充，无则默认0
//	cout << str << endl;  //发生截断
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;
//	str.clear();
//	cout << "str.length() " << str.length() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;  //使用clear不改变容量的大小
//	cout << "str.empty() " << str.empty() << endl;//判断字符串是否为空
//}
//void main()
//{
//	string str;
//	str.reserve(80);  //通过提前设置str的容量capacity，可以有效提高程序的效率，防止程序不停的从新计算开辟容量
//	cout << "str.capacity()= " << str.capacity() << endl;
//	for (int i = 0; i < 50 ; i++)
//	{
//		str += "bq";
//		cout << "str.capacity()= " << str.capacity() << endl;
//	}
//	cout << str << endl;
//}
//string 类对象的访问及遍历操作
//void main()
//{
//	string str = "hello world";
//	cout << str << endl;
//	for (int i = 0; i < str.size(); ++i)
//	{
//		cout << str[i] ;
//	}
//	cout << endl;
//	for (auto &ele : str)  //引用效率高并且可以改变元素的大小
//	{
//		if(ele == 'h')
//		 ele = 'H';
//		cout << ele;
//	}
//	cout << endl;
//	string::iterator  it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//	string:: reverse_iterator rit = str.rbegin();  //反向迭代器
//	while (rit != str.rend())
//	{
//		cout << *rit;
//		rit++;
//	}
//	cout << endl;
//}

//string类对象的修改操作
void main()
{
	string str;
	str+="hello ";   //+= 都可以
	str.append("world");  //append只能加字符串，不能加字符
	str.push_back('i');//只能是字符
	cout << str << endl;
	// c_str 返回c格式的字符串  因为我们用string创建的时类格式的字符串，不能用strlen这样c的函数
	//int i = strlen(str.c_str());
	int pos = str.find('i', 2);//find 查找字符串某个元素/或字符串的位置
	if (pos == string::npos)
	{
		cout << "不存在" << endl;
	}
	cout << pos << endl;
	 pos = str.find("worlp", 2);//find 查找字符串某个元素/或字符串的位置
	if (pos == string::npos)
	{
		cout << "不存在" << endl;
	}
	else
	cout << pos << endl;
	cout << str.rfind('e',2) << endl; //rfind 反向查找字符串某个元素的位置
	cout << str.substr(str.find('w'), str.size() - str.find('w')) << endl;
	//str.substr(int i,int j) 对于字符串str，从第i的位置开始截取j个字符，随后返回
	string sub("sdhki");   //find是完全匹配字符串，而以下四个是部分不匹配
	pos = str.find_first_of(sub);  //str中第一次出现sub字符串中字母的位置 0
	cout << pos << endl;
	pos = str.find_first_not_of(sub); //str中第一次没有出现sub字符串中字母的位置 1
	cout << pos << endl;
	pos = str.find_last_of(sub); // str中最后一次出现sub字符串中字母的位置 11
	cout << pos << endl;
	pos = str.find_last_not_of(sub);// str中最后一次没有出现sub字符串中字母的位置 9
	cout << pos << endl;

}

//void main()
//{
//	string s1 = "Hello";
//	string s2 = "world";
//	string s3 = s1 + s2;
//	cout << "s3 =" << s3 << endl;
//	bool f = s2 == s3;
//	cout << f << endl;
//	string s4;
//	//cin >> s4;  //   遇见空格就会刷新，不显示空格之后的内容  可以用getline(cin,s4)解决
//	getline(cin, s4);
//	cout << s4;
//}
#endif