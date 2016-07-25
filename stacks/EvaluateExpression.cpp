/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Examples:
 * ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 * ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

int Solution::evalRPN(vector<string> &A) {

	stack<int> nums;
	int op1, op2, temp;

	for (int i = 0; i < A.size(); i++) {

		if (A[i].size() > 1 || isdigit(A[i][0])) {
			temp = 0;
			int neg = 1;
			int j = 0;

			if (A[i][0] == '-') {
				neg = -1;
				j = 1;
			} else {
				neg = 1;
				j = 0;
			}

			for (; j < A[i].size(); j++) {
				temp = temp * 10 + (A[i][j] - '0');
			}

			nums.push(neg * temp);

		} else {

			if (!nums.empty()) {
				op2 = nums.top();
				nums.pop();
			} else {
				cout << " error1:" << A[i][0] << " i:" << i;
			}

			if (!nums.empty()) {
				op1 = nums.top();
				nums.pop();
			} else {
				cout << " error2:" << A[i][0] << " i:" << i;
			}

			switch (A[i][0]) {
			case '+':
				op1 += op2;
				break;
			case '-':
				op1 -= op2;
				break;
			case '*':
				op1 *= op2;
				break;
			case '/':
				op1 = op1 / op2;
				break;
			default:
				break;
			}

			nums.push(op1);

		}
	}

	return nums.top();
}
