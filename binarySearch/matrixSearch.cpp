//Write an efficient algorithm that searches for a value in an m x n matrix.

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
	int colSz = A.size();
	int rowSz = A[0].size();

	int low = 0;
	int high = (colSz * rowSz) - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (A[mid / rowSz][mid % rowSz] == B) {
			return 1;
		} else if (A[mid / rowSz][mid % rowSz] > B) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return 0;
}
