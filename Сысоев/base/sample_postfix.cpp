#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  double res;
  int enter = 0;
  setlocale(LC_ALL, "Russian");
  cout << "1.Постфиксная форма" << endl;
  cout << "2.Подсчет" << endl;
  cin >> enter;
  switch (enter)
  {
	  case 1:
	  {
		  cout << "Введите арифметическое выражение: " << endl;
		  cin >> expression;
		  TPostfix Postfix(expression);
		  if (!Postfix.IsValidInTotal())
			  throw "Error";
		  cout << "Арифметическое выражение: " << expression << endl;
		  Postfix.ToPostfix();
		  cout << "Постфиксная форма: " << Postfix.GetPostfix() << endl;
		  break;
	  }
	  case 2:
	  {
		  cout << "Введите арифметическое выражение: " << endl;
		  cin >> expression;
		  TPostfix Postfix(expression);
		  if (!Postfix.IsValidInTotal())
			  throw "Error";
		  cout << "Арифметическое выражение: " << expression << endl;
		  res = Postfix.Calculate();
		  cout << res << endl;
		  break;
	  }
	  default:
		  break;
  }
  return 0;
}
