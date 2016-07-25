/**
 * You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN.
 * In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR.
 * By flipping, we mean change character 0 to 1 and vice-versa.
 * Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.
 * If you don’t want to perform the operation, return an empty array.
 * Else, return an array consisting of two elements denoting L and R.
 * If there are multiple solutions, return the lexicographically smallest pair of L and R.
 * Notes:
 * Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == b, then b < d.
 */

vector<int> Solution::flip(string A) {

	vector<int> ans;

	int sz = A.size();
	int ones = 0;
	int numones = 0, numzeroes = 0;
	int win1 = 0, win2 = 0;
	int itr1 = 0, itr2 = 0;

	for (int i = 0; i < sz; i++) {
		if (A[i] == '1')
			ones++;
	}
	int tcount = ones;

	for (int i = 0; i < sz; i++) {
		if (A[i] == '0') {
			numzeroes++;
		} else {
			numones++;
		}

		if (ones + numzeroes - numones > tcount) {
			itr2 = i;
			win1 = itr1 + 1;
			win2 = itr2 + 1;
			tcount = ones + numzeroes - numones;
		} else if (numzeroes < numones) {
			numones = 0;
			numzeroes = 0;
			itr1 = i + 1;
			itr2 = i + 1;
		} else {
			itr2++;
		}
	}

	if (win1 != 0) {
		ans.push_back(win1);
		ans.push_back(win2);
	}

	return ans;
}
