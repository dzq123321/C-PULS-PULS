#if 0
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<Limits.h>
using namespace std;

//������ת��Ϊ�ַ���
//c����   _itoa(_atoi),sprintf()->()����ʽ��������д���ַ�����
//��������ת����ֵ���Ǵ����s2�У����´�ӡs2
//void main()
//{
	//int n = 123456789;
	//char s1[31];
	//_itoa(n, s1, 10);
	//printf("%s\n", s1);
	//n = atoi(s1);
	//printf("%d\n", n);
	//char s2[31];
	//sprintf(s2, "%d", n);//
	//printf("%s\n", s2);
	//char s2[200] = {0};
	//float n2 = 123456789.200;
	//sprintf(s2, "%f", n2);//��ʽ�����ݣ���n���ַ������뵽s2��
	//printf("%s\n", s2);
	//char s3[32];
	//printf("%s\n", s2);
	//_itoa(n2, s3, 10);
	//printf("%s\n",s3);
//}
//����c��������ת��ʱ������Ԥ��һ��buffer�ַ��ռ��ţ��ռ䲻�ý綨
//��C++�У�����ʹ��stringstream��������ܿ������⡣ 
//sstream �ײ��Ϊά��һ��string�࣬��η�����Ҫ��.clear()���������
//��clear()��������ײ��string,��Ҫ����ײ�����Ҫ.str(),���������ʹ��
//void main() {
//	double a = 1239.183;
//	string s;
//	stringstream b;
//	b << a;
//	b >> s;
//	cout << s<<endl;
//	b.clear();
//	b.str("");
//	double d = 965.4355;
//	b << d;
//	b >> s;
//	cout << s << endl;
//	string value = b.str();
//		cout << value << endl;
//}
/**/
//void main()
//{
//	stringstream sstream;
//	// ������ַ������� sstream ��  
//	sstream << "first" << " " << "string,"; 
//	sstream << " second string";  
//	cout << "strResult is: " << sstream.str() << endl;
//	// ��� sstream 
//	   sstream.str("");  
//	sstream << "third string";   
//	cout << "After clear, strResult is: " << sstream.str() << endl;
//}


//c++�����������
//�ı�д��
//void main()
//{
//	int ar[] = { 34,45,56,2,434,43,76,87,12 };
//	int n = sizeof(ar) / sizeof(int);
//	FILE *fp = fopen("Test.txt", "w");
//	if (NULL == fp)
//	{
//		cerr << "open Test.txt failed ." << endl;
//		exit(1);
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		fprintf(fp, "%d", ar[i]);
//	}
//	fclose(fp);
//	return;
//}
//���ı�����
//void main()
//{
//	FILE *fp = fopen("Test.txt", "r");
//	if (NULL == fp)
//	{
//		cerr << "open Test.txt failed ." << endl;
//		exit(1);
//	}
//	int ar[10];
//	for (int i = 0; i < 10; i++)
//	{
//		fscanf(fp, "%d", &ar[i]);
//	}
//	fclose(fp);
//	return;
//}
//�Զ�����д��
//void main()
//{
//	int ar[] = { 34,45,56,2,434,43,76,87,12 };
//	int n = sizeof(ar) / sizeof(int);
//	FILE *fp = fopen("Test.txt", "wb");
//	if (NULL == fp)
//	{
//		cerr << "open Test.txt failed ." << endl;
//		exit(1);
//	}
//	fwrite(ar, sizeof(int), n, fp);
//	fclose(fp);
//	return;
//}

//�Զ����ƶ�
//void main()
//{
//	FILE *fp = fopen("Test.txt", "wb");
//	if (NULL == fp)
//	{
//		cerr << "open Test.txt failed. " << endl;
//		exit(1);
//	}
//	int ar[10];
//	fread(ar, sizeof(int), 10, fp);
//	fclose(fp);
//	return;
//}


