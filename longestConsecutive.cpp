#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> ordered;
        for (auto n : num) {
            ordered.insert(n);
        }
        
        int lastNum = 0;
        bool first = true;
        size_t longestConsecutive = 0;
        size_t currentConsecutive = 0;
        for (auto n : ordered) {
            if (first) {
                lastNum = n;
                currentConsecutive = 1;
                first = false;
            } else {                                
                if (n - lastNum != 1) {
                    lastNum = n;                    
                    if (currentConsecutive > longestConsecutive) {
                        longestConsecutive = currentConsecutive;
                    }
                    
                    currentConsecutive = 1;
                } else {
                    lastNum = n;
                    ++currentConsecutive; 
                }  
            }
        }

        if (currentConsecutive > longestConsecutive) {
            longestConsecutive = currentConsecutive;
        }
        
        return longestConsecutive;
    }
};

int main() {
    Solution sln;
    vector<int> s = {100, 4, 200, 1, 3, 2,201,202,203,204,205};
    cout << sln.longestConsecutive(s) << endl;
    return 0;
}