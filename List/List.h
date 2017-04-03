#ifndef LIST_H
#define LIST_H

#include"Coordinate.cpp"

class List {
public:
	List(int size);
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, Coordinate *e);
	int LocateElem(Coordinate *e);
	bool PriorElem(Coordinate *currentElem, Coordinate *preElem);
	bool NextElem(Coordinate *currentElem, Coordinate *nextElem);
	bool ListInsert(int i, Coordinate *e);
	bool ListDelete(int i, Coordinate *e);
	void ListTraverse();

private:
	Coordinate *m_pList = 0;
	int m_iSize;
	int m_iLength;
};

#endif