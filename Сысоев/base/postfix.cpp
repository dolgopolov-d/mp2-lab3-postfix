
#include "postfix.h"
#include "stack.h"

void TPostfix::ToPostfix()
{
	TStack<char> a(MaxStackSize);
	do
	{
		if (!IsValidInTotal())
			throw "Error";
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

double TPostfix::Calculate()
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
double TPostfix::Helper(double a, double b, char c)
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
bool TPostfix::IsValidByBrackets()
{
	int left = 0, right = 0;
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
			left++;
		if (infix[i] == ')')
			right++;
	}
	if (right == left)
		return true;
	else
		return false;
}
bool TPostfix::IsValidByOpers()
{
	int operands = 0, operations = 0;
	for (int i = 0; i < infix.size(); i++)
	{
		if ((infix[i] == '(') || (infix[i] == ')'))
			continue;
		if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/'))
			operations++;
		else
			if ((infix[i] != '+') && (infix[i] != '-') && (infix[i] != '*') && (infix[i] != '/'))
			{
				while ((infix[i] != '+') && (infix[i] != '-') && (infix[i] != '*') && (infix[i] != '/') && (i != infix.size()))
					i++;
				i--;
				operands++;
			}
	}
	if (operands - 1 == operations)
		return true;
	else
		return false;
}
bool TPostfix::IsValidByPos()
{
	int i = 0;
	string last = "operand", current;
	if ((infix[0] == '+') || (infix[0] == '-') || (infix[0] == '*') || (infix[0] == '/'))
		return false;
	if (infix[0] == ')')
		return false;
	if (infix[0] == '(')
		last = "left bracket";
	else
	{
		while ((infix[i] != '+') && (infix[i] != '-') && (infix[i] != '*') && (infix[i] != '/') && (i != infix.size()))
			i++;
		last = "operation";
	}
	for (int j = i + 1; j < infix.size(); j++)
	{
		if (infix[j] == '(')
			current = "left bracket";
		else
			if (infix[j] == ')')
				current = "right bracket";
			else
				if ((infix[j] == '+') || (infix[j] == '-') || (infix[j] == '*') || (infix[j] == '/'))
					current = "operation";
				else
					if ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/'))
					{
						while ((infix[j] != '+') && (infix[j] != '-') && (infix[j] != '*') && (infix[j] != '/') && (j != infix.size()))
							j++;
						j--;
						current = "operand";
					}
		if ((current == last && current !="left bracket" && current != "right bracket") || (last == "left bracket" && current == "right bracket"))
			return false;
		last = current;
	}
	return true;
}
bool TPostfix::IsValidInTotal()
{
	if (!IsValidByBrackets() || !IsValidByOpers() || !IsValidByPos())
		return false;
	return true;
}