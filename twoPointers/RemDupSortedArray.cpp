/**
 * Remove duplicates from Sorted Array
 * Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.
 * Note that even though we want you to return the new length, make sure to change the original array as well in place
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 */

int Solution::removeDuplicates(vector<int> &A) {

	int sz = A.size();

	if (sz <= 1)
		return sz;

	int uItr = 0, curr = 0, next = 1;

	while (curr < A.size() - 1) {
		if (A[curr] != A[next]) {
			A[uItr] = A[curr];
			uItr++;
		}
		curr++;
		next++;
	}

	A[uItr] = A[curr];
	uItr++;

	return uItr;
}
