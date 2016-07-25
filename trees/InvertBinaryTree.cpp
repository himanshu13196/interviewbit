/**
 * Given a binary tree, invert the binary tree and return it.
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

void invertHelper(TreeNode* &lroot, TreeNode* &rroot) {

	swap(lroot, rroot);

	if (lroot != NULL) {
		invertHelper(lroot->left, lroot->right);
	}

	if (rroot != NULL) {
		invertHelper(rroot->left, rroot->right);
	}

	return;
}

TreeNode* Solution::invertTree(TreeNode* root) {

	if (root == NULL)
		return root;

	invertHelper(root->left, root->right);

	return root;
}
