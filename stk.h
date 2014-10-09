#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<string.h>

#define MAX_SIZE 64
#define FULL 0
#define EMP  -1

typedef struct _STACK{
	char _data[MAX_SIZE];
	unsigned int _top;
}_Stack;

#endif

//////////////////////////////////////////////////////////////
////initiate the Stack
void InitStk(_Stack *_sk)
{
	_sk->_top = -1;
}

//////////////////////////////////////////////////////////////
////Get the length of the Stack
int StkLen(_Stack * _sk)
{
	return (_sk->_top + 1);
}

//////////////////////////////////////////////////////////////
////Whether the Stack is empty
int IsEmp(_Stack * _sk)
{
	return (_sk->_top == -1);
}

//////////////////////////////////////////////////////////////
////push elem to the Stack
int Push(_Stack *_sk,	char _elem)
{
	if(_sk->_top == (MAX_SIZE - 1))
	   return FULL;
	_sk->_top++;
	_sk->_data[_sk->_top] = _elem;
	return 1;
}

//////////////////////////////////////////////////////////////
////get an elem from the Stack
int Pop(_Stack *_sk,	char *_elem)
{
	if(_sk->_top == -1)
	   return EMP;
	*_elem = _sk->_data[_sk->_top];
	_sk->_top--;
	return 1;
}

//////////////////////////////////////////////////////////////
////leek the Stack and print all elem
void LeekStK(_Stack *_sk)
{
	unsigned int n;
	for(n = 0; n < _sk->_top; n--)
	{
		printf("%c ", _sk->_data[_sk->_top]);
	}
	printf("\n");
}

//////////////////////////////////////////////////////////////
////
int Symmetry(const char *_str)
{
	_Stack __sk;
	unsigned int __len, n;
	char __elem;
	InitStk(&__sk);
	__len = strlen(_str);
	for(n = 0; n < __len; n++)
	   Push(&__sk, _str[n]);
	for(n = 0; n < __len; n++)
	{
		Pop(&__sk, &__elem);
		if(_str[n] != __elem)
		   return 0;
	}
	return 1;
}
