#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool minus = x < 0;
        string s = to_string(abs(x));
        string sReverse;
        for (auto i = s.rbegin(); i != s.rend(); ++i) {
            sReverse.push_back(*i);
        }
        
        x = stoi(sReverse);
        if (minus) {
            x = -x;
        }
        
        return x;
    }
};

int main() {
	Solution sln;
	
    int x;
    cin >> x;
    cout << sln.reverse(x) << endl;
	return 0;
}