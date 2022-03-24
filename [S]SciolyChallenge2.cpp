// This is for Science Olympiad Birdso Satellite Div B Cybersecurity "hands on" problem #2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> in_array(n);
    for (auto &num : in_array){
        cin >> num;
    }

    if (n == 1){
        cout << in_array[0] << endl;
        return 0;
    }
    if (n==2){
        cout << max(in_array[0], in_array[1]) << endl;
        return 0;
    }

    // DP ;)
    vector<int> dp(n);
    for (int i=(n-1); i>=0; i--){
        if (i+2 > (n-1)){
            dp[i] = in_array[i];
            continue;
        }
        if (i+3 > (n-1)){
            dp[i] = in_array[i] + in_array[i+2];
            continue;
        }

        dp[i] = in_array[i] + max(dp[i+2], dp[i+3]);
    }
    cout << max(dp[0], dp[1]) << endl;
}