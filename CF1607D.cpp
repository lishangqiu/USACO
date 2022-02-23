#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;
int t = 0;

bool checkCorrect(vector<int> joint_sequence, int n){
	sort(joint_sequence.begin(), joint_sequence.end());
	for (int j=1;j<=joint_sequence.size();j++){
		if (joint_sequence[j-1] != j){
			return false;
		}
	}
	return true;
}

bool checkBlueRed(vector<int> blue, vector<int> red, int n){
	vector<int> combined = blue;
	combined.insert(combined.end(), red.begin(), red.end());
	return checkCorrect(combined, n);
}

int main(){
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;

		vector<int> ints;
		for (int j = 0; j < n; j++) {
			int a; std::cin >> a; ints.push_back(a);
		}

		vector<char> symbs;
		for (int j = 0; j < n; j++) {
			char a; std::cin >> a; symbs.push_back(a);
		}

		vector<int> reds;
		vector<int> blues;
		for (int k = 0; k < n; k++){
			if (symbs[k] == 'B'){
				blues.push_back(ints[k]);
			}
			else{
				reds.push_back(ints[k]);
			}
		}

		if (checkBlueRed(blues, reds, n)){
			cout << "yes";
			int a; cin >> a;
			return 0;
		}

		sort(reds.begin(), reds.end());
		sort(blues.begin(), blues.end());

		// blue has 1
		if (blues.size() > 0){
			if (blues[0] >= 1){
				vector<int> temp_blue = blues;
				for (auto &p : temp_blue){
					p -= (blues[0]-1);
				}
				// find smallest red needed
				int smallestRed = temp_blue.size()+1;
				for (int j=1;j<=temp_blue.size();j++){
					if (temp_blue[j-1] != j){
						smallestRed = j;
					}
				}

				if (reds.size() > 0){
					vector<int> temp_red;
					if (reds[0] <= smallestRed){
						temp_red = reds;
						for (auto &p : temp_red){
							p += (smallestRed-reds[0]);
						}

						if (checkBlueRed(temp_blue, temp_red, n)){
							cout << "yes";
							int a; cin >> a;
							return 0;
						}
					}
				}
				else{
					if (smallestRed == temp_blue.size()+1){
							cout << "yes";
							int a; cin >> a;
							return 0;
					}
				}
			}
		}

		if (reds.size() > 0){
			if (reds[0] <= 1){
				vector<int> temp_red = reds;
				for (auto &p : temp_red){
					p += (1 - reds[0]);
				}
				// find smallest red needed
				int smallestBlue = temp_red.size()+1;
				for (int j=1;j<=temp_red.size();j++){
					if (temp_red[j-1] != j){
						smallestBlue = j;
					}
				}

				if (blues.size() > 0){
					vector<int> temp_blue;
					if (blues[0] >= smallestBlue){
						temp_blue = blues;
						for (auto &p : temp_blue){
							p -= (blues[0]-smallestBlue);
						}

						if (checkBlueRed(temp_blue, temp_red, n)){
							cout << "yes";
							int a; cin >> a;
							return 0;
						}
					}
				}
				else{
					if (smallestBlue == temp_red.size()+1){
							cout << "yes";
							int a; cin >> a;
							return 0;
					}
				}
			}
		}
		

		//blue_cont:
	}
	return 0;
}
