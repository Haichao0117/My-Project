//66.ÿ������
#include <vector>
#include <stack>

using namespace std;


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
				while (!temp_index.empty() && T[temp_index.top()] < T[i])					//Ҫע���ж�ջ�Ƿ�Ϊ�գ�����û��top()������ᱨ�� outof range
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