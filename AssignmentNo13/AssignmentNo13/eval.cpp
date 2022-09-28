// fritz ammon
// cs 202 section 1002
// assignment 13
// description: evaluation program that
// tests the linkedStack class
// will test by postfix expressions

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <sstream>
#include <cmath>
#include "linkedStack.h"

using std::cout;
using std::cin;
using std::endl;
using std::isdigit;
using std::pow;

void releaseSStream(std::stringstream& stream);
int fail(const char *);
bool isValidNumber(char *);

int main(int argc, char **argv) // argument count and vector
{
	linkedStack<int> stack;
	int count;
	int operand, a, b;
	char operate;
	std::string strCpy;
	std::stringstream cinCpy;

	if (argc <= 2) // not enough parameters
		return fail("Usage: ./eval -c <countValue>\n");

	if (strcmp(argv[1], "-c")) // does not match '-c'
		return fail("Error, must specify '-c' count specifier.\n");
		
	if (!isValidNumber(argv[2])) // is not a number
		return fail("Error, must provide expression prompt count.\n");

	std::sscanf(argv[2], "%d", &count);

	for (int expression = 0; expression < count; expression++)
	{
		cout << "------------------------------------------------------------\n";
		cout << "Enter Postfix Expression:\n";

		strCpy = "";
		while (strCpy == "")
			std::getline(cin, strCpy); // So we can print out the expression later

		cinCpy.clear();
		cinCpy.str(strCpy); // To let us easily strip out what we need
		cout << std::endl;

		while ((operand = cinCpy.peek()) != -1) // stop when eof reached
		{
			if (operand == ' ')
			{
				operand = cinCpy.get(); // pull from stream and continue
				continue;
			}

			if (isdigit(operand)) // start of read is number
			{
				cinCpy >> operand; // read the entire number
				stack.push(operand); // add to stack
			}
			else
			{
				cinCpy >> operate; // pull out of stream

				if (stack.stackCount() < 2) // should be two operands
				{
bad_expression:
					cout << "Error, invalid expression.\n\n";

					stack.deleteStack(); // destroy

					continue;			 // and continue to next expression
				}

				a = stack.pop();
				b = stack.pop();

				// Swap a and b
				a ^= b;
				b ^= a;
				a ^= b;

				// determine operation and save result
				switch (operate)
				{
				case '+':
					stack.push(a + b);
					break;
				case '-':
					stack.push(a - b);
					break;
				case '*':
					stack.push(a * b);
					break;
				case '/': // Know that this should be a double
					if (b == 0) // division by zero
						goto bad_expression;

					stack.push(a / b);
					break;
				case '%': // why not? it shows up as invalid in the pdf
					if (b == 0) // division by zero
						goto bad_expression;

					stack.push(a % b);
					break;
				// so i assume anything but what is on the pdf is invalid...
				case '^':
					stack.push((int) pow((double) a, (double)b));
					break;
				default:
					goto bad_expression;
				}
			}
		}

		if (stack.stackCount() == 0) // was a bad expression
			continue;

		if (stack.stackCount() != 1)
			goto bad_expression;

		cout << "Postfix expression: " << cinCpy.str() << endl
			 << " evalulated is " << stack.pop() << endl;
		cout << endl;
	}

	return 0;
}

int fail(const char *szErr)
{
	cout << szErr;

	return 1;
}

bool isValidNumber(char *szArg)
{
	size_t size = strlen(szArg);

	for (size_t i = 0; i < size; i++)
	{
		if (!isdigit(szArg[i]))
			return false;
	}

	return true;
}