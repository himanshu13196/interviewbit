/*
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 * If x is not a perfect square, return floor(sqrt(x))
 */

int Solution::sqrt(int A) {
	if (A == 1 || A == 0) {
		return A;
	}

	long int low = 0, high = A / 2, mid, sol;

	while (low <= high) {
		mid = (low + high) / 2;
		sol = mid * mid;
		if (sol == A) {
			return mid;
		} else if (sol > A) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	if (sol > A) {
		return mid - 1;
	} else if ((mid + 1) * (mid + 1) < A) {
		return mid + 1;
	} else {
		return mid;
	}
}
