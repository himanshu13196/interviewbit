/**
 * Given a number N, find all factors of N.
 */

vector<int> Solution::allFactors(int A) {
    vector<int> result;
    vector<int> high;
    int sqN = sqrt(A);
    int count = 0;

    result.push_back(1);

    if(A == 1) {
        return result;
    }

    for(int i=2; i <= sqN; i++) {
        if(A % i == 0) {
            result.push_back(i);
            if(i != (A/i)) {
                high.push_back(A/i);
                count++;
            }
        }
    }

    for(int j = 0; j < count; j++) {
        result.push_back(high[count-1-j]);
    }


    result.push_back(A);
    return result;
}
