#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node(char data = 0);
	char m_cData; //不是索引
	bool m_bIsVisited;
};

#endif