/**
 * Given a read only array of n + 1 integers between 1 and n,
 * find one number that repeats in linear time using less than O(n) space,
 * and traversing the stream sequentially O(1) times.
 */

int Solution::repeatedNumber(const vector<int> &A) {
	int temp = A.size() - 1;
	int sqN = sqrt(temp);
	int lstbnd = temp % sqN;

	if (lstbnd == 0) {
		lstbnd = sqN;
	}
	vector<int> ranges((temp / sqN) + 1, 0);
	int temp1;
	int low = 0, high = 0;
	int itr;

	for (int i = 0; i < A.size(); i++) {
		temp = A[i] / sqN;
		temp1 = A[i] % sqN;

		if (temp1 > 0) {
			itr = temp;
		} else {
			itr = temp - 1;
		}

		ranges[itr]++;

		if (itr != ranges.size() - 1 && ranges[itr] > sqN) {
			low = sqN * itr;
			high = sqN + low;
		} else if (itr == ranges.size() - 1 && ranges[itr] > lstbnd) {
			low = sqN * itr;
			high = low + lstbnd;
		}
	}

	fill(ranges.begin(), ranges.end(), 0);

	for (int i = 0; i < A.size(); i++) {
		temp = A[i] - low - 1;
		if (A[i] > low && A[i] <= high) {
			ranges[temp]++;
			if (ranges[temp] > 1) {
				return (A[i]);
			}
		}
	}

	return 0;
}
