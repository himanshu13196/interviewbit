/**
 * You are in an infinite 2D grid where you can move in any of the 8 directions :
 * (x,y) to (x+1, y), (x - 1, y), (x, y+1), (x, y-1), (x-1, y-1), (x+1,y+1), (x-1,y+1), (x+1,y-1)
 * You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.
 */

// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
	int numPts = X.size();
	int result = 0;
	int temp1, temp2;

	for (int i = 1; i < numPts; i++) {
		temp1 = X[i] - X[i - 1];
		temp2 = Y[i] - Y[i - 1];
		if (temp1 < 0) {
			temp1 = -temp1;
		}
		if (temp2 < 0) {
			temp2 = -temp2;
		}
		if (temp1 > temp2) {
			result = result + temp1;
		} else {
			result = result + temp2;
		}
	}

	return result;
}
