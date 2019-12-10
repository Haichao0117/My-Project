//94.InorderTraversal
//94.���������������
//����ǰ�����������������õĵ����ķ�����û���õ�DFS���Ժ��л���������

#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class InorderTraversal {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		inOrder(root, result);
		return result;
	}
	void inOrder(TreeNode* t, vector<int>& R) {
		if (t != NULL) {
			inOrder(t->left, R);
			R.push_back(t->val);
			inOrder(t->right, R);
		}
	}
	void preOrder(TreeNode* t, vector<int>& R) {
		if (t != NULL) {
			R.push_back(t->val);
			inOrder(t->left, R);
			inOrder(t->right, R);
		}
	}
	void postOrder(TreeNode* t, vector<int>& R) {
		if (t != NULL) {
			inOrder(t->left, R);
			inOrder(t->right, R);
			R.push_back(t->val);
		}
	}
};