// 4/11 test cases. I think my entire thought process is flawed sooo RIP. Still somehow got 4 test cases

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

#define cin a_file

int main() {
  ifstream a_file ( "./prob1_silver_open22/2.in" );
  ll N;
  cin >> N;

  vector<set<ll>> incomingNodes(N+1);
  vector<ll> outgoingNodes(N+1);
  vector<ll> weights(N+1);
  ll sum = 0;
  for (ll i=1; i<N+1; i++) {
    ll idx;
    ll weight;
    cin >> idx >> weight;

    incomingNodes[idx].insert(i);
    outgoingNodes[i] = idx;
    weights[i] = weight;
    sum += weight;
  }
  
  ll ans = 0;
  vector<bool> visited(N+1);
  for (ll i=1; i<N+1; i++) {
    if (!visited[i] && incomingNodes[i].size() == 0) {
      ll currIdx = i;
      while (incomingNodes[currIdx].size() == 0) {
        visited[currIdx] = true;
        ans += weights[currIdx];
        incomingNodes[outgoingNodes[currIdx]].erase(currIdx);
        currIdx = outgoingNodes[currIdx];
      }
    }
  }

  ll min_loop = -1;
  for (ll i=1; i<N+1; i++) {
    if (incomingNodes[i].size() > 0) {
      ans += weights[outgoingNodes[i]];
      if (min_loop == -1 || min_loop > weights[outgoingNodes[i]]) {
        min_loop = weights[outgoingNodes[i]];
      }
    }
  }
  
  cout << (sum-min_loop) << endl;
}