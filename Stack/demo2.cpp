//利用栈进行括号匹配
//任意输入一组括号，判断括号是否匹配

#include<iostream>
#include<stdlib.h>
#include"MyStack.h"

using namespace std;

int main(void) {
	MyStack<char> *pStack = new MyStack<char>(30);

	MyStack<char> *pNeedStack = new MyStack<char>(30);

	char str[] = "[()]]";

	char currentNeed  = 0;

	for (int i = 0; i < strlen(str); i++) {
		if(str[i] != currentNeed) {
			pStack->push(str[i]);
			switch(str[i]) {
				case'[':
					if (currentNeed != 0) {
						pNeedStack->push(currentNeed);
					}
					currentNeed = ']';
					break;
				case'(':
					if (currentNeed != 0) {
						pNeedStack->push(currentNeed);
					}

					currentNeed = ')';
					break;
			}
		}
		else {
			char elem;
			pStack->pop(elem);
			//[()]] 循环到倒数第二个字符时，
			//pNeedStack栈为空导致pNeedStack->pop(currentNeed)返回一个false,currentNeed没有置为0
			//任然为]，导致]没有入栈，pStack最后为空所以会出错
			if (!pNeedStack->pop(currentNeed)) {
				currentNeed = 0;
			}
			else
				pNeedStack->pop(currentNeed);
		}
	}

	if (pStack -> stackEmpty()) {
		cout << "字符串括号匹配" << endl;
	}
	else
		cout << "字符串括号不匹配" << endl;


	delete pStack;
	pStack = NULL;

	delete pNeedStack;
	pNeedStack = NULL;

	system("pause");
	return 0;
}