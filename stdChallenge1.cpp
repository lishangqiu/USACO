#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// 0 = N
typedef pair<int, pair<int, int>> c_l;
vector<c_l> inputStuff;
int recurseForInput(int numLeft){
    char direction;
    int x, y;
    cin >> direction >> x >> y;
    inputStuff.push_back({(direction == 'N') ? 0 : 1, {x, y}});
    if (numLeft <= 0){
        return;
    }
    else{
        recurseForInput(numLeft--);
    }
 }

int main(){
    int N;
    cin >> N;
    recurseForInput(N);

}