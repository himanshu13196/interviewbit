/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
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

void Inorder(TreeNode* &A, vector<int> &inorder) {

	if (A == NULL)
		return;

	stack<TreeNode *> nodes;
	TreeNode *itr = A;

	while (1) {

		if (itr->left != NULL) {
			nodes.push(itr);
			itr = itr->left;
		} else {
			inorder.push_back(itr->val);

			if (itr->right == NULL) {
				while ((!nodes.empty()) && nodes.top()->right == NULL) {
					inorder.push_back(nodes.top()->val);
					nodes.pop();
				}

				if (nodes.empty()) {
					return;
				} else {
					inorder.push_back(nodes.top()->val);
					itr = nodes.top()->right;
					nodes.pop();
				}
			} else {
				itr = itr->right;
			}
		}

	}

}

int Solution::isSymmetric(TreeNode* A) {

	vector<int> inorder;

	Inorder(A, inorder);

	/*for(int k = 0; k < inorder.size(); k++) {
	 cout << " " << inorder[k];
	 }*/

	int i = 0;
	int j = inorder.size() - 1;

	while (i < j) {
		if (inorder[i] != inorder[j]) {
			return 0;
		}
		i++;
		j--;
	}

	return 1;
}
