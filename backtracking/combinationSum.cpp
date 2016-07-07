/**
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 */

void combHelper(vector<int> &A, vector<vector<int> > &sol, int &B, vector<int> &curr, int currSum, int itr) {

	for (; itr < A.size(); itr++) {
		if ((A[itr] + currSum) == B) {
			curr.push_back(A[itr]);
			sol.push_back(curr);
			curr.pop_back();
			return;
		} else if ((A[itr] + currSum) < B) {
			curr.push_back(A[itr]);
			int temp = currSum + A[itr];
			combHelper(A, sol, B, curr, temp, itr);
			curr.pop_back();
		} else {
			return;
		}
	}

}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

	vector < vector<int> > sol;
	vector<int> curr;
	int curr_sum = 0;
	int itr = 0;

	sort(A.begin(), A.end());

	A.erase(unique(A.begin(), A.end()), A.end());

	combHelper(A, sol, B, curr, curr_sum, itr);

	return sol;
}
