// MyProject_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <math.h>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;


//完全平方数
//此种方法会造成节点的多次访问,但不影响结果.
class PerfectSquares {
public:
	int numSquares(int n) {

		queue < pair<int, int> > q;
		pair <int, int> p;
		int step = 0;
		p = make_pair(n, step);
		q.push(p);
		while (!q.empty())
		{
			pair <int, int> p1 = q.front();
			q.pop();
			for (int i = 1; p1.first - pow(i, 2) >= 0; i++)
			{
				if (p1.first - pow(i, 2) == 0)
				{
					return p1.second + 1;
					break;
				}
				p = make_pair(p1.first - pow(i, 2), p1.second + 1);
				q.push(p);
			}

		}
		return 0;						//此处不加return 0,leetcode编译不通过.
	}
};


class DailyTemp {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector <int> result(T.size(), 0);
		stack <int> temp_index;
		//temp_index.push(0);
		for (int i = 0; i < T.size(); i++)
		{

			if (temp_index.empty() || T[temp_index.top()] >= T[i])
			{
				temp_index.push(i);
			}
			else
			{
				while (!temp_index.empty() && T[temp_index.top()] < T[i])					//要注意判断栈是否为空，否则没有top()，程序会报错 outof range
				{
					result[temp_index.top()] = i - temp_index.top();
					temp_index.pop();
				}
				temp_index.push(i);
			}

		}
		return result;
	}
};


class EvaluateReversePolishNotation {
public:
	int evalRPN(vector<string>& tokens) {
		stack <string> polish;
		int m;
		int n;
		for (int i = 0; i < tokens.size(); i++)
		{
			/*switch (tokens[i])						//C++中，switch case 不能处理字符串.sad.
			{
				case
			}*/
			if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
			{
				polish.push(tokens[i]);
			}
			else if (tokens[i] == "+")
			{
				m = stoi(polish.top());
				polish.pop();
				n = stoi(polish.top());
				polish.pop();
				polish.push(to_string(m + n));
			}
			else if (tokens[i] == "-")
			{
				m = stoi(polish.top());
				polish.pop();
				n = stoi(polish.top());
				polish.pop();
				polish.push(to_string(n - m));
			}
			else if (tokens[i] == "*")
			{
				m = stoi(polish.top());
				polish.pop();
				n = stoi(polish.top());
				polish.pop();
				polish.push(to_string(n * m));
			}
			else if (tokens[i] == "/")
			{
				m = stoi(polish.top());
				polish.pop();
				n = stoi(polish.top());
				polish.pop();
				polish.push(to_string(n / m));
			}
		}
		return stoi(polish.top());
	}
};



// Definition for a Node.
//test
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class CloneGraph {
public:
	Node* cloneGraph(Node* node) {

		unordered_map<Node*, int> vis;
		unordered_map<Node*, Node*> hash;

		return dfs(node, vis, hash);

	}
	Node* dfs(Node* node,
		unordered_map<Node*, int>& vis,
		unordered_map<Node*, Node*>& hash) {
		if (!node) return node;
		if (vis.count(node)) return hash[node];
		Node* nd = new Node(node->val, vector<Node*>(node->neighbors.size(), NULL));
		hash[node] = nd;
		vis[node] = 1;
		for (int i = 0; i < node->neighbors.size(); ++i) {
			Node* nb = node->neighbors[i];
			Node* new_nb = dfs(nb, vis, hash);
			nd->neighbors[i] = new_nb;
		}
		return nd;
	}


};





int main()
{
	std::cout << "Hello World!\n";


	/*PerfectSquares nums;
	int result =nums.numSquares(12);
	cout << result << endl;*/

	/*DailyTemp temp;
	vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	vector <int>result = temp.dailyTemperatures(temperatures);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result.at(i) << endl;
	}*/
	/*vector <int>::iterator result = temp.dailyTemperatures(temperatures).begin();
	cout << *result << endl;*/

	EvaluateReversePolishNotation reverse;
	vector<string> test = { "2","1","+","3","*" };
	int result = reverse.evalRPN(test);
	cout << result << endl;

	Node node;


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
