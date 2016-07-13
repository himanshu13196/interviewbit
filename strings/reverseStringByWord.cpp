/**
 * Given an input string, reverse the string word by word.
 */

void Solution::reverseWords(string &A) {

	int ssize = A.size(), start, end;
	bool flag = false;

	if (ssize == 0)
		return;

	string temp = "";

	for (int j = ssize - 1; j >= 0; j--) {
		if (A[j] != 32) {
			if (flag) {
				start = j;
			} else {
				flag = true;
				end = j;
				start = j;
			}
		}

		if (A[j] == 32) {
			if (flag) {
				for (int k = start; k <= end; k++) {
					temp += A[k];
				}
				temp += " ";
			}
			flag = false;
		}

	}

	if (A[0] != 32) {
		start = 0;
		for (int k = start; k <= end; k++) {
			temp += A[k];
		}
	} else {
		int tsize = temp.size();
		temp.resize(tsize - 1);
	}

	A = temp;
}
