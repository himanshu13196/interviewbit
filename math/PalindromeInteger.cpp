/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 * A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
 * Negative numbers are not palindromic.
 */

bool Solution::isPalindrome(int A) {

	bool res = true;

	if (A < 0) {
		return false;
	}

	string num = to_string(A);
	int sz = num.size();

	for (int i = 0; i < (sz / 2); i++) {
		if (num[i] != num[sz - 1 - i])
			res = false;
	}

	return res;
}
