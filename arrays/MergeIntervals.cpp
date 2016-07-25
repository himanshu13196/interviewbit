/**
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 * Example 1:
 * Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * Make sure the returned intervals are also sorted.
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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
	vector < Interval > result;

	if (intervals.empty()) {
		result.push_back(newInterval);
		return result;
	}

	int strt = -1, flag = 1, flag2 = 1, last = -1, sz = intervals.size();

	if (newInterval.start > newInterval.end) {
		newInterval.start = newInterval.start + newInterval.end;
		newInterval.end = newInterval.start - newInterval.end;
		newInterval.start = newInterval.start - newInterval.end;
	}

	for (int i = 0; i < sz; i++) {
		if (((newInterval.start <= intervals[i].start) && (newInterval.end >= intervals[i].end)) || ((newInterval.start > intervals[i].start) && (newInterval.start < intervals[i].end))
				|| ((newInterval.end > intervals[i].start) && (newInterval.end < intervals[i].end)) || ((newInterval.start >= intervals[i].start) && (newInterval.end <= intervals[i].end))) {
			if (strt == -1) {
				strt = i;
			}
		} else if (strt != -1 && flag == 1) {
			last = i - 1;
			flag = 0;
		}
	}

	if (strt != -1) {
		if (last == -1) {
			last = sz - 1;
		}
		if (newInterval.start < intervals[strt].start) {
			intervals[strt].start = newInterval.start;
		}

		if (newInterval.end > intervals[last].end) {
			intervals[strt].end = newInterval.end;
		} else {
			intervals[strt].end = intervals[last].end;
		}
	}

	for (int i = 0; i < sz; i++) {
		if ((strt == -1) && (newInterval.start < intervals[i].start) && (flag2 == 1)) {
			result.push_back(newInterval);
			flag2 = 0;
		}

		result.push_back(intervals[i]);

		if (i == strt) {
			i = i + last - strt;
		}
	}

	if ((strt == -1) && (newInterval.start > intervals[sz - 1].end)) {
		result.push_back(newInterval);
	}

	return result;
}
