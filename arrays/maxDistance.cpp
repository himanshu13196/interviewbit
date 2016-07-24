/**
 * Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
 * If there is no solution possible, return -1.
 */

bool myCompare(pair<int, int> j, pair<int, int> k) {
	return j.first < k.first;
}

int Solution::maximumGap(const vector<int> &A) {
	if (A.size() < 2) {
		return 0;
	}

	vector < pair<int, int> > arr;

	pair<int, int> temp;

	for (int i = 0; i < A.size(); i++) {
		temp.first = A[i];
		temp.second = i;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end(), myCompare);

	int len = arr.size();
	int lastIndex = arr[len - 1].second;
	int ans = 0;

	for (int i = len - 2; i >= 0; i--) {
		ans = max(ans, lastIndex - arr[i].second);
		lastIndex = max(lastIndex, arr[i].second);
	}

	return ans;
}
