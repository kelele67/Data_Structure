//数制转换
//输入任意的十进制数N，分别输出N的二进制，八进制，十六进制
#include<iostream>
#include<stdlib.h>
#include"MyStack.h"

using namespace std;

#define BINARY      2
#define OCTONARY    8
#define HEXADECIMAL 16

int main(void) {
	char num[] = "0123456789ABCDEF";

	MyStack<int> *pStack = new MyStack<int>(30);

    int N = 2016;
    int mod = 0;
	while (N != 0) {
		mod = N % HEXADECIMAL;
		pStack->push(mod);
		N = N / HEXADECIMAL;
	}

	// pStack->stackTraverse(false);

	// for (int i = pStack->stackLength()-1; i >= 0; i--) {
	// 	num[pStack[i]] //栈没有下标访问的功能，
	// }

    int elem = 0;
	while(!pStack->stackEmpty()) {
	    pStack->pop(elem);
	    cout << num[elem];
	}

	delete pStack;
	pStack = NULL;

	return 0;
}