/**
 * Suppose a sorted array A is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * Find the minimum element.The array will not contain duplicates.
 */

int Solution::findMin(const vector<int> &A) {
	int mid, low, high, next, prev;
	int sz = A.size();
	low = 0;
	high = sz - 1;

	if (high == 0)
		return A[high];

	while (A[.low] > A[high]) {
		mid = (low + high) / 2;
		next = A[(mid + 1) % sz];
		prev = A[(mid + sz - 1) % sz];

		if (A[mid] < prev && A[mid] < next) {
			return A[mid];
		}

		if (A[mid] <= A[high]) {
			high = mid - 1;
		} else if (A[mid] >= A[low]) {
			low = mid + 1;
		}
	}

	return A[low];
}
