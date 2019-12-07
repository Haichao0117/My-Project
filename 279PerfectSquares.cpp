//279.完全平方数
//此种方法会造成节点的多次访问,但不影响结果.

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
		return 0;						//此处不加return 0,leetcode编译不通过.
	}
};