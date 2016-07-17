/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).
 * You are given a target value to search. If found in the array, return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */

int Solution::search(const vector<int> &A, int B) {

	int low = 0, high = A.size() - 1, mid, prev;
	int pivot = 0;
	int sz = A.size();

	while (low <= high) {
		mid = (low + high) / 2;
		if (A[low] < A[high]) {
			pivot = low;
			break;
		}
		prev = (mid + sz - 1) % sz;

		if (A[mid] < A[prev]) {
			pivot = mid;
			break;
		} else if (A[mid] > A[low]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	low = pivot;
	high = sz - 1 + pivot;

	while (low <= high) {
		mid = (low + high) / 2;

		if (A[mid % sz] == B) {
			return (mid % sz);
		} else if (A[mid % sz] > B) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}
