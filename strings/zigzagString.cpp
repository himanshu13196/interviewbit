/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 * P.......A........H.......N
 * ..A..P....L....S....I...I....G
 * ....Y.........I........R
 * And then read line by line: PAHNAPLSIIGYIR
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
 */

string Solution::convert(string A, int B) {

    if(B >= A.size() || B <= 1 || A.size() <= 1) {
        return A;
    }

    string arr[B], sol;
    int dir = 1, itr1 = 0,itr2 = 0;

    while(itr2 < A.size()) {
        arr[itr1] += A[itr2];
        itr1 = itr1+dir;

        if(itr1 == B-1) {
            dir = -1;
        }

        if(itr1 == 0) {
            dir = 1;
        }
        itr2++;
    }

    for(int i = 0; i < B; i++) {
        sol += arr[i];
    }

    return sol;
}
