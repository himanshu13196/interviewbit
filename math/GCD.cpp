/**
 * Given 2 non negative integers m and n, find gcd(m, n)
 * GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
 * Both m and n fit in a 32 bit signed integer.
 */

int Solution::gcd(int A, int B) {

	if (A == 0) {
		return B;
	}

	if (B == 0) {
		return A;
	}

	while (A > 0 && B > 0) {
		if (A >= B) {
			A = A - B;
		} else {
			B = B - A;
		}
	}

	if (A > 0) {
		return A;
	} else {
		return B;
	}

}
