/**
 * Given a binary tree, return the postorder traversal of its nodes’ values.
 * Using Recursion is not allowed
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
vector<int> Solution::postorderTraversal(TreeNode* A) {

	vector<int> result;
	stack<TreeNode *> lftSub;
	TreeNode *itr = A;

	if (A == NULL)
		return result;

	while ((!lftSub.empty()) || itr) {

		result.push_back(itr->val);

		if (itr->left != NULL) {
			lftSub.push(itr->left);
		}

		if (itr->right != NULL) {
			itr = itr->right;
		} else if (!lftSub.empty()) {
			itr = lftSub.top();
			lftSub.pop();
		} else {
			break;
		}

	}

	int i = 0;
	int j = result.size() - 1;

	while (i < j) {
		swap(result[i], result[j]);
		i++;
		j--;
	}

	return result;
}
