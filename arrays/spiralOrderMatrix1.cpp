/*Given a matrix of m * n elements (m rows, n columns),
 return all elements of the matrix in spiral order.*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int count = A.size() * A[0].size();
	int row = 0, col = 0, dir = 1, rSize = A.size(), cSize = A[0].size();

	while (count > 0) {

		for (int i = 0; i < cSize; i++) {
			result.push_back(A[row][col]);
			col = col + dir;
			count--;
			if (count == 0)
				break;
		}

		col = col - dir;

		if (count == 0)
			break;
		row = row + dir;
		rSize--;

		for (int j = 0; j < rSize; j++) {
			result.push_back(A[row][col]);
			row = row + dir;
			count--;
			if (count == 0)
				break;
		}

		row = row - dir;

		if (count == 0)
			break;
		col = col - dir;
		cSize--;

		dir = -dir;
	}
	return result;
}
