#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  // M here is the number of coins
  int M;

  cin >> N >> M;

  vector<int> C(M);
  for (int &coin : C){
    cin >> coin;
  }

  vector<vector<int>> dp(N, vector<int>(N, 0));
  for (int &coin : C){
    dp[0][coin-1] = 1;
  }

  for (int i=1; i<N; i++){
    for (int j=0; j<N; j++){
      dp[i][j] += dp[i-1][j];
      for (int &coin : C){
        if ((j+coin) >= N){
          continue;
        }
        dp[i][(j+coin)] += dp[i-1][j];
      }
    }
  }
  cout << dp[N-1][N-1] << endl;
} 