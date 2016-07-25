//Given a column title as appears in an Excel sheet, return its corresponding column number.

int Solution::titleToNumber(string A) {

	int sz = A.size();

	int result = 0;

	for (int i = 0; i < sz; i++) {
		result = result * 26 + A[i] - 64;
	}

	return result;
}
