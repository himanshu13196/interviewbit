//Implement pow(A, B) % C
int Solution::Mod(int A, int B, int C) {

    long long temp;
    if(B == 2) {
        temp = ((long long)A * A)%C;

        if(temp < 0) temp += C;

        return temp;

    } else if(B==1) {

        temp = (long long)A % C;

        if(temp < 0) temp += C;

        return (temp);

    } else if(B == 0) {
        if(A == 0)
            return 0;
        else
            return 1;

    } else {

        if(B%2 == 0) {

            temp = Mod(A, B/2, C);

            temp = (temp * temp)%C;

            if(temp < 0) temp += C;

            return temp;

        } else {
            temp = Mod(A, B-1, C);

            temp = (temp * (long long)A)%C;

            if(temp < 0) temp += C;

            return temp;
        }
    }
}
