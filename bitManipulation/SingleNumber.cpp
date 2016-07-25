/**
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * algorithm should have a linear runtime complexity and use constant extra space.
 */

int Solution::singleNumber(const vector<int> &A) {
	int sol = 0;
	for (int i = 0; i < A.size(); i++) {
		sol = (sol ^ A[i]);
	}
	return sol;
}
