#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n, k;
        cin >> n >> k;
        string input;
        cin >> input;
        sort(input.begin(), input.end());

        int numPairs = 0;
        int numSingles = 0;
        char prev = '-';
        for (char i : input){
            if (prev != i){
                numSingles++;
                prev = i;

                continue;
            }
            else{
                numPairs++;
                prev = '-';
                numSingles--;
            }
        }

        int eachColorPairs = floor(((float)numPairs/(float)k));
        numSingles += (numPairs - (eachColorPairs*k))*2;

        if (numSingles >= k){
            cout << (eachColorPairs*2)+1 << endl;
        }
        else{
            cout << eachColorPairs*2 << endl;
        }
    }
}