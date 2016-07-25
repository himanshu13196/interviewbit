/**
 * Write a program to validate if the input string has redundant braces?
 * Return 0/1
 * 0 -> NO 1 -> YES
 * Input will be always a valid expression
 * and operators allowed are only + , * , - , /
 * Example:
 * ((a+b)) has redundant braces so answer will be 1
 * (a + (a + b)) doesn't have have any redundant braces so answer will be 0
 */

int Solution::braces(string A) {
    stack<char> brcs;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == '(') {
            brcs.push(A[i]);
        } else if(A[i] == ')') {
            if(brcs.empty()) {
                return 1;
            } else if(brcs.top() == '(') {
                return 1;
            } else {
                while((!brcs.empty()) && brcs.top() != '(') {
                    brcs.pop();
                }
                if((!brcs.empty()) && brcs.top() == '(') {
                    brcs.pop();
                }
            }
        } else if(A[i] == '+' || A[i] == '*' || A[i] == '/' || A[i] == '-') {
            if(!brcs.empty()) {
                brcs.push(A[i]);
            }
        }
    }

    if(brcs.empty()) {
        return 0;
    } else {
        return 1;
    }
}
