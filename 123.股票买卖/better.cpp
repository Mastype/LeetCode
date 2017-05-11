#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
//使用2维数据存储的DP解法。空间超
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
        return 0;
	    int stats[2][4] = {-prices[0], 0, INT_MIN, 0};
	    for(int i = 1; i < len; i++) {
	        stats[i%2][0] = max(stats[(i-1)%2][0], -prices[i]);
	        stats[i%2][1] = max(stats[(i-1)%2][1], stats[(i-1)%2][0] + prices[i]);
	        stats[i%2][2] = max(stats[(i-1)%2][2], stats[(i-1)%2][1] - prices[i]);
	        stats[i%2][3] = max(stats[(i-1)%2][3], stats[(i-1)%2][2] + prices[i]);
	    }
	    return max(stats[(len-1)%2][1], stats[(len-1)%2][3]);
    }
};
int main()
{
    int a[] = {1,2,3,4,5};
	vector<int> arr(a, a+5);
	cout << Solution().maxProfit(arr) << endl;
}
