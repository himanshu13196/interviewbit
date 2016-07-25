/**
 * Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.
 * If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.
 * The replacement must be in-place, do not allocate extra memory.
 */

void swap(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void Solution::nextPermutation(vector<int> &A) {
	int revstrt = -1;
	int revend = -1;
	bool revflag = false;
	int ascstrt = -1;

	for (int i = 0; i < A.size() - 1; i++) {
		if (A[i] > A[i + 1]) {
			if (revflag == false) {
				revstrt = i;
				revflag = true;
			}
			revend = i + 1;
		} else if (A[i] < A[i + 1]) {
			ascstrt = i;
			revflag = false;
		}
	}

	if (ascstrt == -1) {
		sort(A.begin(), A.end());
	} else {
		if (ascstrt > revstrt) {
			swap(A[ascstrt], A[ascstrt + 1]);
		} else {
			int temp = revend;
			while (A[ascstrt] > A[temp]) {
				temp--;
			}
			swap(A[ascstrt], A[temp]);
			while (revstrt < revend) {
				swap(A[revstrt], A[revend]);
				revstrt++;
				revend--;
			}
		}
	}
}
