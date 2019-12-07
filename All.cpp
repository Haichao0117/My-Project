// MyProject_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <math.h>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;


//279.完全平方数
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
			/*switch (tokens[i])						//C++中，switch case 不能处理字符串.sad:(
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



//622.设计循环队列
class MyCircularQueue {
private:
	int* data;
	int head;
	int tail;
	int length;
	int count;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		data = new int[k];
		head = 0;
		tail = -1;                //tail初始化为-1，方便后面寻找队尾元素。如果设置为0，在获取队尾元素时要判断tail是否为0
		length = k;
		count = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull())
			return false;
		else
		{
			tail = (tail + 1) % length;		//计算下一个tail的值
			data[tail] = value;
			count++;
			return true;
		}
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty())
			return false;
		else
		{
			head = (head + 1) % length;
			count--;
			return true;
		}
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty())
			return -1;
		else
			return data[head];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty())
			return -1;
		else
			return data[tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if (count == 0)
		{
			return true;
		}
		else
			return false;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if (count == length)
		{
			return true;
		}
		else
			return false;
	}
};

//200.岛屿数量
class NumofLands {
public:
	int numsIsLands(vector<vector<char>>& grid) {
		position offset[4];
		offset[0].row = 0; offset[0].col = 1;	//右
		offset[1].row = 1; offset[1].col = 0;	//下
		offset[2].row = 0; offset[2].col = -1;	//左
		offset[3].row = -1; offset[3].col = 0;	//上

		queue <position> q;

		//初始化方阵
		int size_row = grid.size();			//行数
		if (size_row == 0)					//判断输入是否为空
			return 0;
		int size_col = grid[0].size();		//列数

		//尝试加边界，失败
		//grid.resize(size_row + 2);
		//for (int i = 0; i <= size_row + 1; i++)
		//{
		//	grid[i].resize(size_col + 2);
		//	//grid[i][0] = grid[i][size_col + 1] = 0;
		//}
		//
		//for (int i = size_row; i > 0; i--)
		//{
		//	for (int j = size_col; j > 0; j--)
		//	{
		//		grid[i][j] = grid[i - 1][j - 1];
		//	}
		//}
		//
		////for (int i = 0; i <= size_row + 1; i++)
		////{
		////	//grid[i].resize(size_col + 2);
		////	grid[i][0] = grid[i][size_col + 1] = 0;
		////}
		//for (int i = 0; i <= size_row+1; i++)
		//{
		//	grid[i][0] = grid[i][size_col + 1] = 0;
		//}
		//for (int i = 0; i <= size_col+1; i++)
		//{
		//	grid[0][i] = grid[size_row + 1][i] = 0;
		//}

		position here, nbr;
		int nums = 0;
		for (int r = 0; r < size_row; r++)
		{
			for (int c = 0; c < size_col; c++)
			{
				if (grid[r][c] == '1')
				{
					here.row = r;
					here.col = c;
					nums++;
					while (true)
					{
						for (int i = 0; i < 4; i++)
						{
							nbr.row = here.row + offset[i].row;
							nbr.col = here.col + offset[i].col;
							if (nbr.row < 0 || nbr.row >= size_row || nbr.col < 0 || nbr.col >= size_col)	//判断是否为边界，如果是，则跳出当前循环
								continue;
							if (grid[nbr.row][nbr.col] == '1')
							{
								q.push(nbr);
								grid[nbr.row][nbr.col] = '0';		//将走过的点置为‘0’，防止重复搜索
							}
						}
						if (q.empty())		//直到队列为空，结束循环
							break;
						here = q.front();
						q.pop();
					}
				}
			}
		}
		return nums;
	}
private:
	class position {
	public:
		int row;
		int col;
	};
};




//递归 Hanoi tower
void towerOfHanoi(int n, int x, int y, int z)
{
	if (n > 0)
	{
		towerOfHanoi(n - 1, x, z, y);
		cout << "Move top disk from tower " << x
			<< "to top of tower " << y << endl;
		towerOfHanoi(n - 1, z, y, x);
	}
}

//155.最小栈
class MinStack {
public:
	/** initialize your data structure here. */

	MinStack() {

	}

	void push(int x) {
		stack1.push(x);
		if (min.empty() || x <= min.top())				//这里要用<=,因为如果存在相同的最小值，经过一次pop后，min里的最小值就发生了变化。
		{
			min.push(x);
		}
	}

	void pop() {
		if (min.top() == stack1.top())
		{
			stack1.pop();
			min.pop();
		}
		else
		{
			stack1.pop();
		}
	}

	int top() {
		return stack1.top();
	}

	int getMin() {
		return min.top();
	}
private:
	stack <int> stack1;
	stack <int> min;
};
/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/

//20.有效的括号
class ValidBrackets {
public:
	bool isValid(string s) {
		stack<char> Bracket;
		int num = s.length();
		char a;
		for (int i = 0; i < s.length(); i++)			//s.length()是unsigned int，这里会警告
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
		//if ((a == "(" && b == ")") || (a == "[" && b == "]") || (a == "{" && b == "}"))		//"A"代表了一个字符串，存储形式是A\0;而'A'代表一个字符，存储形式是A
		if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
			return true;
		else return false;
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


	//622.设计循环队列
	/**
	* Your MyCircularQueue object will be instantiated and called as such:
	* MyCircularQueue* obj = new MyCircularQueue(k);
	* bool param_1 = obj->enQueue(value);
	* bool param_2 = obj->deQueue();
	* int param_3 = obj->Front();
	* int param_4 = obj->Rear();
	* bool param_5 = obj->isEmpty();
	* bool param_6 = obj->isFull();
	*/


	//200.岛屿数量
   /*
   vector<vector<char>> vec = { { '1', '1', '1', '1', '0' }, { '1', '1', '0', '1', '0' }, { '1', '1', '0', '0', '0' }, { '0', '0', '0', '0', '0' } };
   vector<vector<char>> vec1 = {};
   NumofLands Num;
   int a =Num.numsIsLands(vec1);
   cout << a << endl;
   */


   //20.有效的括号
   /*ValidBrackets* bracket = new ValidBrackets();
   bool result = bracket->isValid("()");
   cout << result << endl;*/


   //739.每日温度
   //DailyTemp daily;
   //DailyTemp* dailytemp = new DailyTemp();
   //vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
   ////daily.dailyTemperatures(temperatures);
   //vector<int> result = dailytemp->dailyTemperatures(temperatures);
   //

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
