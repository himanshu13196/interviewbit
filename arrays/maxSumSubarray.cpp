/**
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 */

int Solution::maxSubArray(const vector<int> &A) {
	long int result;
	long int sum;

	result = 0;
	sum = 0;
	bool pos = false;

	for (int l = 0; l < A.size(); l++) {
		if (A[l] > 0) {
			pos = true;
		}
	}

	if (pos) {
		for (int i = 0; i < A.size(); i++) {
			if (sum >= 0) {
				sum = sum + A[i];
				if (sum > result)
					result = sum;
			} else {
				sum = 0;
				sum = sum + A[i];
				if (sum > result)
					result = sum;
			}
		}
	} else {
		//cout << "loop entered";
		for (int i = 0; i < A.size(); i++) {
			if (i == 0) {
				result = A[i];
			} else if (A[i] > result) {
				result = A[i];
			}
		}
	}

	return result;
}
