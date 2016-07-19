/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as one 1 or 11.
 * 11 is read off as two 1s or 21.
 * 21 is read off as one 2, then one 1 or 1211.
 * Given an integer n, generate the nth sequence.
 */

string Solution::countAndSay(int A) {
	string sol;

	if (A == 0) {
		return sol;
	}

	sol = "1";

	if (A <= 1) {
		return sol;
	}
	int count;

	for (int i = 0; i < A - 1; i++) {
		string temp;
		count = 1;
		int tsize = sol.size();

		for (int j = 0; j < tsize - 1; j++) {
			if (sol[j] == sol[j + 1]) {
				count++;
			} else {
				temp += to_string(count);
				temp += sol[j];
				count = 1;
			}
		}
		temp += to_string(count);
		temp += sol[tsize - 1];
		sol = temp;
	}

	return sol;
}
