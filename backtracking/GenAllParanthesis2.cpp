/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.
*/

void paranthHelp(vector<string> &sol, string curr, int open, int close, int &n) {

	if (open < n) {
		curr += '(';
		open++;
	}

	if (open < n) {
		paranthHelp(sol, curr, open, close, n);
	}

	while (close < open) {
		curr += ')';
		close++;
		if (close == n) {
			sol.push_back(curr);
			return;
		} else if (open < n) {
			paranthHelp(sol, curr, open, close, n);
		}
	}

	return;
}

vector<string> Solution::generateParenthesis(int A) {

	vector < string > sol;

	if (A < 1)
		return sol;

	int open = 0, close = 0;
	string curr = "";

	paranthHelp(sol, curr, open, close, A);

	return sol;

}
