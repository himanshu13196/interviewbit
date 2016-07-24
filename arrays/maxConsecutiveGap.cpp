/**
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 * Try to solve it in linear time/space.
 */

int Solution::maximumGap(const vector<int> &A) {

	if (A.size() < 2) {
		return 0;
	}
	vector<int> aux = A;
	int result = 0;
	int temp = 0;

	sort(aux.begin(), aux.end());

	for (int i = 1; i < aux.size(); i++) {
		temp = aux[i] - aux[i - 1];
		if (temp > result) {
			result = temp;
		}
	}

	return result;

}
