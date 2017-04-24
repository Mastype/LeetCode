#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if(numRows <= 1)
        return s;
        string res = "";
        for(int i = 0; i < size;) {
            res += s[i];
            i += 2 * (numRows - 1);
        }
        for(int r = 1; r < numRows-1; r++) {
            int odd = r;
            int even = 2 * (numRows - odd - 1) + r;
            while(odd < size || even < size) {
                if(odd < size) {
                    res += s[odd];
                    odd += 2 * (numRows - 1);
                }
                if(even < size) {
                    res += s[even];
                    even += 2 * (numRows - 1);
                }
            }
        }
        for (int i = numRows -1; i < size;) {
            res += s[i];
            i += 2 * (numRows - 1);
        }
        return res;
    }
};

int main() {
    Solution sol = new Solution();
    cout << sol.convert("ABCDEFG", 3) << endl;
    //Êä³ö AEBDFCG
}
