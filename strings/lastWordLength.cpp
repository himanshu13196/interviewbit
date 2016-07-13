/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 * return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 */

int Solution::lengthOfLastWord(const string &A) {
	int ssize = A.size(), count = 0;
	bool flag = false;

	for (int i = ssize - 1; i >= 0; i--) {
		if (A[i] != 32) {
			flag = true;
			count++;
		} else if (flag) {
			break;
		}
	}

	return count;
}
