#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result;
    void recursion(int l, int r, string s) {
        if(l == 0 && r == 0) {
            result.push_back(s);
            return;
        }
        if(l > 0)
            recursion(l-1, r+1, s+"(");
        if(r > 0)
            recursion(l, r-1, s+")");
        }
public:
	 vector<string> generateParenthesis(int n) {
        if(n < 1)
            return result;
        recursion(n,0,"");
        return result;
    }
};
int main()
{
    int n;
    while(cin >> n) {
        vector <string> result = Solution().generateParenthesis(n);
        for(vector<string>::iterator iter = result.begin(); iter != result.end(); iter ++) {
            cout << *iter << endl;
        }
    }
}
