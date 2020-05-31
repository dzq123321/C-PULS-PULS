#if 0
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<stdlib.h>
#include<iostream>
#include "slist.h"
using namespace std;
//int main() {
//	string str1 = "hello world";
//	string str2 = str1;
//	printf("Sharing the memory:\n");
//	printf("/tstr1's address: %x\n", str1.c_str());
//	printf("/tstr2's address: %x\n", str2.c_str());
//	str1[1] = 'q';
//	str2[1] = 'w';
//	printf("After Copy-On-Write:\n");
//	printf("/tstr1's address: %x\n", str1.c_str());
//	printf("/tstr2's address: %x\n", str2.c_str());
//	return 0;
//}
//public ListNode oddevenList(ListNode head) {
//	if (head != nullptr) {
//		ListNode odd = head;
//		ListNode even = odd.next;
//		List middleNode = even;
//		while (even != nullptr || even.next != nullptr) {
//			odd.next = old.next.next;
//			even.next = even.next.next;
//			odd = odd.next;
//			even = even.next;
//		}
//		odd.next = middleNode;
//	}
//	return head;
//}
SListNode* partition(SListNode* pHead, int x) {
	if (pHead == NULL)
		return pHead;
	SListNode* middle = _Buynode(x);
	SListNode* first = _Buynode(-1);
	SListNode* cur = pHead;
	SListNode* pnext = pHead->next;
	SListNode* left = first;
	SListNode* right = middle;
	while (cur)
	{
		pnext = cur->next;
		if (cur->data < x)
		{
			left->next = cur;
			cur->next = middle;
			left = cur;
		}
		if (cur->data >= x)
		{
			right->next = cur;
			cur->next = NULL;
			right = cur;
		}
		cur = pnext;
	}
	SListNode* p = first;
	while (p->next != NULL)
	{
		if (p->next->data == x)
		{
			SListNode* tmp = p->next;
			p->next = p->next->next;
			delete tmp;
			tmp = nullptr;
			break;
		}
	}
	SListNode* tmp = first->next;
	delete first;
	first = nullptr;
	return tmp;
}
void main()
{
	SList plist;
	SListInit(&plist);
	SListPushBack(&plist, 5);
		SListPushBack(&plist, 2);
		SListPushBack(&plist,7);
		SListPushBack(&plist, 1);
		SListPushBack(&plist, 4);
		SListPushBack(&plist, 3);
		SList* plist=partition(&plist, 7)
		SListShow(&plist);

}
#endif