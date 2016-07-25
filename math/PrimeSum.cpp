/**
 * Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
 */

bool isPrime(int num) {
	if (num == 2)
		return true;

	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

vector<int> Solution::primesum(int A) {
	vector<int> result;
	for (int i = 2; i <= A / 2 + 1; i++) {
		if (isPrime(i)) {
			if (isPrime(A - i)) {
				result.push_back(i);
				result.push_back(A - i);
				return result;
			}
		}
	}

	return result;
}