//c++�ı�����
//void main()
//{
//	int ar[] = { 12,23,45,56,67 };
//	int n = sizeof(ar) / sizeof(int);
//	ofstream ofile;
//	ofile.open("Test4.txt", ios::out);//fopen("test.txt","w");
//	for (int i = 0; i < n; i++)
//	{
//		ofile << ar[i] << " ";
//	}
//	ofile.close();
//	return;
//}

//�ı�д��
//void main() {
//	int ar[6];
//	ifstream ifile;
//	ifile.open("Test4.txt", ios::in);
//	for (int i = 0; i < 6; i++)
//	{
//		ifile >> ar[i];
//	}
//	ifile.close;
//	return;
//
//}

//�Զ�����д��
//void main()
//{
//	int ar[] = { 12,23,45,56,67 };
//	int n = sizeof(ar) / sizeof(int);
//	ofstream ofile;
//	ofile.open("Test4.txt ", ios::out | ios::binary);
//	ofile.write((const char* )ar, sizeof(int)*n);
//	ofile.close();
//	return;
//}
//�����ƶ���
//void main()
//{
//	int ar[6];
//	ifstream ifile;
//	ifile.open("Test4.txt",ios::in | ios::binary);
//	ifile.read((char*)ar, sizeof(int)*6);
//	ifile.close();
//	return;
//}
//int main()
//{
//	int n = 3;
//	int sum = (int)pow(n, 2) + n;
//	cout << (sum >> 1) << endl;  //(����һλ��ʾ�������2)
//	cout << (2 && 3) << endl;
//}
//int main() {
//	int s = 0, a = 0, b = 2, c = 3, d = 4;
//	s = a++ && ++b && d++; //1  2 3 4  (a=0��λ��&&��Ϊ0,Ϊ�����Գ��򲻻��������)
//	//s = a++||++b||d++;   // 1 3  3 4
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
//	cout << s << endl;
//	//int i = 0, j = 0, k = 0;
//	//(++i) || ++j && ++k;
//	// �� && �� || ��������ʱ���������ʽ������ || ���ʽ(++i=1)���ݻ�����ʣ�ֱ��ֹͣ���㣨�߼�������1ֹͣ���㣬�߼�������0ֹͣ���㣩
//	//printf("i= %d\n j= %d\n k= %d\n", i, j, k);
//	return 0; 
//}
//int convert(int y, int m, int d)
//{
//	int ping[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	int run[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//	int flag = 0;
//	int res = 0;
//	if (((y % 4 == 0) && (y % 100) != 0) || (y % 400 == 0))
//		flag = 1;
//	for (int i = 0; i < m - 1; i++)
//	{
//		if (flag == 0)//ƽ��
//		{
//			res += ping[i];
//		}
//		else
//			res += run[i];
//	}
//	return (res + d);
//}
//int main()
//{
//	int y, m, d;
//	int res = 0;
//	while (cin >> y >> m >> d)
//	{
//		cout << convert(y, m, d) << endl;
//	}
//}
class Solution {
		public:
			int StrToInt(string str) {
				int LIMIT = INT_MIN;
				int LIMIT2 = LIMIT/10;
				if (str.size() == 0)
					return 0;
				const char*tmp = str.c_str();
				int i = 0;
				int flag = 0;
				int res = 0;
				if (*tmp == '-')
				{
					flag = 1;
 				  tmp++;
				}
				else if ((*tmp == '+'))
					tmp++;
				while ((*tmp) != '\0')
				{
					if (*tmp >= '0'&&*tmp <= '9')//-2^31 - 2^31-1    
					{
						res = res * 10 + (*tmp - '0');
			
						if (i==9)
						{
							if ((res / 10) > -LIMIT2)
								return 0;
							if (flag == 1 && res == INT_MIN)
								return INT_MIN;
							else if(res<=0)
							return 0;
						}
						i++;
						tmp++;
					}
					else
						return 0;
				}
				if (flag == 1)
				{
					return -res;
				}
				return res;
			}
};
void main()
{
	string s1 = "2147483647";
	Solution s;
	int t = s.StrToInt(s1);
	cout<< s.StrToInt(s1) << endl;
}
#endif