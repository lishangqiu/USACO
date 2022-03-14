#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main(){
    int N;
    cin >> N;
    
    vector<int> cows(N);
    for (int &cow : cows){
        cin >> cow;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> minHeap1;
    vector<int> poppedPos1(N, -1);
    minHeap1.push({cows[0], 0});
    for (int i=1; i<N; i++){
        while (!minHeap1.empty() && (minHeap1.top().first < cows[i])){
            poppedPos1[minHeap1.top().second] = i;
            minHeap1.pop();
        }
        minHeap1.push({cows[i], i});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> minHeap2;
    vector<int> poppedPos2(N, -1);
    minHeap2.push({cows[N-1], N-1});
    for (int i=N-2; i>=0; i--){
        while (!minHeap2.empty() && (minHeap2.top().first < cows[i])){
            poppedPos2[minHeap2.top().second] = i;
            minHeap2.pop();
        }
        minHeap2.push({cows[i], i});
    }

    long long ans = 0;
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            if ((poppedPos1[i] == -1 || poppedPos1[i] >= j) && (poppedPos2[j] == -1 || poppedPos2[j] <= i)){
                ans += j-i+1;
                continue;
            }
        }
    }
    cout << ans;

}