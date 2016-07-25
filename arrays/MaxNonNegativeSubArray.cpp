/**
 * Find out the maximum sub-array of non negative numbers from an array.
 * The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.
 * Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).
 */

vector<int> Solution::maxset(vector<int> &A) {

	vector<int> max;
	vector<int> temp;
	long int mxSum, tmpSum;

	mxSum = 0;
	tmpSum = 0;

	for (int i = 0; i < A.size(); i++) {

		if (A[i] >= 0) {
			temp.push_back(A[i]);
			tmpSum += A[i];
		}
		if ((A[i] < 0) || (i == A.size() - 1)) {

			if (mxSum < tmpSum) {
				max.clear();
				max = temp;
				mxSum = tmpSum;
			} else if (mxSum == tmpSum) {
				if (max.size() < temp.size()) {
					max.clear();
					max = temp;
					mxSum = tmpSum;
				}
			}

			temp.clear();
			tmpSum = 0;
		}

	}

	return max;
}
