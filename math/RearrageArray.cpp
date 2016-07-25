//Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
void Solution::arrange(vector<int> &A) {

	int old, nw;

	int sz = A.size();

	for (int i = 0; i < sz; i++) {
		if (A[i] < i) {
			nw = A[A[i]] / sz;
		} else {
			nw = A[A[i]];
		}

		old = A[i];

		A[i] = old * sz + nw;
	}

	for (int i = 0; i < sz; i++) {
		A[i] = A[i] % sz;
	}

}
