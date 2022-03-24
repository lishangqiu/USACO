#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t;
  cin >> t;
  for (int t_x=0; t_x<t; t_x++){
    bool failed;
    int m, n, k;
    cin >> m >> n >> k;

    vector<int> f_arr(n+1);

    for (int i=1; i<(n+1); i++){
      int x;
      cin >> x;
      f_arr[i] = x;
    }

    vector<int> dist_arr(n+1);
    for (int i=1; i<(n+1); i++){
      if (f_arr[i] > (m-k) && (i>(m-k))){
        dist_arr[i] = 0;
      }
      else{
        // positive means wants to go up in position
        dist_arr[i] = i-f_arr[i];
      }
    }

    int num_sorted = 0;
    int num_skipped = 0;
    for (int i=1; i<(n+1); i++){
      int curr_dist = dist_arr[i]-num_sorted;
      if (curr_dist <= 0){
        num_skipped += 1;
      }
      else if(curr_dist >= k){
        int num_needed_sorted = (curr_dist-k)+1;
        if ((i-num_sorted-num_skipped) < num_needed_sorted){
          failed = true;
        }
        else{
          num_sorted += num_needed_sorted;
        }
      }
    }

    if (num_skipped >= k){
      failed = true;
    }

    if (!failed){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }

  }
}