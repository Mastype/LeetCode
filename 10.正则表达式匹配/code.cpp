#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int size_s = s.size();
		int size_p = p.size();
		vector<vector<bool>> arr(size_s + 1, vector<bool>(size_p + 1, false));

		arr[0][0] = true;
		for (int i = 1; i <= size_s; i++)
			arr[i][0] = false;
		for (int j = 2; j <= size_p; j++)
		if (p[j - 1] == '*')
			arr[0][j] = arr[0][j - 2];
		for (int i = 1; i <= size_s; i++)
		for (int j = 1; j <= size_p; j++) {
			if (p[j - 1] != '*'){
				if (s[i-1] == p[j-1] || p[j-1] == '.')
					arr[i][j] = arr[i - 1][j - 1];
			}
			else {
				if (s[i-1] == p[j - 2] || p[j - 2] == '.')
					arr[i][j] = (arr[i - 1][j] || arr[i][j-2]);
				else
					arr[i][j] = arr[i][j - 2];
			}
		}
		return arr[size_s][size_p];
	}
};
int main()
{
	vector<int> v({ 1,2,4,3 });
	cout << Solution().maxArea(v);
}
