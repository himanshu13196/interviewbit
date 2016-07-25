/**
 * Write a function that takes an unsigned integer and returns the number of 1 bits it has
 */

int Solution::numSetBits(unsigned int A) {
	int sz = sizeof(A) * 8, count = 0;
	unsigned int base = 1;

	for (int i = 0; i < sz; i++) {
		if (A & base)
			count++;

		base *= 2;
	}

	return count;
}
