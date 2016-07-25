/**
 * Reverse bits of an 32 bit unsigned integer
 */

unsigned int Solution::reverse(unsigned int A) {

	int sol = 0;

	for (int i = 0; i < 32; i++) {

		if (A & (1 << i)) {
			sol |= 1;
		}
		if (i != 31)
			sol <<= 1;
	}

	return sol;
}
