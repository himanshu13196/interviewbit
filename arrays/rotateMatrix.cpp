/**
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * You need to do this in place.
 */

void Solution::rotate(vector<vector<int> > &A) {
	int mover1, mover2, rowS, colS, rowD, colD, row = 0, col = 0;
	int count = A.size() * A.size(), sz = A.size(), bnd = sz - 1;

	while (count > 3) {
		for (int i = 0; i < sz - 1; i++) {
			//move 0 to 90
			rowS = row;
			colS = col;
			rowD = colS;
			colD = bnd - rowS;
			mover1 = A[rowD][colD];
			A[rowD][colD] = A[rowS][colS];
			rowS = rowD;
			colS = colD;
			//move 90 to 180
			rowD = colS;
			colD = bnd - rowS;
			mover2 = A[rowD][colD];
			A[rowD][colD] = mover1;
			rowS = rowD;
			colS = colD;
			//cout << "Source:" << mover2 << " ";
			//move 180 to 270
			rowD = colS;
			colD = bnd - rowS;
			mover1 = A[rowD][colD];
			//cout << "Dest:" << mover1 << " ";
			A[rowD][colD] = mover2;
			rowS = rowD;
			colS = colD;
			//move 270 to 360
			rowD = colS;
			colD = bnd - rowS;
			mover2 = A[rowD][colD];
			A[rowD][colD] = mover1;
			rowS = rowD;
			colS = colD;
			col = col + 1;
			count = count - 4;
		}
		sz = sz - 2;
		row++;
		col = row;

	}
}
