#ifndef NODE_H
#define NODE_H
#include"List.h"
class Node {
	//数据域+指针域
public:
	int data;
	Node *next;
	void printNode();

};
#endif