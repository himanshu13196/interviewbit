/**
 * Given a binary tree, return the preorder traversal of its nodes’ values.
 * Using recursion is not allowed.
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
vector<int> Solution::preorderTraversal(TreeNode* A) {

	vector<int> result;

	if (A == NULL)
		return result;

	TreeNode * itr = A;
	stack<TreeNode *> rgtSub;

	while (1) {
		result.push_back(itr->val);

		if (itr->right != NULL)
			rgtSub.push(itr->right);

		if (itr->left != NULL) {
			itr = itr->left;
		} else if (!rgtSub.empty()) {
			itr = rgtSub.top();
			rgtSub.pop();
		} else {
			break;
		}

	}

	return result;
}
