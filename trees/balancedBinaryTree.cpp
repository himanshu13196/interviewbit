/**
 * Given a binary tree, determine if it is height-balanced.
 * Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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

int isBalancedHelper(TreeNode *A, int &result) {

	if (A == NULL) {
		return 0;
	} else {

		int ldepth = isBalancedHelper(A->left, result);
		int rdepth = isBalancedHelper(A->right, result);
		int diff = ldepth - rdepth;

		if (diff > 1 || diff < -1) {
			result = 0;
		}
		return (max(ldepth, rdepth)) + 1;
	}

}

int Solution::isBalanced(TreeNode* A) {

	int result = 1;

	isBalancedHelper(A, result);

	return result;

}
