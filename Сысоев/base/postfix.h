#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;


class TPostfix
{
  string infix;
  string postfix;
  int i = 0;
  int prior;
public:
	TPostfix(string a = "a+b")
  {
	  infix = a;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  double Helper(double a, double b, char c)
  {
	  switch (c)
	  {
		  case '+':
		  {
			  return a + b;
		  }
		  case '-':
		  {
			  return a - b;
		  }
		  case '*':
		  {
			  return a * b;
		  }
		  case '/':
		  {
			  return a / b;
		  }
		  default:
			  throw;
	  }
  }
  void ToPostfix()
  {
	  TStack<char> a(MaxStackSize);
	  do
	  {
		  char c = infix[i];
		  if ((c == '+') || (c == '-'))
			  prior = 1;
		  if ((c == '*') || (c == '/'))
			  prior = 2;
		  if ((c == '(') || (c == ')'))
			  prior = 0;
		  if ((c != '+') && (c != '-') && (c != '/') && (c != '*') && (c != '(') && (c != ')'))
		  {
			  int j = i;
			  char s = infix[j];
			  while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '/') && (infix[j] != '*') && (infix[j] != ')') && (j != infix.size()))
			  {
				  postfix.push_back(infix[j]);
				  j++;
			  }
			  i = j - 1;
			  postfix.push_back(',');
		  }
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
					  while ((!a.IsEmpty()) && (a.Top_el() != '('))
					  {
						  postfix.push_back(a.pop());
						  postfix.push_back(',');
					  }	
					  if (a.Top_el() == '(')
						  a.pop();
				  }
				  while ((!a.IsEmpty()) && (prior <= a.Prior()) && (a.Top_el() != '('))
				  {
						 postfix.push_back(a.pop());
						 postfix.push_back(',');
				  }
				  if ((c == '(') || (c == ')'))
					  ;
				  else
					 a.push(c);
			  }
		  }
		  i++;
	  } while (infix[i] != NULL);
	  while ((infix[i] == NULL) && (!a.IsEmpty()))
	  {
		  postfix.push_back(a.pop());
		  postfix.push_back(',');
	  }
	  postfix.back() = ' ';
  }
  double Calculate() // Ввод переменных, вычисление по постфиксной форме*/
  {
	  ToPostfix();
	  string tmp;
	  TStack<double> b(infix.size());
	  for (int i = 0; i < postfix.size(); i++)
	  {
		  if ((postfix[i] != '+') && (postfix[i] != '-') && (postfix[i] != '/') && (postfix[i] != '*'))
		  {
			  while (postfix[i] != ',')
			  {
				  tmp += postfix[i];
				  i++;
			  }
			  b.push(stof(tmp));
			  tmp.clear();
		  }
		  else
		  {
			  if (b.IsEmpty())
				  throw;
			  else
			  {
				  b.push(Helper(b.pop(), b.pop(), postfix[i]));
				  i++;
			  }
		  }
	  }
	  return b.Top_el();
  }
};
#endif