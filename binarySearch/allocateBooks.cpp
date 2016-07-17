/**
 * N number of books are given. The ith book has Pi number of pages.
 * You have to allocate books to M number of students so that maximum number of pages alloted to a student is minimum. A book will be allocated to exactly one student. Each student has to be allocated atleast one book.
 * NOTE: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.
 * Input:List of Books M number of students
 * Your function should return an integer corresponding to the minimum number.
 */

int Solution::books(vector<int> &A, int B) {
	int sz = A.size();

	if (sz < B) {
		return -1;
	}

	int high = 0, low = A[0];

	for (int i = 0; i < sz; i++) {
		if (A[i] > low) {
			low = A[i];
		}
		high = high + A[i];
	}

	int sol = high, mid, tPpl = 1, tSum = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		tPpl = 1;
		tSum = 0;

		for (int j = 0; j < sz; j++) {
			tSum = tSum + A[j];
			if (tSum > mid) {
				tSum = A[j];
				tPpl++;
			}
		}

		if (tPpl <= B) {
			if (mid < sol) {
				sol = mid;
			}
			high = mid - 1;
		} else if (tPpl > B) {
			low = mid + 1;
		}
	}

	return sol;

}
