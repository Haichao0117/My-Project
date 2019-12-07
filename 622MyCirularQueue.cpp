//622.���ѭ������


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
		tail = -1;                //tail��ʼ��Ϊ-1���������Ѱ�Ҷ�βԪ�ء��������Ϊ0���ڻ�ȡ��βԪ��ʱҪ�ж�tail�Ƿ�Ϊ0
		length = k;
		count = 0;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull())
			return false;
		else
		{
			tail = (tail + 1) % length;		//������һ��tail��ֵ
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