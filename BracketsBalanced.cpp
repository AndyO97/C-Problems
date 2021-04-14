// CPP program to check for balanced brackets with characters in between.

#include <bits/stdc++.h>
using namespace std;

// function to check if brackets are balanced
bool BracketsBalanced(string expr)
{
	stack<char> s;
	char x;

	// Traversing the string
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '['
			|| expr[i] == '{')
		{
			// Push the element in the stack
			s.push(expr[i]);
			continue;
		}

		// If current current character is closing and the stack
		// is empty,then it should be false
		if (expr[i] == ')' || expr[i] == ']'
			|| expr[i] == '}')
		{
			if(s.empty())
			return false;
		//Check if it matches with the last stored opening bracket   
	    switch (expr[i]) {
		case ')':
			
			// Store the top element in a
			x = s.top();
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':

			// Store the top element in b
			x = s.top();
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			// Store the top element in c
			x = s.top();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
		}

		
	}

	// Check Empty Stack
	return (s.empty());
}

// Main coode to try the function
int main()
{
	string expr = "{if(a==10) print b;}[]";

	// Function call
	if (BracketsBalanced(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}

