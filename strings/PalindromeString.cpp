int Solution::isPalindrome(string A) {

	if (A.size() == 0)
		return 1;
	int low = 0, high = A.size() - 1, result = 1;

	//convert everything to lower case
	for (int i = 0; i < A.size(); i++) {
		if (A[i] >= 'A' && A[i] <= 'Z') {
			A[i] += 32;
		}
	}

	while (low <= high) {

		while ((A[low] < 'a' && (A[low] < '0' || A[low] > '9')) || A[low] > 'z') {
			low++;
			if (low > high)
				break;
		}

		while ((A[high] < 'a' && (A[low] < '0' || A[low] > '9')) || A[high] > 'z') {
			high--;
			if (low > high)
				break;
		}

		if (low > high)
			break;

		if (A[low] == A[high]) {
			result = 1;
		} else {
			result = 0;
			break;
		}

		low++;
		high--;
	}

	return result;
}
