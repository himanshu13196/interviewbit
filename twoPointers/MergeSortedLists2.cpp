/**
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 */

void Solution::merge(vector<int> &A, vector<int> &B) {

	vector<int>::iterator itr1 = A.begin(), itr2 = B.begin();

	while (itr1 != A.end() && itr2 != B.end()) {

		if (*itr1 >= *itr2) {
			itr1 = A.insert(itr1, *itr2);
			itr2++;
			itr1++;
		} else {
			itr1++;
		}
	}

	while (itr2 != B.end()) {
		itr1 = A.insert(itr1, *itr2);
		itr1++;
		itr2++;
	}
}
