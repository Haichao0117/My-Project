//20.��Ч������

#include <stack>
#include <string>

using namespace std;

class ValidBrackets {
public:
	bool isValid(string s) {
		stack<char> Bracket;
		int num = s.length();
		char a;
		for (int i = 0; i < s.length(); i++)			//s.length()��unsigned int������ᾯ��
		{

			if (Bracket.empty() || !pair(Bracket.top(), s[i]))
			{
				Bracket.push(s[i]);
				a = Bracket.top();
			}
			else if (pair(Bracket.top(), s[i]))
			{
				Bracket.pop();
			}
		}
		if (Bracket.empty()) return true;
		else return false;
	}
	bool pair(char a, char b)
	{
		//if ((a == "(" && b == ")") || (a == "[" && b == "]") || (a == "{" && b == "}"))		//"A"������һ���ַ������洢��ʽ��A\0;��'A'����һ���ַ����洢��ʽ��A
		if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
			return true;
		else return false;
	}
};
