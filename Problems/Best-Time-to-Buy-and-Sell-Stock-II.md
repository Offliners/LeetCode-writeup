# Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

#### Example 1
```
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
```

#### Example 2
```
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying
```

### Python 3
```python
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum([max(prices[i] - prices[i - 1], 0) for i in range(1, len(prices))])
```
[code](Python%203/122.py)

#### Result
```
Runtime: 68 ms, faster than 16.64% of Python3 online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 15.1 MB, less than 7.32% of Python3 online submissions for Best Time to Buy and Sell Stock II
```

### C
```C
int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    
    for(int i = 0; i + 1 < pricesSize; i++)
        if(prices[i] < prices[i+1])
            profit += prices[i+1] - prices[i];
    
    return profit;
}
```
[code](C/122.c)

#### Result
```
Runtime: 12 ms, faster than 28.81% of C online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 6.7 MB, less than 100.00% of C online submissions for Best Time to Buy and Sell Stock II.
```
