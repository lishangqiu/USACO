#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums(7);
    for (auto &a : nums){
        cin >> a;
    }
    
    vector<function<int(int, int, int)>> function_vector {[](int a, int b, int c){return a+b;}, [](int a, int b, int c){return b+c;}, [](int a, int b, int c){return a+c;}, [](int a, int b, int c){return a+b+c;}};
    
    for (int i=0; i<7-2; i++){
        for (int j=(i+1); j<7-1; j++){
            for (int k=(j+1); k<7; k++){
                bool found = true;
                vector<function<int(int, int, int)>> temp_functions(function_vector);
                
                for (int x=0; x<7; x++){
                    if (x == i || x == j || x == k){
                        continue;
                    }
                    
                    bool funcFound = true;
                    for (int y=0; y<temp_functions.size(); y++){
                        if (temp_functions[y](nums[i], nums[j], nums[k]) == nums[x]){
                            temp_functions.erase(temp_functions.begin() + y);
                            funcFound = true;
                            break;
                        }
                        else{
                            funcFound = false;
                        }
                    }
                    if (!funcFound){
                        found=false;
                        break;
                    }
                }
                
                if (found){
                    vector<int> temp{nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());

                    cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
                    return 0;
                }
            }
        }
    }
}