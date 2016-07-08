/**
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * Your algorithm’s runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */

vector<int> Solution::searchRange(const vector<int> &A, int B) {
	int low = 0, high = A.size() - 1, mid;
	vector<int> result;
	int pivot = -1;

	while (low <= high) {
		mid = (low + high) / 2;

		if (A[mid] == B) {
			if (mid == 0) {
				pivot = mid;
				break;
			} else {
				if (A[mid - 1] == B) {
					high = mid - 1;
				} else {
					pivot = mid;
					break;
				}
			}
		} else if (A[mid] > B) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	if (pivot == -1) {
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}

	result.push_back(pivot);

	low = 0;
	high = A.size() - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (A[mid] == B) {
			if (mid == A.size() - 1) {
				pivot = mid;
				break;
			} else {
				if (A[mid + 1] == B) {
					low = mid + 1;
				} else {
					pivot = mid;
					break;
				}
			}
		} else if (A[mid] > B) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	result.push_back(pivot);

	return result;
}
