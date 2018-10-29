#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  TPostfix Postfix;
  double res;

  setlocale(LC_ALL, "Russian");
  //cout << "Введите арифметическое выражение: ";
  //cin >> expression;
  //cout << expression << endl;
  cout << "Арифметическое выражение: " << Postfix.GetInfix() << endl;
  Postfix.ToPostfix();
  cout << "Постфиксная форма: " << Postfix.GetPostfix() << endl;
  /*
  res = postfix.Calculate();
  cout << res << endl;
  */
  return 0;
}
