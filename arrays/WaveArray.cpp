/**
 * Given an array of integers, sort the array into a wave like array and return it,
 * In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....
 */

vector<int> Solution::wave(vector<int> &A) {
	vector<int> result = A;
	sort(result.begin(), result.end());

	int i = 0;

	while (i < (result.size() - 1)) {
		result[i] = result[i] + result[i + 1];
		result[i + 1] = result[i] - result[i + 1];
		result[i] = result[i] - result[i + 1];
		i = i + 2;
	}

	return result;
}
