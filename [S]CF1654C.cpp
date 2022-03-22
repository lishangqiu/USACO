#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

bool solve(multiset<ll> &piecesLeft, ll startingSum){
  if (piecesLeft.size() == 0) return true;
  
  auto itr = piecesLeft.find(startingSum);
  if (itr != piecesLeft.end()){
    piecesLeft.erase(itr);
    return true;
  }
  else{
    if (startingSum > *piecesLeft.begin() && startingSum >= 2) {
      if (startingSum % 2 == 0) {
        return (solve(piecesLeft, startingSum/2) && solve(piecesLeft, startingSum/2));
      }
      else{
        return (solve(piecesLeft, startingSum/2) && solve(piecesLeft, startingSum/2+1));
      }
    }
    else{
      return false;
    }
  }
}

int main() {
  int t;
  cin >> t;
  
  for (int t_=0; t_<t; t_++){
    int n;
    cin >> n;

     multiset<ll> pieces;
     ll sum = 0;
     for (int i=0; i<n; i++){
        int temp;
        cin >> temp;
        pieces.insert(temp);
        sum += temp;
     }

     solve(pieces, sum);
     cout << ((pieces.size() == 0) ? "YES" : "NO") << endl;

  }
}
