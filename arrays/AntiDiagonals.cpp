/**
 *Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
 */
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
	int iSize = A.size();
	vector < vector<int> > result;
	vector<int> temp;
	int count = iSize * iSize, r = 0, c = 0, tr = 0, tc = 0;

	while (count > 0) {
		tr = r;
		tc = c;
		while (tr <= iSize - 1 && tc >= 0) {
			temp.push_back(A[tr][tc]);
			tr++;
			tc--;
			count--;
		}

		result.push_back(temp);
		temp.clear();

		if (c < iSize - 1) {
			c++;
		} else if (r < iSize - 1) {
			r++;
		}
	}

	return result;
}
