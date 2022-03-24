#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
   
  for (int t_=0;t_<t;t_++){
    ll n, x;
    cin >> n >> x;
       
    multiset<ll> ints_thing;
    for (ll i=0; i<n; i++) {
      ll temp;
      cin >> temp;
      ints_thing.insert(temp);
    }

    ll ans = 0;
    while (!ints_thing.empty()) {
      auto itr = ints_thing.find(*ints_thing.begin()*x);

      if (itr != ints_thing.end()) {
        ints_thing.erase(itr);
      }
      else {
        ans++;
      }
      ints_thing.erase(ints_thing.begin());
    }
    cout << ans << endl;
  }

}