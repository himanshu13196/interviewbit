/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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

void convertBST(TreeNode *root, int start, int end, const vector<int> &A, int flag) {

	if (start > end)
		return;

	int mid = (start + end) / 2;
	TreeNode *curr = new TreeNode(A[mid]);

	if (flag == 0) {
		root->left = curr;
	} else {
		root->right = curr;
	}

	convertBST(curr, start, mid - 1, A, 0);
	convertBST(curr, mid + 1, end, A, 1);

	return;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {

	if (A.size() == 0) {
		return NULL;
	}

	int start = 0;
	int end = A.size() - 1;
	int mid = (start + end) / 2;
	TreeNode* root = new TreeNode(A[mid]);

	convertBST(root, start, mid - 1, A, 0);
	convertBST(root, mid + 1, end, A, 1);

	return root;

}
