/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1 and S2.
 * As an example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".
 * Given the array of strings, you need to find the longest S which is the prefix of ALL the strings in the array.
 */

string Solution::longestCommonPrefix(vector<string> &A) {

	int sz = A.size();
	int minsz = A[0].size();
	string result;

	for (int i = 0; i < sz; i++) {
		if (A[i].size() < minsz) {
			minsz = A[i].size();
		}
	}

	int flag = 0;

	if (sz == 1)
		return A[0];

	char temp;

	for (int j = 0; j < minsz; j++) {
		flag = 1;
		temp = A[0][j];
		for (int k = 1; k < sz; k++) {
			if (A[k][j] != temp) {
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			result.push_back(temp);
		} else {
			break;
		}
	}

	return result;
}
