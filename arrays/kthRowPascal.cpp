/**
 * Given an index k, return the kth row of the Pascal’s triangle.
 * Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
 */

vector<int> Solution::getRow(int A) {
	vector<int> result(A + 1);

	for (int i = 0; i < A + 1; i++) {
		if (i == 0) {
			result[0] = 1;
		} else {
			for (int j = i; j >= 0; j--) {
				if (j == i) {
					result[j] = result[j - 1];
				} else if (j > 0) {
					result[j] = result[j] + result[j - 1];
				}
			}
		}
	}

	return result;
}
