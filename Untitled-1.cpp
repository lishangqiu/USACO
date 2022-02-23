#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int minNumSteps = INT8_MAX;


void recurse(vector<vector<char>> &arr, vector<vector<bool>> &checked, pair<int, int> currPos, pair<int, int> targetPos, int numStepsTaken){
    if (currPos == targetPos){
      cout << "ALKFJDSLJGLS" << numStepsTaken << endl;
      minNumSteps = min(minNumSteps, numStepsTaken);
    }
    
    if (currPos.first >= arr.size() || currPos.second >= arr.size() || currPos.first < 0 || currPos.second < 0){
        return;
    }
    if (checked[currPos.first][currPos.second]){
      return;
    }
    if (arr[currPos.first][currPos.second] == 'O'){
        return;
    }

    cout << currPos.second << currPos.first << endl;
    checked[currPos.first][currPos.second] = true;

    recurse(arr, checked, {currPos.first + 1, currPos.second}, targetPos, numStepsTaken+1);
    recurse(arr, checked, {currPos.first - 1, currPos.second }, targetPos, numStepsTaken+1);
    recurse(arr, checked, {currPos.first, currPos.second+1}, targetPos, numStepsTaken+1);
    recurse(arr, checked, {currPos.first , currPos.second - 1}, targetPos, numStepsTaken+1);
    
}



int main()
{
    int N;
    cin >> N;
    vector<vector<char>> arr(N, vector<char>(N, ' '));
    vector<vector<bool>> checked(N, vector<bool>(N, false));

    pair<int, int> posA;
    pair<int, int> posB;
        
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            char temp;
            cin >> temp;
            arr[i][j] = temp;
            if (temp == 'A'){
                posA = {i, j};
            }
            else if (temp == 'B'){
                posB = {i, j};
            }
        }
    }
    
    cout << "hi";
    recurse(arr, checked, posA, posB, 0);
    cout << "min: " << minNumSteps;

    system("pause");
    return 0;
}
