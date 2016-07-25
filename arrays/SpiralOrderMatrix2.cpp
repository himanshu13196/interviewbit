/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * Example:
 * Given n = 3,
 * You should return the following matrix:
 * [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]
 */

vector<vector<int> > Solution::generateMatrix(int A) {
	vector < vector<int> > result(A, vector<int>(A));
	int count = A * A;
	int num = 1;
	int dir = 1;
	int rSize = A;
	int cSize = A;
	int r = 0;
	int c = 0;

	while (count > 0) {
		for (int i = 0; i < cSize; i++) {
			if (count == 0)
				break;
			result[r][c] = num;
			num++;
			count--;
			c = c + dir;
		}

		if (count == 0)
			break;
		c = c - dir;
		r = r + dir;
		rSize--;

		for (int j = 0; j < rSize; j++) {
			if (count == 0)
				break;
			result[r][c] = num;
			num++;
			count--;
			r = r + dir;
		}

		if (count == 0)
			break;
		r = r - dir;
		dir = -dir;
		c = c + dir;
		cSize--;

	}

	return result;
}
