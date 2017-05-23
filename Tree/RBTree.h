#ifndef RB_TREE_H
#define RB_TREE_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

template<class KEY, class U>
class RB_Tree {
private:
	RB_Tree(const RB_Tree& input) {}
	const RB_Tree& operator=(const RB_Tree& input) {}
private:
	enum COLOR {
		RED,
		BLACK
	};
	class RB_Node {
	public:
		RB_Node() {
			right = NULL;
			left = NULL;
			parent = NULL;
		}
		COLOR RB_COLOR;
		RB_Node* right;
		RB_Node* left;
		RB_Node* parent;
		KEY key;
		U data;
	};
public:
	RB_Tree() {
		this->m_nullNode = new RB_Node();
		this->m_root = m_nullNode;
		this->m_nullNode->right = this->m_root;
		this->m_nullNode->left = this->m_root;
		this->m_nullNode->parent = this->m_root;
		this->m_nullNode->RB_COLOR = BLACK;
	}

	bool Empty() {
		if (this->m_root == this->m_nullNode) {
			return true;
		} else {
			return false;
		}
	}

	//查找key
	RB_Node* find(KEY key) {
		RB_Node* index = m_root;
		while (index != m_nullNode) {
			if (key < index->key) {
				index = index->left; // 比当前的小，往左
			} else if (key > index->key) {
				index = index->right; // 比当前的大，往右
			} else {
				break;
			}
		}
		return index;
	}

	bool Insert(KEY key, U data) {
		RB_Node* insert_point = m_nullNode;
		RB_Node* index = m_root;
		while (index != m_nullNode) {
			insert_point = index;
			if (key < index->key) {
				index = index->left;
			} else if (key > index->key) {
				index = index->right;
			} else {
				break;
			}
		}
		RB_Node* insert_node = new RB_Node();
		insert_node->key = key;
		insert_node->data = data;
		insert_node->RB_COLOR = RED;
		insert_node->right = m_nullNode;
		insert_node->left = m_nullNode;
		//如果插入一棵空树
		if (insert_point == m_nullNode) {
			m_root = insert_node;
			m_root->parent = m_nullNode;
			m_nullNode->left = m_root;
			m_nullNode->right = m_root;
			m_nullNode->parent = m_root;
		} else {
			if (key < insert_point->key) {
				insert_point->left = insert_node;
			} else {
				insert_point->right = insert_node;
			}
			insert_node->parent = insert_point;
		}
		InsertFixUp(insert_node); // 恢复红黑树性质
	}

	void InsertFixUp(RB_Node* node) {
		while (node->parent->RB_COLOR == RED) {
			// Z的父亲为祖父的左孩子
			if (node->parent == node->parent->parent->left) {
				RB_Node* uncle = node->parent->parent->right;
				//case①: Z的叔叔Y是红色的
				if (uncle->RB_COLOR == RED) {
					node->parent->RB_COLOR = BLACK;
					uncle->RB_COLOR = BLACK; //1.把父->黑、叔->黑
					node->parent->parent->RB_COLOR = RED; //2.祖->红
					node = node->parent->parent; //3.祖->当前结点
				} 
				//case②: Z的叔叔是黑色的
				else if (uncle->RB_COLOR == BLACK) {
					//case②.1: Z是右孩子
					if (node == node->parent->right) {
						node = node->parent; // 1.父->当前结点
						RotateLeft(node); // 2.左旋
					}
					//case②.2: Z是左孩子
					node->parent->RB_COLOR = BLACK; // 1.父->黑
					node->parent->parent->RB_COLOR = RED; // 2.祖父->红
					RotateRight(node->parent->parent); // 3.祖父为Pivot右旋
				}
			} 
			// Z的父亲为祖父的右孩子，对称
			else {
				RB_Node* uncle = node->parent->parent->left;
				if (uncle->RB_COLOR == RED) {
					node->parent->RB_COLOR = BLACK;
					uncle->RB_COLOR = BLACK; 
					node->parent->parent->RB_COLOR = RED; 
					node = node->parent->parent; 
				} 
				else if (uncle->RB_COLOR == BLACK) {
					if (node == node->parent->right) {
						node = node->parent; 
						RotateRight(node); // 左旋改为右旋
					}
					node->parent->RB_COLOR = BLACK; 
					node->parent->parent->RB_COLOR = RED; 
					RotateLeft(node->parent->parent); // 右旋改为左旋
				}
			}
		}
		m_root->RB_COLOR = BLACK; // 最后把根结点涂黑即可
	}

