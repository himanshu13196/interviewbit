/**
 * Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

	vector < vector<int> > result;

	if (A == NULL)
		return result;

	stack<TreeNode *> trav1;
	stack<TreeNode *> trav2;
	int flag = 0;
	TreeNode *temp;

	trav1.push(A);

	while (1) {
		vector<int> itr;
		if (flag % 2 == 0) {
			if (!trav1.empty()) {
				while (!trav1.empty()) {
					temp = trav1.top();
					itr.push_back(temp->val);
					if (temp->left) {
						trav2.push(temp->left);
					}
					if (temp->right) {
						trav2.push(temp->right);
					}
					trav1.pop();
				}
				result.push_back(itr);
			} else {
				break;
			}
		} else {
			if (!trav2.empty()) {
				while (!trav2.empty()) {
					temp = trav2.top();
					itr.push_back(temp->val);

					if (temp->right) {
						trav1.push(temp->right);
					}

					if (temp->left) {
						trav1.push(temp->left);
					}
					trav2.pop();
				}
				result.push_back(itr);

			} else {
				break;
			}
		}

		flag++;
	}

	return result;

}
