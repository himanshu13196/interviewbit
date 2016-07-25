/**
 * Given an integer n, return the number of trailing zeroes in n!.
 */

int Solution::trailingZeroes(int A) {

	if (A < 5) {
		return 0;
	}

	int num = 5;
	int result = 0;
	int temp = A;

	while (temp > 0) {
		temp = A;
		result = result + A / num;
		temp = A / num;
		num = num * 5;
	}

	return result;
}
