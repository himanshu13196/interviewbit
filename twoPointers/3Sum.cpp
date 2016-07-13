/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers.
 * You may assume that each input would have exactly one solution.
 */

int Solution::threeSumClosest(vector<int> &A, int B) {

	sort(A.begin(), A.end());

	int solDiff = B - (A[0] + A[1] + A[2]), solSum = A[0] + A[1] + A[2];
	int itr1, itr2, diff, sum;

	if (solDiff < 0)
		solDiff = -solDiff;

	for (int i = 0; i < A.size() - 2; i++) {
		itr1 = i + 1;
		itr2 = A.size() - 1;

		while (itr1 < itr2) {

			sum = A[i] + A[itr1] + A[itr2];
			diff = B - (sum);

			if (diff == 0)
				return B;

			if (diff < 0)
				diff = -diff;

			if (diff < solDiff) {
				solSum = sum;
				solDiff = diff;
			}

			if (sum > B) {
				itr2--;
			} else {
				itr1++;
			}
		}

	}

	return solSum;

}
