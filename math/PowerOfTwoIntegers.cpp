/**
 * Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.
 */

bool Solution::isPower(int A) {

	if (A == 1) {
		return true;
	}

	int num = sqrt(A);
	int temp;

	for (int i = 2; i <= sqrt(A); i++) {
		if (A % i == 0) {
			temp = A / i;
			while (temp % i == 0) {
				temp = temp / i;
				if (temp == 1) {
					return true;
				}
			}
		}
	}

	return false;
}
