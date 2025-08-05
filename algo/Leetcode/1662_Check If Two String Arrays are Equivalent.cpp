// 1662. Check If Two String Arrays are Equivalent

/*
*  Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
*/

#include <vector>
#include <string>
using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = 0, n = 0;   // for word2

        for (int i = 0; i < word1.size(); ++i) {

            for (int j = 0; j < word1[i].size(); ++j) {

                // Check if we have exhausted word2
                if (m >= word2.size() || n >= word2[m].size()) {
                    return false;
                }

                // Compare characters from word1 and word2
                if ((word1[i][j] != word2[m][n])) {
                    return false;
                }

                // Move to the next character in word2
                n++;
                if (n == word2[m].size()) {
                    m++;
                    n = 0;
                }
            }
        }
        // Check if we have exhausted both words
        if (m < word2.size() || n != 0) {
            return false;
        }

        return true;
    }
};
