/**
 * Given an array ‘A’ of sorted integers and another non negative integer k,
 * find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
 */
int Solution::diffPossible(vector<int> &A, int B) {
	int itr1 = 0, itr2 = 1, diff;

	while (itr2 < A.size()) {
		diff = A[itr2] - A[itr1];
		if (diff == B) {
			return 1;
		} else if (diff > B) {
			if (itr1 == itr2 - 1) {
				itr1++;
				itr2++;
			} else {
				itr1++;
			}
		} else {
			itr2++;
		}
	}

	return 0;
}
