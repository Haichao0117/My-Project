//155.最小栈

#include <stack>

using namespace std;

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