//225.用队列实现栈

#include <queue>

using namespace std;


class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		while (!Q1.empty()) {
			Q2.push(Q1.front());
			Q1.pop();
		}
		Q1.push(x);
		while (!Q2.empty()) {
			Q1.push(Q2.front());
			Q2.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int res = Q1.front();
		Q1.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		return Q1.front();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (Q1.empty()) return true;
		else return false;
	}
private:
	queue<int> Q1;
	queue<int> Q2;
	int peek;
};

class MyStack2 {
public:
	/** Initialize your data structure here. */
	MyStack2() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		Q1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int size = Q1.size();
		for (int i = 0; i < size - 1; i++) {
			Q1.push(Q1.front());
			Q1.pop();
		}
		int res = Q1.front();
		Q1.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		return Q1.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		if (Q1.empty()) return true;
		else return false;
	}
private:
	queue<int> Q1;
	//queue<int> Q2;
	//int peek;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */