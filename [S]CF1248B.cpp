// a lil warmup question for tmr's usaco

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ll n;
  cin >> n;
  vector<ll> ints(n);

  for (auto &int_thing : ints) {
    cin >> int_thing;
  }
  sort(ints.begin(), ints.end());
  ll x = 0;
  ll y = 0;
  for (ll i=0; i<(n/2); i++) {
    y += ints[i];
    x += ints[n-i-1];
  }
  if (n%2 != 0){
    x += ints[n/2];
  }
  cout << (x*x + y*y) << endl;
}