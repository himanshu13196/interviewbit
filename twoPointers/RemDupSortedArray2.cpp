/**
 * Remove Duplicates from Sorted Array
 * Given a sorted array, remove the duplicates in place such that each element appear atmost twice and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * Note that even though we want you to return the new length, make sure to change the original array as well in place
 * For example,
 * Given input array A = [1,1,1,2],
 * Your function should return length = 3, and A is now [1,1,2].
 */

int Solution::removeDuplicates(vector<int> &A) {

	int curr = 0, next = 1, uItr = 0, flag = 0;

	while (curr < A.size() - 1) {
		if (A[curr] != A[next]) {
			A[uItr] = A[curr];
			uItr++;
			flag = 0;
		} else if (flag == 0) {
			A[uItr] = A[curr];
			uItr++;
			flag = 1;
		}
		curr++;
		next++;
	}

	A[uItr] = A[curr];
	uItr++;

	return uItr;

}
