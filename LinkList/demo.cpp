#include<stdlib.h>
#include"List.cpp"
#include<iostream>
using namespace std;

//线性表--单链表

int main() {
	Node node1;
	node1.data = 3;
	Node node2;
	node2.data = 4;	
	Node node3;
	node3.data = 5;
	Node node4;
	node4.data = 6;

	Node node5;
	node5.data = 7;

	Node temp;


	List *pList = new List();

	// pList->ListInsertHead(&node1);
	// pList->ListInsertHead(&node2);
	// pList->ListInsertHead(&node3);
	// pList->ListInsertHead(&node4);

	pList->ListInsertTail(&node1);
	pList->ListInsertTail(&node2);
	pList->ListInsertTail(&node3);
	pList->ListInsertTail(&node4);

	// pList->ListInsert(1, &node5);

	pList->ListDelete(1, &temp);
	//失败pList->GetElem(1, &temp);
	//pList->PriorElem(&node4, &temp);

	pList->ListTraverse();

	cout << "temp=:" << temp.data << endl;
	delete pList;
	pList = NULL;
	return 0;
}