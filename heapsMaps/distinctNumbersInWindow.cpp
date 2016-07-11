/**
 * You are given an array of N integers, A1, A2 ,…, AN and an integer K.
 * Return the of count of distinct numbers in all windows of size K.
 * Formally, return an array of size N-K+1 where i’th element in this array
 * contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.
 */

vector<int> Solution::dNums(vector<int> &A, int B) {

	vector<int> sol;

	if (B > A.size())
		return sol;

	unordered_map<int, int> count;

	int tcount = 0;

	for (int i = 0; i < B; i++) {

		if (count.find(A[i]) == count.end()) {
			tcount++;
			count[A[i]] = 1;
		} else {
			count[A[i]] += 1;
		}
	}

	sol.push_back(tcount);

	int i = 0;

	for (int j = B; j < A.size(); j++) {

		if (count[A[i]] == 1) {
			count.erase(A[i]);
			tcount--;
		} else {
			count[A[i]] -= 1;
		}

		if (count.find(A[j]) == count.end()) {
			count[A[j]] = 1;
			tcount++;
		} else {
			count[A[j]] += 1;
		}

		i++;

		sol.push_back(tcount);
	}

	return sol;
}
