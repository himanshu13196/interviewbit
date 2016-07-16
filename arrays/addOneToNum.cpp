/**
 * Given a non-negative number represented as an array of digits,
 * add 1 to the number ( increment the number represented by the digits ).
 * The digits are stored such that the most significant digit is at the head of the list.
 */

vector<int> Solution::plusOne(vector<int> &A) {

	vector<int> result;
	int strt = 0;
	int allNine = 1;

	while (A[strt] == 0) {
		strt++;
		if (strt == A.size()) {
			result.push_back(1);
			return result;
		}
	}

	for (int i = strt; i < A.size(); i++) {
		result.push_back(A[i]);
		if (A[i] < 9) {
			allNine = 0;
		}
	}

	if (allNine == 1) {

		result[0] = 1;

		for (int i = 1; i < result.size(); i++) {
			result[i] = 0;
		}

		result.push_back(0);

		return result;
	}

	int temp = result.size() - 1;

	while (result[temp] == 9) {
		result[temp] = 0;
		temp--;
	}

	result[temp] = result[temp] + 1;

	return result;

}
