/**
 * Given a string S, find the longest palindromic substring in S.
 * Substring of string S:S[i...j] where 0 <= i <= j < len(S)
 * Palindrome string:
 * A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.
 * Incase of conflict, return the substring which occurs first ( with the least starting index ).
 */

string Solution::longestPalindrome(string A) {

	string sol;

	int ssz = A.size();
	int solStrt = 0;
	int solEnd = 0;
	int len;
	int tlen;
	int strt, end;
	bool flag = false;

	for (int i = 0; i < A.size(); i++) {
		for (int k = i; k <= i + 1; k++) {
			end = k;
			flag = false;
			strt = i - 1;

			while (strt >= 0 && end < A.size()) {
				if (A[strt] == A[end]) {
					flag = true;
					strt--;
					end++;
				} else {
					break;
				}
			}

			if (flag == true) {
				strt++;
				end--;
				len = solEnd - solStrt;
				tlen = end - strt;

				if (len < tlen) {
					solStrt = strt;
					solEnd = end;
				} else if (len == tlen && solStrt > strt) {
					solStrt = strt;
					solEnd = end;
				}
			}
		}
	}

	for (int j = solStrt; j <= solEnd; j++) {
		sol += A[j];
	}

	return sol;
}
