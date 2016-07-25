/**
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * 'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 */

int Solution::maxArea(vector<int> &A) {
	int area = 0, tArea, itr1 = 0, itr2 = A.size() - 1;

	while (itr1 < itr2) {
		if (A[itr1] < A[itr2]) {
			tArea = A[itr1] * (itr2 - itr1);
			itr1++;
		} else {
			tArea = A[itr2] * (itr2 - itr1);
			itr2--;
		}

		if (tArea > area)
			area = tArea;
	}

	return area;
}
