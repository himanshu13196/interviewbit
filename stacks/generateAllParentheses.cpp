/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 * Return 0 / 1 ( 0 for false, 1 for true ) for this problem
 */

int Solution::isValid(string A) {
	stack<char> braces;

	for (int i = 0; i < A.size(); i++) {
		switch (A[i]) {
		case '(':
			braces.push(A[i]);
			break;
		case ')':
			if (braces.empty() || braces.top() != '(') {
				return 0;
			} else {
				braces.pop();
			}
			break;
		case '{':
			braces.push(A[i]);
			break;
		case '}':
			if (braces.empty() || braces.top() != '{') {
				return 0;
			} else {
				braces.pop();
			}
			break;
		case '[':
			braces.push(A[i]);
			break;
		case ']':
			if (braces.empty() || braces.top() != '[') {
				return 0;
			} else {
				braces.pop();
			}
			break;
		default:
			return 0;
		}
	}

	if (!(braces.empty())) {
		return 0;
	}

	return 1;
}
