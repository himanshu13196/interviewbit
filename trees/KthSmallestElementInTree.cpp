/**
 * Given a binary search tree, write a function to find the kth smallest element in the tree.
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
void traversal(TreeNode *curr, int &count, const int &k, int &result) {

	if (curr == NULL)
		return;

	traversal(curr->left, count, k, result);
	if (count >= k)
		return;
	count++;
	if (count == k)
		result = curr->val;
	traversal(curr->right, count, k, result);

	return;
}

int Solution::kthsmallest(TreeNode* root, int k) {

	int count = 0;
	int result;

	traversal(root, count, k, result);

	return result;
}
