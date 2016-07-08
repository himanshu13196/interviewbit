/**
 * Implement pow(x, n) % d.
 * In other words, given x, n and d,
 * find (x^n % d)
 */

int Solution::pow(int x, int n, int d) {
	long long int num = 1;
	long long int base = x % d;

	while (n) {
		if (n & 1) {
			num *= base;
			num = num % d;
		}
		n >>= 1;
		base = (base * base) % d;
	}

	num = num % d;
	if (num < 0) {
		num = num + d;
	}

	return num;
}
