/**
 * Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.
 * Do it in place.
 */

void Solution::setZeroes(vector<vector<int> > &A) {

	int rflag = -1;
	int cflag = -1;

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			if (A[i][j] == 0) {
				if (i == 0) {
					rflag = 1;
				}
				if (j == 0) {
					cflag = 1;
				}
				A[0][j] = 0;
				A[i][0] = 0;
			}
		}
	}

	for (int i = 1; i < A[0].size(); i++) {
		if (A[0][i] == 0) {
			for (int j = 1; j < A.size(); j++) {
				A[j][i] = 0;
			}
		}
	}

	for (int i = 1; i < A.size(); i++) {
		if (A[i][0] == 0) {
			for (int j = 1; j < A[0].size(); j++) {
				A[i][j] = 0;
			}
		}
	}

	if (A[0][0] == 0) {
		if (cflag == 1) {
			for (int i = 1; i < A.size(); i++) {
				A[i][0] = 0;
			}
		}
		if (rflag == 1) {
			for (int j = 1; j < A[0].size(); j++) {
				A[0][j] = 0;
			}
		}
	}

}
