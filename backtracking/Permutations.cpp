//Given a collection of numbers, return all possible permutations.
void permHelp(vector<int> &A, vector<vector<int> > &sol, vector<int> &curr, int& sz) {
	int temp;
	for (int i = 0; i < A.size(); i++) {
		curr.push_back(A[i]);
		if (curr.size() == sz) {
			sol.push_back(curr);
		} else if (curr.size() < sz) {
			temp = A[i];
			A.erase(A.begin() + i);
			permHelp(A, sol, curr, sz);
			A.insert(A.begin() + i, temp);
		}
		curr.pop_back();
	}

	return;
}

vector<vector<int> > Solution::permute(vector<int> &A) {

	vector < vector<int> > sol;
	vector<int> curr;
	int sz = A.size();

	permHelp(A, sol, curr, sz);

	return sol;
}
