/**
 * Given a number N, verify if N is prime or not.
 * Return 1 if N is prime, else return 0.
 */

int Solution::isPrime(int A) {

	if (A < 2) {
		return 0;
	}

	if (A == 2) {
		return 1;
	}

	int sqN = sqrt(A);

	for (int i = 2; i <= sqN; i++) {
		if (A % i == 0) {
			return 0;
		}
	}

	return 1;
}
