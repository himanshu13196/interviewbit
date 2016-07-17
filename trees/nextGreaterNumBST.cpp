/**
 * Given a BST node, return the node which has value just greater than the given node.
 * Using recursion is not allowed.
 * Assume that the value is always present in the tree.
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

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {

	if (A == NULL)
		return NULL;

	TreeNode* result = NULL;

	TreeNode* searchNode = A;

	while (1) {

		if (searchNode->val <= B) {
			if (searchNode->right == NULL) {
				return result;
			} else {
				searchNode = searchNode->right;
			}
		} else {
			result = searchNode;

			if (searchNode->left == NULL) {
				return result;
			} else {
				searchNode = searchNode->left;
			}

		}

	}

	return result;

}

