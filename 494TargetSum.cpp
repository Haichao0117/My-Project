//494.Ŀ���
//û���õ�ջ
#include <vector>

using namespace std;


class TargetSum {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int res = 0;
		int sum = 0;
		DFSsolution(nums, S, 0, sum, res);
		return res;
	}
	void DFSsolution(vector<int>& nums, int S, int i, int sum, int& res)
	{
		if (i == nums.size()) {
			if (sum == S) {
				++res;
			}
			return;
		}
		DFSsolution(nums, S, i + 1, sum + nums[i], res);
		DFSsolution(nums, S, i + 1, sum - nums[i], res);

	}
};