	//左旋代码实现
	bool RotateLeft(RB_Node* node) {
		if (node == m_nullNode || node->right == m_nullNode) {
			return false;
		}
		RB_Node* lower_right = node->right;
		lower_right->parent = node->parent;
		node->right = lower_right->left;
		if (lower_right->left != m_nullNode) {
			lower_right->left->parent = node;
		}
		// 旋转及结点为根结点
		if (node->parent == m_nullNode) {
			m_root = lower_right;
			m_nullNode->left = m_root;
			m_nullNode->right = m_root;
		} else {
			if (node == node->parent->left) {
				node->parent->left = lower_right;
			} else {
				node->parent->right = lower_right;
			}
		}
		node->parent = lower_right;
		lower_right->left = node;
	}

	// 右旋代码实现
	bool RotateRight(RB_Node* node) {
		if (node == m_nullNode || node->left == m_nullNode) {
			return false;
		}
		RB_Node* lower_left = node->left;
		node->left = lower_left->right;
		lower_left->parent = node->parent;
		if (lower_left->right != m_nullNode) {
			lower_left->right->parent = node;
		}
		if (node->parent == m_nullNode) {
			m_root = lower_left;
			m_nullNode->left = m_root;
			m_nullNode->right = m_root;
		} else {
			if (node == node->parent->right) {
				node->parent->right = lower_left;
			} else {
				node->parent->left = lower_left;
			}
		}
		node->parent = lower_left;
		lower_left->right = node;
	}

	bool Delete(KEY key) {
		RB_Node* delete_point = find(key);
		if (delete_point == m_nullNode) {
			return false;
		}
		// 删除结点 有两个儿子 
		if (delete_point->left != m_nullNode && delete_point->right != m_nullNode) {
			RB_Node* successor = InOrderSuccessor(delete_point);
			delete_point->data = successor->data;
			delete_point->key = successor->key;
			delete_point = successor;
		}
		RB_Node* delete_point_child;
		if (delete_point->right != m_nullNode) {
			delete_point_child = delete_point->right;
		} else if (delete_point->left != m_nullNode) {
			delete_point_child = delete_point->left;
		} else {
			delete_point_child = m_nullNode;
		}
		delete_point_child->parent = delete_point->parent;
		// 删除的是根节点
		if (delete_point->parent == m_nullNode) {
			m_root = delete_point_child;
			m_nullNode->parent = m_root;
			m_nullNode->left = m_root;
			m_nullNode->right = m_root;
		} else if (delete_point == delete_point->parent->right) {
			delete_point->parent->right = delete_point_child;
		} else {
			delete_point->parent->left = delete_point_child;
		}
		// 如果删除的是黑色结点 + 不是倒数第二个结点且父结点不为空
		if (delete_point->RB_COLOR == BLACK && !(delete_point_child == m_nullNode &&
			delete_point_child->parent == m_nullNode)) {
			DeleteFixUp(delete_point_child);
		}
		delete delete_point;
		return true;
	}

