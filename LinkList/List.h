#ifndef LIST_H
#define LIST_H

#include"Node.h"

class List {
public:
	List();//不需要size参数
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Node *pNode);
	int LocateElem(Node *pNode);
	bool PriorElem(Node *pCurrentNode, Node *pPreNode);
	bool NextElem(Node *pCurrentNode, Node *pNextNode);
	bool ListInsert(int i, Node *pNode);
	bool ListDelete(int i, Node *pNode);
	bool ListInsertHead(Node *pNode);
	bool ListInsertTail(Node *pNode);
	void ListTraverse();

private:
	Node *m_pList = 0;
	int m_iLength;
};

#endif