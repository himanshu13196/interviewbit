/**
 * You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board.
 * 2 painters cannot share a board to paint. That is to say, a board
 * cannot be painted partially by one painter, and partially by another.
 * A painter will only paint contiguous boards. Which means a
 * configuration where painter 1 paints board 1 and 3 but not 2 is invalid.
 * Return the ans % 10000003
 */

int Solution::paint(int A, int B, vector<int> &C) {

	long high = 0, low = C[0], sol, mid, tSum;
	int tPpl;

	for (int i = 0; i < C.size(); i++) {
		if (C[i] > low) {
			low = C[i];
		}
		high = high + C[i];
	}

	sol = high;

	while (low <= high) {
		mid = (low + high) / 2;
		tPpl = 1;
		tSum = 0;

		for (int j = 0; j < C.size(); j++) {
			tSum = tSum + C[j];

			if (tSum > mid) {
				tPpl++;
				tSum = C[j];
			}
		}

		if (tPpl <= A) {
			if (mid < sol) {
				sol = mid;
			}
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	sol = (sol * B) % 10000003;

	return sol;
}
