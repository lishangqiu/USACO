#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;

  for (int a = 0; a < t; a++){
    int n;
    cin >> n;

    vector<int> vertice_encoding(n);
    for (auto &num : vertice_encoding){
      cin >> num;
    }

    vector<int> final_order(n);
    for (auto &num : final_order){
      cin >> num;
    }
    
    // Figure out the root
    int root_val = -1; // this would be the idx+1
    for (int i = 0; i < n; i++){
      if (vertice_encoding[i] == i+1){
        root_val = vertice_encoding[i];
        break;
      }
    }

    unordered_map<int, unordered_set<int>> tree_parent_childs;
    for (int i = 0; i < n; i++){
      int pos_temp = i+1;

      if (pos_temp == root_val){
        continue;
      }
      tree_parent_childs[vertice_encoding[i]].insert(pos_temp);
    }

    // The smallest has to be the root node
    if (final_order[0] != root_val){
      cout << "-1" << endl;
      continue;
    }

    unordered_set<int> acceptabled_children = tree_parent_childs[root_val];
    vector<int> final_answer(n, -1);
    final_answer[root_val-1] = 0;
    vector<int> distances(n, -1);
    distances[root_val-1] = 0;
    
    int latest_biggest = 0;

    for (int i = 1; i < n; i++){
      int curr_vert_idx = final_order[i];
      if (acceptabled_children.find(curr_vert_idx) == acceptabled_children.end()){
        cout << "-1" << endl;
        goto failed;
      }
      acceptabled_children.insert(tree_parent_childs[curr_vert_idx].begin(), tree_parent_childs[curr_vert_idx].end());
      int target_distance = latest_biggest + 1;
      final_answer[curr_vert_idx-1] = target_distance - distances[vertice_encoding[curr_vert_idx-1]-1];
      distances[curr_vert_idx-1] = target_distance;
      latest_biggest = target_distance;
    }

    for (auto p : final_answer){
      cout << p << " ";
    }
    cout << endl;

    failed:
    {
    }
  }
}