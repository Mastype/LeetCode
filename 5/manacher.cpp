#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		char arr[2001];
		for (int i = 0; i < s.size(); i++) {
			arr[2 * i] = '#';
			arr[2 * i + 1] = s[i];
		}
		arr[2 * s.size()] = '#';
		int len = 2 * s.size() + 1;
		vector<int> rl(len, 0);
		int max = 0, m_right = 0, pos = 0, m_pos = 0;
		for (int i = 0; i < 2 * (s.size() - 1); i++) {
			if (i<m_right)
				rl[i] = (rl[pos * 2 - i]> m_right - i)? rl[pos*2-i]:(m_right-i);
			else
				rl[i] = 0;
			while ((i - rl[i] - 1) >= 0 && (i + rl[i] + 1)<len && arr[i - rl[i] - 1] == arr[i + rl[i] + 1])
				rl[i] ++;
			if (i + rl[i] > m_right) {
				pos = i;
				m_right = i + rl[i];
			}
			if (rl[i] > max) {
				max = rl[i];
				m_pos = i;
			}
		}
		return s.substr((m_pos - max) / 2, max);
	}
};
int main()
{
	string s = "abcba";
//	cout << lengthOfLongestSubstring(s) << endl;
	Solution *sol = new Solution();
	cout << sol->longestPalindrome(s) << endl;
	return 0;
}
