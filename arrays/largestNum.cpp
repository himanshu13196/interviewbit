/**
 * Given a list of non negative integers, arrange them such that they form the largest numbe
 */

bool myCompare(string i, string j) {
	return (i + j) > (j + i);
}

string Solution::largestNumber(const vector<int> &A) {

	bool allZero = true;
	vector < string > temp;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] != 0) {
			allZero = false;
		}

		temp.push_back(to_string(A[i]));
	}

	if (allZero)
		return "0";

	sort(temp.begin(), temp.end(), myCompare);

	string result = temp[0];

	for (int i = 1; i < temp.size(); i++) {
		result += temp[i];
	}

	return result;

}
