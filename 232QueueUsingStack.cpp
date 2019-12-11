//232.��ջʵ�ֶ���
//���˱��˵Ľⷨ���Լ�д��û�õĶ���̫���ˣ�ѭ������ֱ����while(!empty()),���ø��ˣ��ο�������

#include <stack>

using namespace std;


class  MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		int size1 = S1.size();
		for (int i = 0; i < size1; i++) {
			S2.push(S1.top());
			S1.pop();
		}
		S1.push(x);
		int size2 = S2.size();
		for (int i = 0; i < size2; i++) {
			S1.push(S2.top());
			S2.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int res = S1.top();
		S1.pop();
		return res;
	}

	/** Get the front element. */
	int peek() {
		return S1.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (S1.empty()) return true;
		//if (!S1.empty()) return false;						//����Ҫ����ֵ��������д��Ȼ�ڱ��ر������ͨ��������leetcode�ϻᱨcontrol reaches end of non-void function [-Werror=return-type]����
		else return false;
	}
private:
	stack<int> S1;
	stack<int> S2;

};

class  MyQueue2 {
public:
	/** Initialize your data structure here. */
	MyQueue2() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		if (S1.empty()) front = x;
		S1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (S2.empty()) {
			while (!S1.empty()) {
				S2.push(S1.top());
				S1.pop();
			}
		}
		int res = S2.top();
		S2.pop();
		return res;
	}

	/** Get the front element. */
	int peek() {
		if (!S2.empty()) return S2.top();
		else return front;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		if (S1.empty() && S2.empty()) return true;
		else return false;
	}
private:
	stack<int> S1;
	stack<int> S2;
	int front;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */