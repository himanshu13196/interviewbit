/*Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.
 Make sure the combinations are sorted.
 To elaborate,
 1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
 2. Entries should be sorted within themselves.
 Example :
 If n = 4 and k = 2, a solution is:
 [ [1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
 */

void combHelper(vector<vector<int> > &sol, int &n, int &k, vector<int> &curr, int itr) {

	for (; itr <= n; itr++) {
		if (curr.size() == k - 1) {
			curr.push_back(itr);
			sol.push_back(curr);
			curr.pop_back();
		} else if (curr.size() < k - 1) {
			curr.push_back(itr);
			int temp = itr + 1;
			combHelper(sol, n, k, curr, temp);
			curr.pop_back();
		} else {
			return;
		}
	}

	return;
}

vector<vector<int> > Solution::combine(int n, int k) {

	vector < vector<int> > sol;

	vector<int> curr;
	int itr = 1;

	combHelper(sol, n, k, curr, itr);

	return sol;
}