	// 删除修复
	void DeleteFixUp(RB_Node* node) {
		while (node != m_root && node->RB_COLOR == BLACK) {
			// 同样先考虑是父结点的左结点的情况
			if (node == node->parent->left) {
				RB_Node* brother = node->parent->right;
				// case①: X 的兄弟结点 W 是红色的
				if (brother->RB_COLOR == RED) {
					brother->RB_COLOR = BLACK; //1.兄->红
					node->parent->RB_COLOR = RED; //2.父->红
					RotateLeft(node->parent); //3.父为Pivot左旋
				}
				// case②: X 的兄弟结点 W 是黑色的
				else {
					// case②.1: 且 W 两个孩子都是黑的
					if (brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK) {
						brother->RB_COLOR = RED; //1. 兄->红
						node = node->parent; //2.父->当前结点
					}
					// case②.2: W 的孩子 左红右黑
					else if (brother->right->RB_COLOR == BLACK) {
						brother->RB_COLOR = RED; //1.兄->红
						brother->left->RB_COLOR = BLACK; //2.兄左子->黑
						RotateRight(brother); //3.父为Pivot右旋
					}
					// case②.3: W 的孩子 左黑右红
					brother->RB_COLOR = node->parent->RB_COLOR; //1. 兄->父色
					node->parent->RB_COLOR = BLACK; //2. 父->黑
					brother->right->RB_COLOR = BLACK; //3.兄右子->黑
					RotateLeft(node->parent); //4.父为Pivot左旋
					node = m_root;
				}
			}
			else {
				// 同样的考虑是父节点的右子节点的情况，也是只改变旋转
				RB_Node* brother = node->parent->left;
				// case①: X 的兄弟结点 W 是红色的
				if (brother->RB_COLOR == RED) {
					brother->RB_COLOR = BLACK; //1.兄->红
					node->parent->RB_COLOR = RED; //2.父->红
					RotateRight(node->parent); //3.父为Pivot左旋
				}
				// case②: X 的兄弟结点 W 是黑色的
				else {
					// case②.1: 且 W 两个孩子都是黑的
					if (brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK) {
						brother->RB_COLOR = RED; //1. 兄->红
						node = node->parent; //2.父->当前结点
					}
					// case②.2: W 的孩子 左红右黑
					else if (brother->right->RB_COLOR == BLACK) {
						brother->RB_COLOR = RED; //1.兄->红
						brother->left->RB_COLOR = BLACK; //2.兄左子->黑
						RotateLeft(brother); //3.父为Pivot右旋
					}
					// case②.3: W 的孩子 左黑右红
					brother->RB_COLOR = node->parent->RB_COLOR; //1. 兄->父色
					node->parent->RB_COLOR = BLACK; //2. 父->黑
					brother->right->RB_COLOR = BLACK; //3.兄右子->黑
					RotateRight(node->parent); //4.父为Pivot右旋
					node = m_root;
				}	
			}
		}
		m_nullNode->parent = m_root; // 最后将node置为根结点
		node->RB_COLOR = BLACK; // 并改为黑色
	}

	inline RB_Node* InOrderPredecessor(RB_Node* node) {
		// 空结点 没有 predecessor 前驱
		if (node == m_nullNode) {
			return m_nullNode;
		}
		RB_Node* result = node->left;
		//找到左子树的最大（右）结点
		while (result != m_nullNode) {
			if (result->right != m_nullNode) {
				result = result->right;
			} else {
				break;
			}
		}
		// 循环结束时意味着 result==null 或者result 的右子节点 == null
		if (result == m_nullNode) {
			RB_Node* index = node->parent;
			result = node;
			while (index != m_nullNode && result == index->left) {
				result = index;
				index = index->parent;
			}
			result = index; // 第一个parent 的右结点 或者 null
		}
		return result;
	}

	inline RB_Node* InOrderSuccessor(RB_Node* node) {
		if (node == m_nullNode) {
			return m_nullNode;
		}
		RB_Node* result = node->right;
		// 找到node 的右子树的最小（左）结点
		while (result != m_nullNode) {
			if (result->left != m_nullNode) {
				result = result->left;
			} else {
				break;
			}
		}
		// 循环结束时意味着 result==null 或者result 的左子节点 == null
		if (result == m_nullNode) {
			RB_Node* index = node->parent;
			result = node;
			while (index != m_nullNode && result == index->right) {
				result = index;
				index = index->parent;
			}
			result = index; // 第一个parent 的左结点 或者 null
		}
		return result;
	}

	// debug
	void InOrderTraverse() {
		InOrderTraverse(m_root);
	}
	void CreateGraph(string filename) {

	}
	void InOrderCreate(ofstream& file, RB_Node* node) {

	}
	void InOrderTraverse(RB_Node* node) {
		if (node == m_nullNode) {
			return;
		} else {
			InOrderTraverse(node->left);
			cout << node->key << endl;
			InOrderTraverse(node->right);
		}
	}

	~RB_Tree() {
		clear(m_root);
		delete m_nullNode;
	}

private:
	// utility function for destructor to destruct object
	void clear(RB_Node* node) {
		if (node == m_nullNode) {
			return;
		} else {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}
private:
	RB_Node *m_nullNode;
	RB_Node *m_root;
};
#endif