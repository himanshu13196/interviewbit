/**
 * You are given a read only array of n integers from 1 to n.
 * Each integer appears exactly once except A which appears twice and B which is missing.
 * Return A and B.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 * Note that in your output A should precede B.
 */

vector<int> Solution::repeatedNumber(const vector<int> &A) {

	vector<bool> num(A.size() + 1, false);

	int rpt = 0, ms = 0, temp = 0;
	for (int i = 0; i < A.size(); i++) {
		temp = A[i];
		if (num[temp] == true) {
			rpt = temp;
		} else {
			num[temp] = true;
		}
	}

	for (int j = 1; j < A.size() + 1; j++) {
		if (num[j] == false) {
			ms = j;
			break;
		}
	}

	vector<int> result;
	result.push_back(rpt);
	result.push_back(ms);

	return result;
}
