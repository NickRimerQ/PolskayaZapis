#include <iostream>
#include <stack>
#include <string>
using namespace std;

int check(string &example)
{
	for (int i = 0; i < example.length(); i++)
	{
		if (example[i] == ' ') 
		{
			example.erase(i, 1);
			i--;
		}
			
	}
	int counter = 0;
	stack<char> CheckStack;
	for (int i = 0; i < example.length(); i++)
	{
		switch (example[i]) 
		{
		case'(':
			CheckStack.push(i);
			break;
		case')':
			if (CheckStack.empty())
			{
				counter++;
			}
			else
			{
				CheckStack.pop();
			}
			break;

		case'+':
			if ((i - 1) >= 0 && (i + 1) < example.length())
			{
				if (example[i + 1] == '+' || example[i + 1] == '-' || example[i + 1] == '*' || example[i + 1] == '/' || example[i - 1] == '(' || example[i + 1] == ')')
				{
					counter++;
				}
			}
			else
			{
				counter++;
			}
			break;

		case'-':
			if ((i - 1) >= 0 && (i + 1) < example.length())
			{
				if (example[i + 1] == '-' || example[i + 1] == '+' || example[i + 1] == '*' || example[i + 1] == '/' || example[i - 1] == '(' || example[i + 1] == ')')
				{
					counter++;
				}
			}			
			else
			{
				counter++;
			}
			break;

		case'*':
			if ((i - 1) >= 0 && (i + 1) < example.length())
			{
				if (example[i + 1] == '*' || example[i + 1] == '/' || example[i + 1] == '+' || example[i + 1] == '-' || example[i - 1] == '(' || example[i + 1] == ')')
				{
					counter++;
				}
			}
			else
			{
				counter++;
			}
			break;

		case'/':
			if ((i - 1) >= 0 && (i + 1) < example.length() && example[i + 1] != '0')
			{
				if (example[i + 1] == '/' || example[i + 1] == '*' || example[i + 1] == '+' || example[i + 1] == '-' || example[i - 1] == '(' || example[i + 1] == ')')
				{
					counter++;
				}
			}
			else
			{
				counter++;
			}
			break;
		
		default:
			continue;
		}
	}
	while(CheckStack.empty() != 1)
	{
		counter++;
		CheckStack.pop();
	}
	cout << "Number of spelling mistakes: " << counter << endl;
	return counter;
}

string polskayaZapis(string str)
{
	cout << "Initial example: " << str << endl;
	string outputLine;
	stack<char> StackAfterALL;
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '+':
		case '-':
			if (StackAfterALL.empty() != 1) 
			{
				if (StackAfterALL.top() == '*' || StackAfterALL.top() == '/')
				{
					char temp = StackAfterALL.top();
					StackAfterALL.pop();
					StackAfterALL.push(str[i]);
					StackAfterALL.push(temp);
					continue;
				}
			}
			StackAfterALL.push(str[i]);
			continue;
		
		case '*':
		case '/':
			StackAfterALL.push(str[i]);
			continue;

		case '(':
			StackAfterALL.push(str[i]);
			continue;

		case ')':
			while(StackAfterALL.top() != '(')
			{
				outputLine.push_back(StackAfterALL.top());
				StackAfterALL.pop();
			}
			StackAfterALL.pop();
			continue;
		}
		outputLine.push_back(str[i]);
	}
	
	while(StackAfterALL.empty() != 1)
	{
		outputLine.push_back(StackAfterALL.top());
		StackAfterALL.pop();
	}
	cout << "Polish notation: " << outputLine << endl;
	return outputLine;
}


int main()
{
	string a = "(1+2+)*(2/0)";
	check(a);
	cout << a << endl;

	return 0;
}
