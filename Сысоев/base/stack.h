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
  TStack(TStack &s)
  {
	  size = s.size;
	  top = s.top;
	  pMem = new T[size];
	  for (int i = 0; i < size; i++)
		  pMem[i] = s.pMem[i];
  }
  ~TStack()
  {
    delete [] pMem;
  }
  int Max_size()
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
  T Top_el()
  {
	  if (IsEmpty())
		  throw "Error";
	  return pMem[top];
  }
  int Prior()
  {
	  if (IsEmpty())
		  throw "Error";
	  if ((pMem[top] == '+') || (pMem[top] == '-'))
		 return 1;
	  if ((pMem[top] == '*') || (pMem[top] == '/'))
		  return 2;
  }
};

#endif
