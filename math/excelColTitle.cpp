//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
string Solution::convertToTitle(int A) {
	string result;

	do {
		if (A % 26 != 0) {
			result.push_back(64 + (A % 26));
		} else {
			result.push_back('Z');
			A = A - 1;
		}

		A = A / 26;
	} while (A > 0);

	reverse(result.begin(), result.end());

	return result;
}
