// https://oj.leetcode.com/problems/count-and-say/
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        int index = 1;
        string sequence = "1";

        while (index < n) {   
            char countingChar = sequence[0];
            int ocurrence = 1;
            string nextSequence;
            
            for (size_t i = 1; i < sequence.size(); ++i) {
                char c = sequence[i];
                if (c != countingChar) {                    
                    // say the char
                    nextSequence += to_string(ocurrence);
                    nextSequence += countingChar;

                    countingChar = c;
                    ocurrence = 1;
                } else {
                    ++ocurrence;
                    continue;
                }
            }

            nextSequence += to_string(ocurrence);
            nextSequence += countingChar;

            sequence = nextSequence;
            ++index;

            //cout << index << "=" << sequence << endl;
        }

        return sequence;
    }
};

int main() {
	Solution sln;

    int n;
    cin >> n; 
    cout << sln.countAndSay(n) << endl;
	return 0;
}