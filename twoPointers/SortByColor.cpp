/**
 * Given an array with n objects colored red, white or blue,
 * sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 * Note: Using library sort function is not allowed.
 */

void Solution::sortColors(vector<int> &A) {

	int count0 = 0, count1 = 0, count2 = 0;

	for (int i = 0; i < A.size(); i++) {
		switch (A[i]) {
		case 0:
			count0++;
			break;
		case 1:
			count1++;
			break;
		case 2:
			count2++;
			break;
		default:
			break;
		}
	}

	int itr = 0;

	while (count0 > 0) {
		A[itr] = 0;
		itr++;
		count0--;
	}

	while (count1 > 0) {
		A[itr] = 1;
		itr++;
		count1--;
	}

	while (count2 > 0) {
		A[itr] = 2;
		itr++;
		count2--;
	}
}
