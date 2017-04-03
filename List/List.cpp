#include"List.h"
#include<iostream>
using namespace std;

List::List(int size) {
	m_iSize = size;
	m_pList = new Coordinate[m_iSize];
	m_iLength = 0;
}

List::~List() {
	delete []m_pList;
	m_pList = NULL;
}

void List::ClearList() {
	m_iLength = 0;
}

bool List::ListEmpty() {
	if (m_iLength == 0)
		return true;
	else
		return false;
	// return m_iLength == 0 true : false;
}

int List::ListLength() {
	return m_iLength;
}

bool List::GetElem(int i, Coordinate *e) {
	if (i < 0 || i > m_iSize)
		return false;
	else
		*e = m_pList[i];
	    return true;
}

int List::LocateElem(Coordinate *e) {
	for(int i = 0; i < m_iLength; i++) {
		//比较运算符也要重载
		if (m_pList[i] == *e)
			return i;
	}
	return -1;
}

bool List::PriorElem(Coordinate *currentElem, Coordinate *preElem){
	int temp = LocateElem(currentElem);
	if (temp == -1) {
		return false;
	}
	else {
		if (temp == 0) {
			return false;
		}
		else {
			*preElem = m_pList[temp - 1];
			return true;
		}
	}
}

bool List::NextElem(Coordinate *currentElem, Coordinate *nextElem){
	int temp = LocateElem(currentElem);
	if (temp == -1) {
		return false;
	}
	else {
		if (temp == m_iLength - 1) {
			return false;
		}
		else {
			*nextElem = m_pList[temp + 1];
			return true;
		}
	}
}

void List::ListTraverse() {
	for (int i = 0; i < m_iLength; i++) {
		cout << m_pList[i] << endl;
	}
}

bool List::ListInsert(int i, Coordinate *e) {
	if (i < 0 || i > m_iLength) {
		return false;
	}
	//先移动，且最后一个元素先移动，避免元素被覆盖
	for (int k = m_iLength - 1; k >= i; k--) {
		m_pList[k+1] = m_pList[k]; 
	}
	m_pList[i] = *e;

	m_iLength++; //保证m_iLength依然为当前元素个数

	return true;
}

bool List::ListDelete(int i, Coordinate *e) {
	//删除时没有m_iLength这个位置的元素
	if (i < 0 || i >= m_iLength) {
		return false;
	}
	*e = m_pList[i];

	for (int k = i; k < m_iLength - 1; k++) {
		m_pList[k] = m_pList[k+1]; 
	}
	m_iLength--;

	return true;
}