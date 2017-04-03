#include"List.h"
#include"Node.cpp"
#include<iostream>
using namespace std;

List::List() {
	m_pList = new Node;
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;//头结点并不算在当前链表当中
}

//释放所有节点
List::~List() {
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

//释放除了头结点以外的结点
void List::ClearList() {
	Node *currentNode = m_pList->next;
	while (currentNode != NULL) {
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;
}


bool List::ListEmpty() {
	if (m_iLength == 0) {
		return true;
	}
	else {
		return false;
	}
}

int List::ListLength() {
	return m_iLength;
}

//头插法
bool List::ListInsertHead(Node *pNode) {
	Node *temp = m_pList->next;//保留头结点的next
	Node *newNode = new Node;//从堆中申请内存，保证函数执行完毕后不被回收
	//内存申请失败
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;//获取传入进来的data
	m_pList->next = newNode;//将头结点next指向新的结点
	newNode->next = temp;//新的结点指向p_list的next；
	m_iLength++;
	return true;
}

//尾插法
bool List::ListInsertTail(Node *pNode) {
	Node *currentNode = m_pList;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	//申请内存
	Node *newNode = new Node;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;

	return true;
}

bool List::ListInsert(int i, Node *pNode) {
	if (i < 0 || i > m_iLength) {
		return false;
	}
	Node *currentNode = m_pList;
	//找到第i个位置的上一个位置
	for (int k = 0; k < i; k++) {
		currentNode = currentNode->next;
	}
	//申请内存
	Node *newNode = new Node;
	if (newNode == NULL) {
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	m_iLength++;

	return true;
}

bool List::ListDelete(int i, Node *pNode) {
	//不能删除尾结点后面一个
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	//找到第i个
	for (int k = 0; k <= i; k++) {
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;

	return true;
}

bool List::GetElem(int i, Node *pNode) {
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	Node *currentNode = m_pList;
	// Node *currentNodeBefore = NULL;
	//找到第i个
	for (int k = 0; k <= i; k++) {
		// currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List::LocateElem(Node *pNode) {
	Node *currentNode = m_pList;
	int count = 0;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data) {
			return count;
		}
		count++;
	}
	return -1;
}

bool List::PriorElem(Node *pCurrentNode, Node *pPreNode) {
	Node *currentNode = m_pList;
	Node *tempNode = NULL;
	while (currentNode->next != NULL) {
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data) {
			if (tempNode == m_pList) {
				return false;
			}
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	return false;
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode) {
	Node *currentNode = m_pList;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data) {
			if (currentNode->next == NULL) {
				return false;
			}
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	return false;
}

void List::ListTraverse() {
	Node *currentNode = m_pList;
	while (currentNode->next != NULL) {
		//第一个头结点不遍历
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}
