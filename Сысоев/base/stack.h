#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int top;
  int count=0;
public:
  TStack(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > MaxStackSize))
      throw size;
    pMem = new T[size];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  int max_size()
  {
	  return size;
  }
  int Size()
  {
	  return count;
  }
  bool IsFull()
  {
	  return top == size -1;
  }
  bool IsEmpty()
  {
	  return top == -1;
  }
  void push(const T &a)
  {
	  if (IsFull())
		  throw "Error";
	  count++;
	  top++;
	  pMem[top] = a;
  }
  T pop()
  {
	  if (IsEmpty())
		  throw "Error";
	  count--;
	  return pMem[top--];
  }
  T top_el()
  {
	  return pMem[top];
  }
  int prior()
  {
	  if ((pMem[top] == '+') || (pMem[top] == '-'))
		 return 1;
	  if ((pMem[top] == '*') || (pMem[top] == '/'))
		  return 2;
  }
};

#endif
