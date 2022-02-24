#include <iostream>
#include <math.h>

using namespace std;
int main(){
    int N;
    cin >> N;

    for (int i=0; i<N; i++){
        int ans = 0;
        int a, b;
        cin >> a >> b;

        while (a > b){
            if (a % 2 != 0){
                a += 1;
                ans++;
            }
            a /= 2;
            ans++;
        }

        while (1){
            if (a * 2 <= b){
                ans++;
                a *= 2;
            }
            else{
                break;
            }
        }

        int diff = b - a;
        bool asdf = false;
        while (1){
            int temp = diff;
            if (diff % 2 != 0){
                temp -= 1;
                ans++;
                asdf = true;
            }
            else{
                asdf = false;
            }
            if ((temp / 2) > 3){
                temp /= 2;
                diff = temp;
                ans++;
            }
            else{
                if (asdf){
                    ans--;
                }

                break;
            }
        }
        ans += diff;

        cout << ans << endl;
    }
}