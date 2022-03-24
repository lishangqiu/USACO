#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        vector<int> digits;
        ll n, s;
        cin >> n >> s;

        // IMPORTANT: digits here is reversed, i.e. idx 0 would be the last digit
        while (n != 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        
        int digitsSum = 0;
        ll currSteps = 0;
        for (int dig : digits){
            digitsSum += dig;
        }

        int idx = 0;
        while (digitsSum > s){
            // start creating new digits
            if (idx >= digits.size()){

            }
            else{
                int dig_sum_minus = digits[idx] - 1;
                if (digitsSum - dig_sum_minus <= s){
                    int dig_sum_minus = (digitsSum-s)
                }

                int num_add = 10-digits[idx];
                currSteps += num_add * pow(10, idx);
                digitsSum-=digits[idx]
            }
        }
    }
}