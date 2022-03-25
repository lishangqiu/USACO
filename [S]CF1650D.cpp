#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
   
    for (int t_=0;t_<t;t_++){
        int n;
        cin >> n;
        vector<int> valIdx(n);
        for (int i=0; i<n; i++){
            int temp;
            cin >> temp;
            valIdx[temp-1] = i;
        }
        vector<int> ans(n);
        for (int i=n-1; i>=0; i--){
            int move_left = 0;
            if (valIdx[i]<i){
                move_left = (i+1)-(i-valIdx[i]);
                ans[i] = move_left;
            }
            else{
                move_left = (valIdx[i]-i);
            }
            for (int j=0; j<=i; j++){
                int temp_pos = valIdx[j]-move_left;
                if (temp_pos<0){
                    temp_pos = (i+1)+temp_pos;
                }
                valIdx[j] = temp_pos;
            }
        }
        for (int i=0; i<n; i++){
          cout << ans[i] << endl;
        }
    }
}