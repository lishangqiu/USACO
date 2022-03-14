#include <iostream>
#include <vector>

using namespace std;

// check if 
int solve(vector<vector<int>> &from_edges, vector<int> &can_get, int curr_val, int starting_val){
  if (can_get[curr_val] == 2){
    return true;
  }
  if (can_get[curr_val] == 1){
    return false;
  }
  can_get[curr_val] = 1;

  for (auto x : from_edges[curr_val]){
    if (solve(from_edges, can_get, x, starting_val)){
      can_get[curr_val] = 2;
      return true;
    }
  }
  return false;
}

int main(){
  int n;
  cin >> n;

  vector<vector<int>> to_edges(n+1);
  vector<vector<int>> from_edges(n+1); // at index i, the ith cow accepts all of the gifts in that vector
  for (int i=1;i<(n+1);i++){
    vector<int> temp(n);
    for (int j=0; j<n; j++){
      int x;
      cin >> x;
      temp[j] = x;
    }

    for (auto x : temp){
      if (x==i){
        break;
      }
      from_edges[i].push_back(x);
      to_edges[x].push_back(i);
    }
  }

  for (int i=1;i<(n+1);i++){
    if (from_edges[i].size() == 0){
      cout << i << endl;
      continue;
    }
    
    vector<int> can_get(n+1, 0);
    can_get[i] = 2;
    int max_int = i;
    for (auto x : from_edges[i]){
      if (solve(from_edges, can_get, x, i)){
        max_int = x;
        break;
      }
    }

    cout << max_int << endl;
  }

}