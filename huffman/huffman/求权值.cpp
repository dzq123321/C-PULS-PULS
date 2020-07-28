
#if 1;
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

//int weight[] = { 817,149,278,425,1270,223,202,609,15,77,403,241,675,751,193,10,599,633,906,278,46,489,651,23,654,79 };
//const int LENGTH = 26;
int weight[] = {20,10,30,25,15 };
const int LENGTH = 5;

typedef struct {
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;


//2��select�ҳ�����Ȩֵ��С���ַ�

void Select(HuffmanTree HT, int cur, int &min1, int &min2) {
	min1 = min2 = 0;
	for (int i = 1; i < cur; ++i)
	{
		//�Թ��Ѽ���ڵ�
		if (HT[i].parent != 0)
		{
			continue;
		}
		if (min1 == 0)
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
//����HuffmanTree

void CreateHuffmanTree(HuffmanTree &HT, int weight[], int n) {
	if (n < 1) {
		return;
	}
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++)  //��ʼ���ڵ�
	{
		HT[i].parent = 0;
		HT[i].lchild = 0;
		HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++)//��ʼ��ǰn���ڵ��Ȩֵ
	{
		HT[i].weight = weight[i - 1];
	}
	for (int i = n + 1; i <= m; i++) {
		int min1, min2;
		Select(HT, i, min1, min2);//�ҵ�parent=0����С�������ڵ�
		HT[i].weight = HT[min1].weight + HT[min2].weight;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[min1].parent = HT[min2].parent = i;
	}
}
int fun(int weight[], int n)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		pq.push(weight[i]);
	}
	int ret = 0;
	for (int i = 0; i < n-1; i++)
	{
		int min1 = pq.top();
		pq.pop();
		int min2 = pq.top();
		pq.pop();
		int tmp = min1 + min2;
		ret += tmp;
		pq.push(tmp);
	}
	return ret;
}
int main()
{
	HuffmanTree ht;
	CreateHuffmanTree(ht, weight, LENGTH);
	int ret1=0;
	for (int i = LENGTH+1; i <= 2 * LENGTH - 1; i++)
	{
		ret1 += ht[i].weight;
	}
	cout << "ret1= " << ret1 << endl;
	int ret2 = fun(weight, LENGTH);
	cout << "ret2= " << ret2 << endl;
}

#endif