#include "CMap.h"

CMap::CMap(int capacity) {
	m_iCapacity = capacity;
	m_iNodeCount = 0;
	m_pNodeArray = new Node[m_iCapacity];
	m_pMatrix = new int[m_iCapacity * m_iCapacity];
	//初始化
	//memset(m_pMatrix, 0, m_iCapacity * m_iCapacity *sizeof(int));
	for (int i = 0; i < m_iCapacity * m_iCapacity; i++) {
		m_pMatrix[i] = 0;
	}
}

CMap::~CMap() {
	delete []m_pNodeArray;
	delete []m_pMatrix;
}

//不只是把指针添加进来， 只需要保存数据
bool CMap::addNode(Node *pNode) {
	if (pNode == NULL) {
		return false;
	}
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
	m_iNodeCount++;
	return true;
}

void CMap::resetNode() {
	for (int i = 0; i < m_iNodeCount; i++) {
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val) {
	if (row < 0 || row > m_iCapacity) {
		return false;
	}
	if (col < 0 || col > m_iCapacity) {
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	return true;
}

bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val) {
	if (row < 0 || row > m_iCapacity) {
		return false;
	}
	if (col < 0 || col > m_iCapacity) {
		return false;
	}
	m_pMatrix[row * m_iCapacity + col] = val;
	m_pMatrix[col * m_iCapacity + row] = val;
	return true;
}

void CMap::printMatrix() {
	for (int i=0; i < m_iCapacity; i++) {
		for (int j=0; j < m_iCapacity; j++) {
			cout << m_pMatrix[i * m_iCapacity + j] << " ";
		}
		cout << endl;
	}
}

bool CMap::getValueFromMatrix(int row, int col, int &val) {
	if (row < 0 || row > m_iCapacity) {
		return false;
	}
	if (col < 0 || col > m_iCapacity) {
		return false;
	}
	val = m_pMatrix[row * m_iCapacity + col];
	return true;
}

//深度优先遍历 类似于前序遍历 递归                                                                                                             

void CMap::depthFirstTraverse(int nodeIndex) {
	int value = 0;
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	for (int i = 0; i < m_iCapacity; i++) {
		getValueFromMatrix(nodeIndex, i, value);
		//有这条弧
		if (value == 1) {
			if (m_pNodeArray[i].m_bIsVisited) {
				continue;
			} else {
				depthFirstTraverse(i);
			}
		} else {
			continue;
		}
	}
}

//广度优先遍历
void CMap::breadthFirstTraverse(int nodeIndex) {
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;

	vector<int> curVec;
	curVec.push_back(nodeIndex);

	breadthFirstTraverseImpl(curVec);
}

//实现函数
void CMap::breadthFirstTraverseImpl(vector<int> preVec) {
	int value = 0;
	vector<int> curVec;

	for (int m = 0; m < (int)preVec.size(); m++) {
		//当前点是否与其他点有连接
		for (int i = 0; i < m_iCapacity; i++) {
			getValueFromMatrix(preVec[m], i, value);
			//相链接
			if (value == 1) {
				if (m_pNodeArray[i].m_bIsVisited) {
					continue;
				} else {
					cout << m_pNodeArray[i].m_cData << " ";
					m_pNodeArray[i].m_bIsVisited = true;

					curVec.push_back(i);
				}
			}
		}
	}
	//本层是否是最后一层
	if (curVec.size() == 0) {
		return;
	} else {
		breadthFirstTraverseImpl(curVec);
	}
}