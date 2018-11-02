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
  bool NotOperation(char c);
  bool IsValidByBrackets();
  bool IsValidByOpers();
  bool IsValidByPos();
  bool IsValidInTotal();
  double Helper(double a, double b, char c);
  void ToPostfix();
  double Calculate();
};
#endif