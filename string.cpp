#if 1
#include<iostream>
#include<string>
using namespace  std;
//string ����Ĺ���
//void main()
//{
//	string str1;
//	cout << "str1=" << str1 << endl;
//	const char *s = "Hello bit";
//	string str2(s);
//	cout << "str2=" << str2 << endl;
//	string str3("Hello bit");
//	cout << "str3=" << str3 << endl;
//	string str4(str3);  //ǳ����
//	cout << "str4=" << str4 << endl;  //����str2 str3 str4 str4 ��ַ������ͬ
//	string str5=str3;//ǳ����
//	cout << "str5=" << str5 << endl;
//	string str6(10, 'acbq');  //���ַ�ʽֻ�ʺ�һ���ַ��������ַ���ʱ���ᷢ���ضϣ�ֻ��ӡ�����
//	cout << "str6=" << str6 << endl;
//	string str7 = "ǳ����";
//	string str8 = str7;//ǳ����
//	cout << "str8=" << str8 << endl;
//
//}
//string ��������������
//void main()
//{
//	string str("figh..");
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.length() " << str.length() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;
//	str.reserve(100);
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;  //capacity=111 ��һ����100�����
//	str.reserve(2);//����һ����ԭ����size=6 ��С����ʱ��capacity�������仯
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;  
//	str.resize(4);//�ı䳤��
//	cout << str << endl;  //�����ض�
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;
//	str.resize(10,'*');//Դ�ַ������Ȳ�����ָ��*����䣬����Ĭ��0
//	cout << str << endl;  //�����ض�
//	cout << "str.size() " << str.size() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;
//	str.clear();
//	cout << "str.length() " << str.length() << endl;
//	cout << "str.capacity() " << str.capacity() << endl;  //ʹ��clear���ı������Ĵ�С
//	cout << "str.empty() " << str.empty() << endl;//�ж��ַ����Ƿ�Ϊ��
//}
//void main()
//{
//	string str;
//	str.reserve(80);  //ͨ����ǰ����str������capacity��������Ч��߳����Ч�ʣ���ֹ����ͣ�Ĵ��¼��㿪������
//	cout << "str.capacity()= " << str.capacity() << endl;
//	for (int i = 0; i < 50 ; i++)
//	{
//		str += "bq";
//		cout << "str.capacity()= " << str.capacity() << endl;
//	}
//	cout << str << endl;
//}
//string �����ķ��ʼ���������
//void main()
//{
//	string str = "hello world";
//	cout << str << endl;
//	for (int i = 0; i < str.size(); ++i)
//	{
//		cout << str[i] ;
//	}
//	cout << endl;
//	for (auto &ele : str)  //����Ч�ʸ߲��ҿ��Ըı�Ԫ�صĴ�С
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
//	string:: reverse_iterator rit = str.rbegin();  //���������
//	while (rit != str.rend())
//	{
//		cout << *rit;
//		rit++;
//	}
//	cout << endl;
//}

//string�������޸Ĳ���
void main()
{
	string str;
	str+="hello ";   //+= ������
	str.append("world");  //appendֻ�ܼ��ַ��������ܼ��ַ�
	str.push_back('i');//ֻ�����ַ�
	cout << str << endl;
	// c_str ����c��ʽ���ַ���  ��Ϊ������string������ʱ���ʽ���ַ�����������strlen����c�ĺ���
	//int i = strlen(str.c_str());
	int pos = str.find('i', 2);//find �����ַ���ĳ��Ԫ��/���ַ�����λ��
	if (pos == string::npos)
	{
		cout << "������" << endl;
	}
	cout << pos << endl;
	 pos = str.find("worlp", 2);//find �����ַ���ĳ��Ԫ��/���ַ�����λ��
	if (pos == string::npos)
	{
		cout << "������" << endl;
	}
	else
	cout << pos << endl;
	cout << str.rfind('e',2) << endl; //rfind ��������ַ���ĳ��Ԫ�ص�λ��
	cout << str.substr(str.find('w'), str.size() - str.find('w')) << endl;
	//str.substr(int i,int j) �����ַ���str���ӵ�i��λ�ÿ�ʼ��ȡj���ַ�����󷵻�
	string sub("sdhki");   //find����ȫƥ���ַ������������ĸ��ǲ��ֲ�ƥ��
	pos = str.find_first_of(sub);  //str�е�һ�γ���sub�ַ�������ĸ��λ�� 0
	cout << pos << endl;
	pos = str.find_first_not_of(sub); //str�е�һ��û�г���sub�ַ�������ĸ��λ�� 1
	cout << pos << endl;
	pos = str.find_last_of(sub); // str�����һ�γ���sub�ַ�������ĸ��λ�� 11
	cout << pos << endl;
	pos = str.find_last_not_of(sub);// str�����һ��û�г���sub�ַ�������ĸ��λ�� 9
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
//	//cin >> s4;  //   �����ո�ͻ�ˢ�£�����ʾ�ո�֮�������  ������getline(cin,s4)���
//	getline(cin, s4);
//	cout << s4;
//}
#endif