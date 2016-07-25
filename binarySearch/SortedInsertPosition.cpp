/**
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 */

int Solution::searchInsert(vector<int> &A, int B) {
	int low, mid, high;
	low = 0;
	high = A.size() - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (A[mid] == B) {
			return mid;
		} else if (A[mid] > B) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	if (A[mid] == B) {
		return mid;
	} else if (A[mid] < B) {
		return mid + 1;
	} else {
		if (mid > 0) {
			return mid;
		} else {
			return 0;
		}
	}
}
