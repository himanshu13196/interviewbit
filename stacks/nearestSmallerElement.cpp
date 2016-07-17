/**
 * Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
 * More formally,
 * G[i] for an element A[i] = an element A[j] such that
 * j is maximum possible AND
 * j < i AND
 * A[j] < A[i]
 * Elements for which no smaller element exist,consider next smaller element as -1.
 */

vector<int> Solution::prevSmaller(vector<int> &A) {

	stack<int> small;
	int temp;

	for (int i = 0; i < A.size(); i++) {
		while ((!small.empty()) && small.top() >= A[i]) {
			small.pop();
		}
		temp = A[i];
		if (small.empty()) {
			A[i] = -1;
		} else {
			A[i] = small.top();
		}

		small.push(temp);
	}

	return A;
}
