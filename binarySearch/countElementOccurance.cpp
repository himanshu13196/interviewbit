/**
 *Given a sorted array of integers, find the number of occurrences of a given target value.
 *Given Your algorithm’s runtime complexity must be in the order of O(log n).
 *Given If the target is not found in the array, return 0
 */

int Solution::findCount(const vector<int> &A, int B) {

	int end = A.size() - 1;
	int first = 0;
	int pos = -1;
	int mid;

	while (first <= end) {
		mid = first + (end - first) / 2;
		if (A[mid] == B) {
			pos = mid;
			break;
		} else if (A[mid] < B) {
			first = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	if (pos == -1) {
		return 0;
	}
	int sol = 1, i = 1;

	while (pos + i < A.size() && A[pos + i] == B) {
		sol++;
		i++;
	}

	i = 1;

	while (pos - i >= 0 && A[pos - i] == B) {
		sol++;
		i++;
	}

	return sol;
}
