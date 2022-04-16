// 11/11 test cases. LETS GOOOOO

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int str_size = s.size();

  vector<int> prefix_C(str_size+1, 0);
  vector<int> prefix_O(str_size+1, 0);
  vector<int> prefix_W(str_size+1, 0);
  for (int i=0; i<str_size; i++) {
    prefix_C[i+1] = prefix_C[i];
    prefix_O[i+1] = prefix_O[i];
    prefix_W[i+1] = prefix_W[i];

    if (s[i] == 'C') {
      prefix_C[i+1]++;
    }
    else if (s[i] == 'O') {
      prefix_O[i+1]++;
    }
    else {
      prefix_W[i+1]++;
    }
  }

  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int a, b;
    cin >> a >> b;
    int temp_C = (prefix_C[b] - prefix_C[a-1]) % 2;
    int temp_O = (prefix_O[b] - prefix_O[a-1]) % 2;
    int temp_W = (prefix_W[b] - prefix_W[a-1]) % 2;

    if ((temp_C == 1 && temp_O == 0 && temp_W == 0) || (temp_C == 0 && temp_O == 1 && temp_W == 1)) {
      cout << "Y";
    }
    else {
      cout << "N";
    }
  }
  cout << endl;
}