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
        std::vector<int> temp = {};

        for (int i = 0; i < accounts.size(); ++i) {
            int summ = 0;
            for (int j = 0; j < accounts[i].size(); ++j) {
                summ += accounts[i][j];
            }
            temp.push_back(summ);
        }

        std::sort(temp.begin(), temp.end(), std::greater<int>());

        for (int i = 0; i < temp.size(); ++i) {
            std::cout << temp[i] << ' ' << std::endl;
        }
        return temp[0];
    }
};
