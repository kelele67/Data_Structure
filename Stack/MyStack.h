/*栈类C++实现*/
#ifndef MYSTACK_H
#define MYSTACK_H

#include<iostream>
using namespace std;

template <typename T>


class MyStack {
public:
	MyStack(int size); //分配内存初始化栈空间，设置栈容量，栈顶
	~MyStack(); //回收栈空间内存
	bool stackEmpty(); //判定栈是否为空
	bool stackFull(); //判定栈是否满
	void clearStack(); //清空栈
	int stackLength(); //栈已有元素个数
	// bool push(char elem); //元素入栈，栈顶上升
	// bool pop(char &elem);
	// //char pop(); //元素出栈，栈顶下降 Full -> throw -1,
	bool push(T elem); //元素入栈，栈顶上升
	bool pop(T &elem);
	//char pop(); //元素出栈，栈顶下降 Full -> throw -1, 
	void stackTraverse(bool isFromButton); //遍历栈中所有元素

private:
	// char *m_pBuffer; //栈空间指针
	T *m_pBuffer; //栈空间指针
	int m_iSize; //栈容量
	int m_iTop; //栈顶，栈中元素个数
};


template <typename T>
MyStack<T>::MyStack(int size) {
	m_iSize = size;
	m_pBuffer = new T[size];
	m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack() {
	delete[]m_pBuffer;
	m_pBuffer = NULL;
}

template <typename T>
bool MyStack<T>::stackEmpty() {
	if (m_iTop == 0) //if(0 == m_iTop)
		return true;
	else
		return false;
}

template <typename T>
bool MyStack<T>::stackFull() {
	if (m_iTop == m_iSize)
		return true; 
	else
		return false;
}

template <typename T>
void MyStack<T>::clearStack() {
	m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength() {
	return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem) {
	if (stackFull())
		return false;
	else
        m_pBuffer[m_iTop] = elem; //没有指针 只需要值赋值 不用自定义拷贝构造函数
        m_iTop++;
	    return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem) {
	if (stackEmpty())
		return false;
	else
		m_iTop--; //使得栈顶当前位置拥有元素
		elem = m_pBuffer[m_iTop];
	    return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromButton) {
	//栈底到栈顶
	if (isFromButton) {
	    for (int i = 0; i < m_iTop; ++i) {
		    cout << m_pBuffer[i];
		    // m_pBuffer[i].printCoordinate();

	    }
    }
    else

	    for (int i = m_iTop -1; i>=0; i--) {
		    cout << m_pBuffer[i];
		    // m_pBuffer[i].printCoordinate();

	    }
}
#endif

