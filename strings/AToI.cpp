//Implement atoi to convert a string to an integer.

int Solution::atoi(const string &A) {
    long sol = 0;
    int start = 0, neg = 1;

    while(A[start] == 32) {
        start++;
    }

    if(A[start] == '-') {
        start++;
        neg = -1;
    }

    if(A[start] == '+') start++;

    for(int i = start; i < A.size(); i++) {
        if(A[i] >= '0' && A[i] <= '9') {
            sol = sol*10 + neg * (A[i] - 48);
            if(neg == 1) {
                if(sol > INT_MAX) {
                    return INT_MAX;
                }
            } else {
                if(sol < INT_MIN) {
                    return INT_MIN;
                }
            }
        } else {
            break;
        }
    }

    return sol;
}
