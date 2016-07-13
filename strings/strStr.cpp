/**
 * strstr - locate a substring ( needle ) in a string ( haystack ).
 */

//KMP Search
int Solution::strStr(const string &haystack, const string &needle) {
	int sz1 = haystack.size(), sz2 = needle.size();

	if (sz1 == 0 || sz2 == 0 || (sz2 > sz1))
		return -1;

	int start, itr1 = 0, itr2 = 0, flag, prfx[sz2], j = 0;
	prfx[0] = 0;

	for (int i = 1; i < sz2; i++) {
		if (needle[i] == needle[j]) {
			prfx[i] = j + 1;
			j++;
		} else {
			while (j > 0) {
				j = prfx[j - 1];
				if (needle[i] == needle[j]) {
					prfx[i] = j + 1;
					j++;
					break;
				}
			}

			if (j == 0) {
				if (needle[i] == needle[j]) {
					prfx[i] = j + 1;
					j++;
				} else {
					prfx[i] = 0;
				}
			}
		}
	}

	int count = 0;
	j = 0;

	for (int i = 0; i < sz1; i++) {
		if (j > sz2 - 1) {
			return (i - sz2);
		}

		if (haystack[i] == needle[j]) {
			j++;
		} else {
			while (j > 0) {
				j = prfx[j - 1];
				if (haystack[i] == needle[j]) {
					j++;
					break;
				}
			}
			if (j == 0) {
				if (haystack[i] == needle[j]) {
					j++;
				}
			}
		}
	}

	if (j > sz2 - 1) {
		return (sz1 - sz2);
	} else {
		return -1;
	}
}
