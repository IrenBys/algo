// 1672. Richest Customer Wealth

#include <vector>
#include <algorithm>
#include <iostream>

/*
* You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
* Return the wealth that the richest customer has.
* A customer's wealth is the amount of money they have in all their bank accounts. 
* The richest customer is the customer that has the maximum wealth.
*/

class Solution {
public:
    int maximumWealth(std::vector < std::vector<int >>& accounts) {
        int result = 0;

        for (int i = 0; i < accounts.size(); ++i) {
            int summ = 0;
            int prev_summ = 0;
            for (int j = 0; j < accounts[i].size(); ++j) {
                summ += accounts[i][j];
            }
            result = std::max(summ, result);
        }
        return result;
    }
};

