#ifndef NODE_H
#define NODE_H

class Node {
public:
	//构造函数 初始化
	Node();
	Node *SearchNode(int nodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};
#endif