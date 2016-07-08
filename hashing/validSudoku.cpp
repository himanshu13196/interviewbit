//Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

int Solution::isValidSudoku(const vector<string> &A) {

	map<int, bool> row[9];
	map<int, bool> col[9];
	map<int, bool> bx[9];
	int temp;
	int tBx;

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			if (isdigit(A[i][j])) {
				temp = A[i][j] - '0';
				tBx = 3 * (i / 3) + j / 3;

				if (row[i].find(temp) == row[i].end()) {
					row[i][temp] = true;
				} else {
					return 0;
				}

				if (col[j].find(temp) == col[j].end()) {
					col[j][temp] = true;
				} else {
					return 0;
				}

				if (bx[tBx].find(temp) == bx[tBx].end()) {
					bx[tBx][temp] = true;
				} else {
					return 0;
				}

			}
		}
	}

	return 1;
}
