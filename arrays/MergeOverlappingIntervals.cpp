/**
 * Given a collection of intervals, merge all overlapping intervals.
 * For example:
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * Make sure the returned intervals are sorted.
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool myCompare(Interval i, Interval j) {
	return (i.start < j.start);

}

bool overlap(Interval &k, Interval &l) {
	if (((k.start <= l.start) && (k.end >= l.end)) || ((k.start > l.start) && (k.start < l.end)) || ((k.end >= l.start) && (k.end < l.end)) || ((k.start >= l.start) && (k.end <= l.end))) {
		return true;
	} else {
		return false;
	}
}

Interval mergeInt(Interval &i, Interval &j) {
	Interval result;
	if (i.start < j.start) {
		result.start = i.start;
	} else {
		result.start = j.start;
	}

	if (i.end > j.end) {
		result.end = i.end;
	} else {
		result.end = j.end;
	}

	return result;
}

vector<Interval> Solution::merge(vector<Interval> &A) {

	vector < Interval > result;

	if (A.empty() || A.size() == 1) {
		result = A;
		return result;
	}

	sort(A.begin(), A.end(), myCompare);

	//Interval mover;
	int mflag = -1;

	for (int i = 1; i < A.size(); i++) {
		if (overlap(A[i - 1], A[i])) {
			A[i] = mergeInt(A[i - 1], A[i]);
			if (i == A.size() - 1) {
				result.push_back(A[i]);
			}
		} else {
			result.push_back(A[i - 1]);
			if (i == A.size() - 1) {
				result.push_back(A[i]);
			}
		}
	}

	return result;

}
