/**
 * For Given Number N find if its COLORFUL number or not
 * Return 0/1
 * COLORFUL number:
 * A number can be broken into different sub-sequence parts.
 * Suppose, a number 3245 can be broken into parts
 * like 3 2 4 5 32 24 45 324 245.
 * And this number is a COLORFUL number,
 * since product of every digit of a sub-sequence are different
 */

int Solution::colorful(int A) {

	if (A > -10 && A < 10)
		return 1;
	if (A < 0)
		A *= -1;

	string nums = to_string(A);
	map<int, bool> prod;
	int temp;

	for (int i = 1; i <= nums.size(); i++) {
		for (int j = 0; j < nums.size(); j += i) {

			if (j + i - 1 >= nums.size())
				break;
			temp = 1;
			for (int k = j; k < j + i; k++) {
				temp = temp * (nums[k] - 48);
			}

			if (prod.find(temp) == prod.end()) {
				prod[temp] = true;
			} else {
				return 0;
			}
		}
	}

	return 1;
}
