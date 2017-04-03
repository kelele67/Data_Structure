// 二叉树链表表示

// BOOL CreateTree(Tree **pTree, Node *pRoot); //创建
// void DestoryTree(Tree *pTree); //销毁
// Node *SearchNode(Tree *pTree, int nodeIndex); //根据索引寻找结点
// BOOL AddNode(Tree *pTree, int nodeIndex, int direction, Node *pNode); //添加
// BOOL DeleteNode(Tree *pTree, int nodeIndex, Node *pNode); //删除
// void PreorderTraversal(); //前序遍历
// void InorderTraversal(); //中序遍历
// void PostorderTraversal(); //后序遍历
// 索引 数据 左孩子结点指针 右孩子结点指针 父节点指针

#ifndef TREE_H
#define TREE_H
#include<stdio.h>
#include"Node.cpp"

class Tree {
public:
	Tree();
	~Tree();
	Node *SearchNode(int nodeIndex);
	bool AddNode(int nodeIndex, int direction, Node *pNode);
	bool DeleteNode(int nodeIndex, Node *pNode);
	void PreorderTraversal();
	void InorderTraversal();
	void PostorderTraversal();

private:
	Node *m_pRoot;
};

#endif