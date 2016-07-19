/**
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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

int sameTreeHelper(TreeNode* &A, TreeNode* &B) {

	if ((A != NULL && B != NULL) && A->val == B->val) {

		return (sameTreeHelper(A->left, B->left) && sameTreeHelper(A->right, B->right));

	} else if (A == NULL && B == NULL) {
		return 1;
	} else {
		return 0;
	}

}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {

	return sameTreeHelper(A, B);

}
