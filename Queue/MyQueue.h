#ifndef MYQUEUE_H
#define MYQUEUE_H

/*环形队列C++实现*/
using namespace std;

#include"Customer.h"

class MyQueue {
public:
	MyQueue(int queueCapacity); //IntiQueue(&Q)创建队列
	virtual ~MyQueue(); //DestroyQueue(&Q)销毁队列
	void ClearQueue(); //ClearQueue(&Q)清空队列
	bool QueueEmpty() const; //QueueEmpty(Q）判空队列
	bool QueueFull() const; //判断队列是否为满
	int QueueLength() const; //QueueLenght(Q)队列长度
	// bool EnQueue(int element); //EnQueue(&Q, element)新元素入队
	// bool DeQueue(int &element); //DeQueue(&Q, &element)首元素出队
    bool EnQueue(Customer element); //EnQueue(&Q, element)新元素入队
	bool DeQueue(Customer &element); //DeQueue(&Q, &element)首元素出队
	//void QueueTraverse(); //QueueTraverse(Q, visit())遍历队列
	void QueueTraverse(); //QueueTraverse(Q, visit())遍历队列
private:
	// int *m_pQueue; //队列数组指针
	Customer *m_pQueue;
	int m_iQueueLen; //队列元素个数
	int m_iQueueCapacity; //队列数组容量
	int m_iHead;
	int m_iTail;
};
#endif