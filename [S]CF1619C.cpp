#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;

    for (int i=0;i<t; i++){
        string a;
        string s;
        string b;

        cin >> a >> s;
        vector<char> a_arr(a.begin(), a.end());
        vector<char> s_arr(s.begin(), s.end());

        int curr_sum = 0;
        int curr_a_ind = a_arr.size()-1;
        bool second_number = false;
        for (int i=(s_arr.size()-1); i>=0; i--){
            if (curr_a_ind < 0){
                b.insert(0, string(1, s_arr[i]));
                continue;
            }

            if (second_number){
                curr_sum += (s_arr[i]-'0')*10;
                if (curr_sum-(a_arr[curr_a_ind]-'0')>10 || curr_sum-(a_arr[curr_a_ind]-'0')<0){
                    cout << "-1" << endl;
                    goto breaking;
                }  
                else{
                    b.insert(0, to_string(curr_sum-(a_arr[curr_a_ind]-'0')));
                    curr_a_ind--;
                    second_number=false;
                    curr_sum = 0;
                }
            }
            else{
                curr_sum += (s_arr[i]-'0');
                if (curr_sum < (a_arr[curr_a_ind]-'0')){
                    second_number = true;
                    continue;
                }
                else{
                    b.insert(0, to_string(curr_sum-(a_arr[curr_a_ind]-'0')));
                    curr_a_ind--;
                    curr_sum = 0;
                }
            }
        }

        if (curr_a_ind >= 0){
            cout << "-1" << endl;
            goto breaking;
        }

        
        b.erase(0, min(b.find_first_not_of('0'), b.size()-1));
        cout << b << endl;

        breaking:
        {
            
        }
    }
}
