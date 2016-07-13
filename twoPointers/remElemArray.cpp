/**
 * Given an array and a value, remove all the instances of that value in the array.
 * Also return the number of elements left in the array after the operation.
 * It does not matter what is left beyond the expected length.
 * Try to do it in less than linear additional space complexity.
 */

int Solution::removeElement(vector<int> &A, int B) {
	int uItr = 0, curr = 0;

	while (curr < A.size()) {
		if (A[curr] != B) {
			A[uItr] = A[curr];
			uItr++;
		}
		curr++;
	}

	return uItr;
}
