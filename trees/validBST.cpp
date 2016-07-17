/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node’s key.
 * The right subtree of a node contains only nodes with keys greater than the node’s key.
 * Both the left and right subtrees must also be binary search trees.
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

int isBSTHelper(TreeNode* A, int max, int min) {

	if (A == NULL) {
		return 1;
	}

	if (A->val < max && A->val > min) {
		if (isBSTHelper(A->left, A->val, min) && isBSTHelper(A->right, max, A->val)) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}

}

int Solution::isValidBST(TreeNode* A) {

	if (A == NULL)
		return 1;

	int result = isBSTHelper(A, INT_MAX, INT_MIN);

	return result;
}
