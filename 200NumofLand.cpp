

#include <queue>
#include <vector>

using namespace std;

class NumofLands {
public:
	int numsIsLands(vector<vector<char>>& grid) {
		position offset[4];
		offset[0].row = 0; offset[0].col = 1;	//��
		offset[1].row = 1; offset[1].col = 0;	//��
		offset[2].row = 0; offset[2].col = -1;	//��
		offset[3].row = -1; offset[3].col = 0;	//��

		queue <position> q;

		//��ʼ������
		int size_row = grid.size();			//����
		if (size_row == 0)					//�ж������Ƿ�Ϊ��
			return 0;
		int size_col = grid[0].size();		//����

		//���԰�������д�ķ�����ӱ߽�
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
							if (nbr.row < 0 || nbr.row >= size_row || nbr.col < 0 || nbr.col >= size_col)	//�ж��Ƿ�Ϊ�߽磬����ǣ���������ǰѭ��
								continue;
							if (grid[nbr.row][nbr.col] == '1')
							{
								q.push(nbr);
								grid[nbr.row][nbr.col] = '0';		//���߹��ĵ���Ϊ��0������ֹ�ظ�����
							}
						}
						if (q.empty())		//ֱ������Ϊ�գ�����ѭ��
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
