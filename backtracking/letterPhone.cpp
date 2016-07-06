/*Given a digit string, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 The digit 0 maps to 0 itself.
 The digit 1 maps to 1 itself.
 Input: Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Make sure the returned strings are lexicographically sorted.
 */

map<char, string> dtos = { { '0', "0" }, { '1', "1" }, { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" }, { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };

vector<string> Solution::letterCombinations(string A) {

	vector < string > sol;

	if (A.size() == 0) {
		return sol;
	} else if (A.size() == 1) {

		string dig = dtos[A[0]];
		string temp;

		for (int i = 0; i < dig.size(); i++) {
			temp = dig[i];
			sol.push_back(temp);
		}
		return sol;
	} else {
		string temp = A.substr(1, A.size() - 1);
		sol = letterCombinations(temp);
		string dig = dtos[A[0]];
		int sz = sol.size();

		for (int j = 1; j < dig.size(); j++) {
			for (int i = 0; i < sz; i++) {
				temp = dig[j] + sol[i];
				sol.push_back(temp);
			}
		}

		for (int l = 0; l < sz; l++) {
			sol[l] = dig[0] + sol[l];
		}
		return sol;
	}
}
