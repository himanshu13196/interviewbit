/**
 * Given a number N, find all prime numbers upto N ( N included ).
 */

vector<int> Solution::sieve(int A) {

	vector<int> result;

	if (A < 2) {
		return result;
	}

	int sqN = sqrt(A);

	vector<int> primes(A + 1, 1);

	primes[0] = 0;
	primes[1] = 0;

	for (int i = 2; i <= sqN; i++) {
		if (primes[i] == 1) {
			for (int j = i + 1; j <= A; j++) {
				if (j % i == 0) {
					primes[j] = 0;
				}
			}
		}
	}

	for (int i = 2; i <= A; i++) {
		if (primes[i] == 1) {
			result.push_back(i);
		}
	}

	return result;
}
