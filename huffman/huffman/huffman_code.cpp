#if 0

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int weight[] = { 817,149,278,425,1270,223,202,609,15,77,403,241,675,751,193,10,599,633,906,278,46,489,651,23,654,79};
const int LENGTH = 26;

typedef struct {
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;


//2、select找出两个权值最小的字符

void Select(HuffmanTree HT, int cur, int &min1, int &min2) {
	min1 = min2 = 0;
	for (int i = 1; i < cur; ++i)
	{
		//略过已加入节点
		if (HT[i].parent != 0)
		{
			continue;
		}
		if(min1==0)
		   min1 = min2 = i;
		else {
			if ((HT[i].weight <= HT[min1].weight)) {
				min2 = min1;
				min1 = i;
			}
			else if (HT[i].weight < HT[min2].weight) {
				min2 = i;
			}
			else if (HT[i].weight > HT[min2].weight) {
				if (min1 == min2)
					min2 = i;
			}
		}
	}
}
//创建HuffmanTree

void CreateHuffmanTree(HuffmanTree &HT, int weight[], int n) {
	if (n < 1) {
		return;
   }
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++)  //初始化节点
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++)//初始化前n个节点的权值
	{
		HT[i].weight = weight[i-1];
	}
	for (int i = n + 1; i <= m; i++) {
		int min1, min2;
		Select(HT, i, min1, min2);//找到parent=0的最小的两个节点
		HT[i].weight = HT[min1].weight + HT[min2].weight;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[min1].parent = HT[min2].parent = i;
	}
}

//HuffmanCodeTable 
typedef char** HuffmanCodeTable;
void CreateHuffmanCode(HuffmanTree HT, HuffmanCodeTable &HC, int n) {
   //0号不用
	HC = new char*[n+1];//Huffman编码表数组
	char *tmp = new char[n];
	tmp[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {//对每个叶子节点编码
		int start = n - 1;
		int pos = i;
		int parent = HT[i].parent;
		while (parent != 0) {
			start--;
			if (HT[parent].lchild == pos) {
				tmp[start] = '0';
			}
			else
			{
				tmp[start] = '1';
			}
			pos = parent;
			parent = HT[parent].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &tmp[start]);
	}
	delete[] tmp;
}



int main()
{
	HuffmanTree HT;
	CreateHuffmanTree(HT, weight, LENGTH);
	for (int i = 1; i < 2 * LENGTH - 1; i++)
	{
		HTNode node = HT[i];
		cout << i + 1 << "\t|" << node.weight << "\t|"
			<< node.parent << "\t|" << node.lchild << "\t|" << node.rchild << "\t|" << endl;
	}
	//验证编码表
	HuffmanCodeTable hct;
	CreateHuffmanCode(HT, hct, LENGTH);
	for (int i = 1; i <= LENGTH; i++)
	{
		cout << i << ": " << weight[i - 1] << "--> " << hct[i] << endl;
	} 

	//编码
	//输入单词
	char text[100];
	cout << "=============input word=================" << endl;
	cout << "================编码====================" << endl;
	gets_s(text);
	int text_len = strlen(text);
	char *encoded_text = new char[text_len*LENGTH];
	int start = 0;  //每个字母编码的起始位置
	for (int i = 0; i <text_len; i++) {
		char c = text[i];
		int index = c - 'a' + 1;
		char *huffman_code = hct[index];
		strcpy(encoded_text + start, huffman_code);
		start += strlen(huffman_code);
	}
	cout << "编码完成： " << encoded_text << endl;

	//3、解码 找到根节点，然后顺着根节点按照编码的顺序依次往下找，直到找到叶子节点
	cout << "================解码====================" << endl;
	int root_index = 1;
	while (HT[root_index].parent != 0)
	{
		root_index++;
	}
	char decoded_text[100];
	int cur = 0;
	int encode_len = strlen(encoded_text);
	int j = 0;

	while (j < encode_len) {
		int p = root_index;
		while (HT[p].lchild != 0 || HT[p].rchild != 0) {
			char code = encoded_text[j++];
			if (code == '0')
			{
				p = HT[p].lchild;
			}
			else {
				p = HT[p].rchild;
			}
		}
		decoded_text[cur] = 'a' + p - 1;
		cur++;
	}
	decoded_text[cur] = '\0';
	cout << decoded_text << endl;
	return 0;
}
#endif