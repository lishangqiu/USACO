#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> cowToCereal;
    vector<vector<int>> cerealToCow(M);
    for (int i=0; i<N; i++){
        int f, s;
        cin >> f >> s;
        cowToCereal.push_back({f-1, s-1});
        cerealToCow[f-1].push_back(i);
        cerealToCow[s-1].push_back(i);
    }

    int startingCereal = 0;
    for (int i=0; i<M; i++){
        if (cerealToCow[i].size() == 1){
            startingCereal = i;
            break;
        }
    }

    vector<int> assignedCereals(N, -1);
    queue<int> cerealTBD;
    cerealTBD.push(startingCereal);
    while (!cerealTBD.empty()){
        int cowSelectedForCereal = cerealToCow[cerealTBD.front()][0];
        assignedCereals[cowSelectedForCereal] = cerealTBD.front();
        for (int i=0; i<=1; i++){
            vector<int> &targetCerealsErase = cerealToCow[cowToCereal[cowSelectedForCereal][i]];
            if ((cowToCereal[cowSelectedForCereal][i] != cerealTBD.front()) && (cerealToCow[cowToCereal[cowSelectedForCereal][i]].size() != 0)){
                cerealTBD.push(cowToCereal[cowSelectedForCereal][i]);
            }
            targetCerealsErase.erase(std::remove(targetCerealsErase.begin(), targetCerealsErase.end(), cowSelectedForCereal), targetCerealsErase.end());
        }
        cerealTBD.pop();
    }
    cout << ":asdjfl";

}