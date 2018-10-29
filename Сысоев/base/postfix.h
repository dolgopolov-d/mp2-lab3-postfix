#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

TStack<char> a(MaxStackSize);

class TPostfix
{
  string infix;
  string postfix;
  int i = 0;
  int prior;
public:
  TPostfix()
  {
	  infix = "(a+b)*(c-f)+g";
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  void ToPostfix()
  {
	  do
	  {
		  char c = infix[i];
		  if ((c == '+') || (c == '-'))
			  prior = 1;
		  if ((c == '*') || (c == '/'))
			  prior = 2;
		  if ((c == '(') || (c == ')'))
			  prior = 0;
		  if ((c != '+') && (c != '-') && (c != '/') && (c != '*') && (c != '(') && (c != ')') && (c != '^'))
			  postfix.push_back(c);
		  else
		  {
			  if (c == '(')
				  a.push(c);
			  if (a.IsEmpty())
				  a.push(c);
			  else
			  {
				  if (c == ')')
				  {
					  while ((!a.IsEmpty()) && (a.top_el() != '('))
						  postfix.push_back(a.pop());
					  if (a.top_el() == '(')
						  a.pop();
				  }
				  while ((!a.IsEmpty()) && (prior <= a.prior()) && (a.top_el() != '('))
				  {
						 postfix.push_back(a.pop());
				  }
				  if ((c == '(') || (c == ')'))
					  ;
				  else
					 a.push(c);
			  }
		  }
		  i++;
	  } while (infix[i] != 0);
	  while ((infix[i] == 0) && (!a.IsEmpty()))
		  postfix.push_back(a.pop());
  }
 /* double Calculate(); // Ввод переменных, вычисление по постфиксной форме*/
};
#endif
