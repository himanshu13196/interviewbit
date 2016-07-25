/**
 * Given a binary tree, flatten it to a linked list in-place.
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
void Traversal(TreeNode* curr, TreeNode* &prev) {
	if (curr == NULL)
		return;

	prev->left = curr;
	prev = curr;

	Traversal(curr->left, prev);
	Traversal(curr->right, prev);
}

void correctNodes(TreeNode *itr) {

	while (itr != NULL) {
		swap(itr->left, itr->right);
		itr->left = NULL;
		itr = itr->right;
	}

}

TreeNode* Solution::flatten(TreeNode* A) {

	if (A == NULL)
		return A;

	TreeNode *prev = A;

	Traversal(A->left, prev);
	Traversal(A->right, prev);
	correctNodes(A);

	return A;
}
