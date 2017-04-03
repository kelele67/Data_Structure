#include"Tree.h"

Tree::Tree() {
	m_pRoot = new Node();
}

Node *Tree::SearchNode(int nodeIndex) {
	return m_pRoot->SearchNode(nodeIndex);
}

Tree::~Tree() {
	DeleteNode(0, NULL);
	// m_pRoot->DeleteNode();
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode) {
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL) {
		return false;
	}

    Node *node = new Node();
    if (node == NULL) {
    	return false;
    }
	node->index = pNode->index;
	node->data = pNode->data;
	//更新父节点
	node->pParent = temp;
	
	if (direction == 0) {
		temp->pLChild = node;
	}
	if (direction == 1) {
		temp->pRChild = node;
	}
	return true;	
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode) {
	Node *temp = SearchNode(nodeIndex);
	if (temp == NULL) {
		return false;
	}
	if (pNode != NULL) {
		pNode->data = temp->data;
	}
	temp->DeleteNode();
	return true;
}

//前序遍历
void Tree::PreorderTraversal() {
	m_pRoot->PreorderTraversal();
}
//中序遍历
void Tree::InorderTraversal() {
	m_pRoot->InorderTraversal();
}

void Tree::PostorderTraversal() {
	m_pRoot->PostorderTraversal();
}

