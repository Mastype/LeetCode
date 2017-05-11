#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
//使用2维数据存储的DP解法。空间超
class Solution {
public:
	int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2)
        return 0;
		vector< vector<int> > arr(size, vector<int>(size, 0));
		for (int i = 0; i < size; i++)
			arr[i][i] = prices[i];

		for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)  {
			arr[i][j] = (arr[i][j - 1] < prices[j]) ? arr[i][j - 1] : prices[j];
			int r = size - 1 - i;
			int c = size - 1 - j;
			if (r == c + 1)
				arr[r][c] = (prices[j] - arr[i][j] > 0) ? prices[j] - arr[i][j] : 0;
			else
				arr[r][c] = (arr[r][c + 1] > prices[j] - arr[i][j]) ? arr[r][c + 1] : prices[j] - arr[i][j];
		}
		int res = (arr[size-1][0] > 0) ? arr[size-1][0] : 0;
		for (int i = 1; i < size-1; i++){
			int profit = arr[i][0] + arr[size - 1][i];
			res = res > profit ? res : profit;
		}
		return res;
    }
};
int main()
{
    int a[] = { 1,2,3,4,5 };
	vector<int> arr(a, a+5);
	cout << Solution().maxProfit(arr) << endl;
}
