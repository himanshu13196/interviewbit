/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 */

int Solution::trap(const vector<int> &A) {

	if (A.size() < 3)
		return 0;

	int lftMx = A[0];
	stack<int> rgtMx;
	int sz = A.size();
	int sol = 0;
	int l;

	for (int i = sz - 1; i >= 1; i--) {
		if (rgtMx.empty()) {
			rgtMx.push(A[i]);
		} else if (A[i] >= rgtMx.top()) {
			rgtMx.push(A[i]);
		}
	}

	for (int i = 1; i < sz - 1; i++) {

		if (A[i] < lftMx && A[i] < rgtMx.top()) {

			l = min(lftMx, rgtMx.top()) - A[i];

			sol = sol + l;
		}

		if (A[i] > lftMx)
			lftMx = A[i];

		if (A[i] == rgtMx.top())
			rgtMx.pop();

	}

	return sol;
}
