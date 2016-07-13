/**
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

int Solution::romanToInt(string A) {

	map<char, int> rToI;

	rToI['I'] = 1;
	rToI['V'] = 5;
	rToI['X'] = 10;
	rToI['L'] = 50;
	rToI['C'] = 100;
	rToI['D'] = 500;
	rToI['M'] = 1000;

	int res = 0;
	int temp1 = 0, temp2 = 0;

	for (int i = 0; i < A.size(); i++) {

		temp1 = rToI[A[i]];
		if (i < A.size() - 1) {
			temp2 = rToI[A[i + 1]];
		} else {
			temp2 = 0;
		}

		if (temp1 < temp2) {
			res = res - temp1;
		} else {
			res = res + temp1;
		}
	}

	return res;

}
