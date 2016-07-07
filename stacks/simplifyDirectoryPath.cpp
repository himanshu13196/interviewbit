/**
 * Given an absolute path for a file (Unix-style), simplify it.
 * Examples:
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * Note that absolute path always begin with ‘/’ ( root directory )
 * Path will not have whitespace characters.
 */

string Solution::simplifyPath(string A) {

	stack < string > dir;
	string sol = "";
	string temp;

	for (int i = 0; i < A.size(); i++) {
		if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z')) {
			temp = "";
			temp += A[i];
			i++;
			while (i < A.size() && ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z'))) {
				temp += A[i];
				i++;
			}
			dir.push(temp);
			i--;
		} else if (A[i] == '.') {
			int count = 1;
			temp = ".";
			i++;
			while (i < A.size() && A[i] == '.') {
				count++;
				temp += '.';
				i++;
			}
			i--;

			if (count == 2) {
				if (!dir.empty())
					dir.pop();
			} else if (count > 2) {
				dir.push(temp);
			}
		}
	}

	if (dir.empty()) {
		sol = '/';
	} else {
		while (!(dir.empty())) {
			temp = "";
			temp += '/';
			temp += dir.top();
			temp += sol;
			sol = temp;
			dir.pop();
		}
	}

	return sol;
}
