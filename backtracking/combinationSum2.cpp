/**
 * Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 */

void combHelper(vector<int> &A, vector<vector<int> > &sol, int &B, vector<int> &curr, int currSum, int itr) {
	int temp;
	for (; itr < A.size(); itr++) {
		temp = A[itr] + currSum;
		if (temp == B) {
			curr.push_back(A[itr]);
			sol.push_back(curr);
			curr.pop_back();
			return;
		} else if (temp < B) {
			curr.push_back(A[itr]);
			int t = itr + 1;
			combHelper(A, sol, B, curr, temp, t);
			curr.pop_back();
		} else {
			return;
		}

		temp = A[itr];
		int k = itr + 1;
		while (itr < A.size() && A[k] == temp) {
			k++;
		}

		if (k != itr + 1) {
			itr = k - 1;
		}

	}

}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

	vector < vector<int> > sol;

	sort(A.begin(), A.end());

	int itr = 0;
	int currSum = 0;
	vector<int> curr;

	combHelper(A, sol, B, curr, currSum, itr);

	return sol;
}

