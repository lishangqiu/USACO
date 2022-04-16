// 10/11 test cases. No idea what went wrong with the last one. Probably some bug(will anayzse ltr)

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  string t;
  cin >> t;

  int str_size = s.size();

  vector<set<int>> ignoreCharsToWork(18);
  for (int i=0; i<18; i++) {
    vector<int> count_diff_s(18);
    vector<int> count_diff_t(18);

    int s_idx = 0;
    int t_idx = 0;

    int num_s = 0;
    int num_t = 0;

    while (t_idx < str_size && s_idx < str_size) {
      while (s_idx < str_size && s[s_idx]-'a' != i) {
        count_diff_s[s[s_idx]-'a']++;
        s_idx++;
      }
      while (t_idx < str_size && t[t_idx]-'a' != i) {
        count_diff_t[t[t_idx]-'a']++;
        t_idx++;
      }

      for (int k=0; k<18; k++) {
        if (k==i) continue;
        if (count_diff_s[k] != count_diff_t[k]) {
          ignoreCharsToWork[i].insert(k);
        }
        count_diff_s[k] = 0;
        count_diff_t[k] = 0;
      }

      if (s_idx < str_size && s[s_idx]-'a' == i) num_s++;
      if (t_idx < str_size && t[t_idx]-'a' == i) num_t++;
      
      s_idx++;
      t_idx++;
    
    }

    if (num_s != num_t) {
      ignoreCharsToWork[i].insert(i);
    }
  }
  
  int Q;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    string input_str;
    cin >> input_str;
    for (int j=0; j<input_str.size(); j++) {
      for (int k=0; k<input_str.size(); k++) {
        if (ignoreCharsToWork[input_str[j]-'a'].find(input_str[k]-'a') != ignoreCharsToWork[input_str[j]-'a'].end()) {
          cout << "N";
          goto next_asdf;
        }
      }
    }
    cout << "Y";
    next_asdf: {

    }
  }
  cout << endl;
}