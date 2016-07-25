/**
 * Given 2 sorted arrays, find all the elements which occur in both the arrays.
 */

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {

	int itr1 = 0, itr2 = 0;
	vector<int> sol;

	while (itr1 < A.size() && itr2 < B.size()) {
		if (A[itr1] == B[itr2]) {
			sol.push_back(A[itr1]);
			itr1++;
			itr2++;
		} else if (A[itr1] > B[itr2]) {
			itr2++;
		} else {
			itr1++;
		}
	}

	return sol;
}
