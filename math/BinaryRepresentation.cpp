/**
 *
 */

string Solution::findDigitsInBinary(int A) {
    string result;
    int rem;

    do {
        rem = A%2;
        A = A/2;
        if(rem == 0) {
            result.push_back('0');
        } else {
            result.push_back('1');
        }

    } while(A>0);

    reverse(result.begin(), result.end());
    return result;

}
