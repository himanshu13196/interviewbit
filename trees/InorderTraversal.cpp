/**
 * Given a binary tree, return the inorder traversal of its nodes’ values.
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
vector<int> Solution::inorderTraversal(TreeNode* A) {

	vector<int> result;
	stack<TreeNode*> visited;

	if (A == NULL) {
		return result;
	}

	TreeNode *itr = A;

	while (1) {

		if (itr->left == NULL) {
			result.push_back(itr->val);

			if (itr->right == NULL) {

				while ((!visited.empty()) && (visited.top()->right == NULL)) {
					result.push_back(visited.top()->val);
					visited.pop();
				}

				if (visited.empty()) {
					break;
				} else {
					result.push_back(visited.top()->val);
					itr = visited.top()->right;
					visited.pop();
				}

			} else {
				itr = itr->right;
			}

		} else {
			visited.push(itr);
			itr = itr->left;
		}

	}

	return result;

}
