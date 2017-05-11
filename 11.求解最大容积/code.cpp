#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int size = height.size();
		int res = 0;
		int i = 0, j = size - 1;
		while (i < j)  {
			int h = (height[i] < height[j]) ? height[i] : height[j];
			int v = (j - i) * h;
			res = (res > v) ? res : v;
			int left = height[i], right = height[j];

			while (i<j && height[i] <= h) i++;
			while (i<j && height[j] <= h) j--;
		}
		return res;

	}
};
int main()
{
    int a[] = { 1,2,4,3 };
	vector<int> v(a, a+4);
	cout << Solution().maxArea(v);
}
