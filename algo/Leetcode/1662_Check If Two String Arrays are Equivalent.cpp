// 1662. Check If Two String Arrays are Equivalent

/*
*  Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp1;
        string temp2;

        for (int i = 0; i < word1.size(); ++i) {
            temp1 += word1[i];
        }

        for (int i = 0; i < word2.size(); ++i) {
            temp2 += word2[i];
        }

        if (temp1 == temp2) return true;

        return false;
    }
};
