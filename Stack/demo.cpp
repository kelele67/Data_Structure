//电脑第一次崩溃把代码崩没了心好痛
#include<iostream>
#include<stdlib.h>
#include"MyStack.h"
// #include"MyStack.cpp"
#include"Coordinate.h"
#include"Coordinate.cpp"

using namespace std;

//定义Coordinate 坐标类
//改造栈类 使其可以用于坐标类

int main(void) {
	MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);

	pStack->push(Coordinate(1, 2)); //底
	pStack->push(Coordinate(3, 4));

	pStack->stackTraverse(true);


	pStack->stackTraverse(false);

	cout << pStack->stackLength() << endl;

}
