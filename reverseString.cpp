#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;
        size_t wordStart = 0;
        size_t len = s.length();
        size_t i = 0;
        while (i < len) {
            size_t j = i;
            while (s[j] == ' ' && j < len) {
                ++j;
            }
            
            if (j >= len) {
                break;
            }
            
            wordStart = j;
            while (s[j] != ' ' && j < len) {
                ++j; 
            }
            
            // split word
            string word = s.substr(wordStart, j - wordStart);
            words.insert(words.begin(), word);
            cout << word << "[" << wordStart << "," << j << "]" << endl;
            i = j;
        }
        
        if (words.size()) {
            s.clear();
            
            for (i = 0; i < words.size(); ++i) {
                s += words[i];
                if (i < words.size() - 1) {
                    s += " ";
                }
            }
        }
    }
};

int main() {
	Solution sln;
	string s = "the sky is blue";
	sln.reverseWords(s);

	cout << s << endl;
	return 0;
}