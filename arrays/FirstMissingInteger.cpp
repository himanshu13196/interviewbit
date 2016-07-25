/**
 * Given an unsorted integer array, find the first missing positive integer.
 * Your algorithm should run in O(n) time and use constant space.
 */

int Solution::firstMissingPositive(vector<int> &A) {

	int result = 1;
	int pos;
	int N = A.size();

	for (int i = 0; i < N; i++) {
		if (A[i] < N + 1 && A[i] >= 1) {
			pos = A[i];
			if (A[pos - 1] != pos) {
				A[pos - 1] = A[pos - 1] + A[i];
				A[i] = A[pos - 1] - A[i];
				A[pos - 1] = A[pos - 1] - A[i];
				i--;
			}
		}
	}

	for (int j = 0; j < N; j++) {
		if (A[j] == j + 1) {
			result++;
		} else {
			return result;
		}
	}

	return result;

}
