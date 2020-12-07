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

int main()
{
	string a = "(1+2+)*(2/0)";
	check(a);
	cout << a << endl;
	

}
