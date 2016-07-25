/**
 * A hotel manager has to process N advance bookings of rooms for the next season.
 * His hotel has K rooms. Bookings contain an arrival date and a departure date.
 * He wants to find out whether there are enough rooms in the hotel to satisfy the demand.
 * Write a program that solves this problem in time O(N log N) .
 *
 * Input:
 * First list for arrival time of booking.
 * Second list for departure time of booking.
 * Third is K which denotes count of rooms.
 */

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
	int count = 1;
	int temp = 0;
	int depCount = 0;

	sort(arrive.begin(), arrive.end());
	sort(depart.begin(), depart.end());

	temp = depart[0];

	for (int i = 1; i < arrive.size(); i++) {
		if (arrive[i] < temp) {
			count++;
			if (count > K) {
				return false;
			}
		} else {
			count++;
			while (temp <= arrive[i]) {
				depCount++;
				temp = depart[depCount];
				count--;
			}
		}
	}

	if (count > K) {
		return false;
	} else {
		return true;
	}
}

