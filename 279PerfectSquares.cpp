//279.��ȫƽ����
//���ַ�������ɽڵ�Ķ�η���,����Ӱ����.

#include <queue>

using namespace std;

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
		return 0;						//�˴�����return 0,leetcode���벻ͨ��.
	}
};