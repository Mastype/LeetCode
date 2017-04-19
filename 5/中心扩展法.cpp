#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 1)
			return "";
		char arr[2000];
		for (int i = 0; i < s.size(); i++) {
			arr[2*i] = s[i];
			arr[2*i + 1] = ' ';
		}
		int max = 1;
		string res = s.substr(0, 1);
		for (int i = 1; i < 2 * (s.size() - 1); i++) {
			int pre = i - 1;
			int next = i + 1;
			string temp_s = "";
			int temp_v;
			if (arr[i] == ' ')
				temp_v = 0;
			else {
				temp_s += arr[i];
				temp_v = 1;
			}
			while (pre >= 0 && next < (2 * s.size() - 1) && arr[pre] == arr[next]) {
				if (arr[pre] == ' '){
					pre--;
					next++;
					continue;
				}
				temp_s = arr[pre] + temp_s + arr[next];
				temp_v += 2;
				pre--;
				next++;
			}
			if (temp_v > max) {
				res = temp_s;
				max = temp_v;
			}

		}

		return res;
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
