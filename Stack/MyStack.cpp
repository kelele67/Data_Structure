// #include<iostream>
// #include<stdlib.h>
// #include"MyStack.h"
// using namespace std;

// template <typename T>

// MyStack<T>::MyStack(int size) {
// 	m_iSize = size;
// 	m_pBuffer = new T[size];
// 	m_iTop = 0;
// }

// template <typename T>
// MyStack<T>::~MyStack() {
// 	delete[]m_pBuffer;
// 	m_pBuffer = NULL;
// }

// template <typename T>
// bool MyStack<T>::stackEmpty() {
// 	if (m_iTop == 0) //if(0 == m_iTop)
// 		return true;
// }

// template <typename T>
// bool MyStack<T>::stackFull() {
// 	if (m_iTop == m_iSize)
// 		return true; 
// 	else
// 		return false;
// }

// template <typename T>
// void MyStack<T>::clearStack() {
// 	m_iTop = 0;
// }

// template <typename T>
// int MyStack<T>::stackLength() {
// 	return m_iTop;
// }

// template <typename T>
// bool MyStack<T>::push(T elem) {
// 	if (stackFull())
// 		return false;
// 	else
//         m_pBuffer[m_iTop] = elem; //没有指针 只需要值赋值 不用自定义拷贝构造函数
//         m_iTop++;
// 	    return true;
// }

// template <typename T>
// bool MyStack::pop(T &elem) {
// 	if (stackEmpty())
// 		return false;
// 	else
// 		m_iTop--; //使得栈顶当前位置拥有元素
// 		elem = m_pBuffer[m_iTop];
// 	    return true;
// }

// template <typename T>
// void MyStack::stackTraverse(bool isFromButton) {
// 	//栈底到栈顶
// 	if (isFromButton) {
// 	    for (int i = 0; i < m_iTop; ++i) {
// 		    cout << m_pBuffer[i];
// 		    // m_pBuffer[i].printCoordinate();

// 	    }
//     }
//     else

// 	    for (int i = m_iTop -1; i>=0; i--) {
// 		    cout << m_pBuffer[i];
// 		    // m_pBuffer[i].printCoordinate();

// 	    }
// }

