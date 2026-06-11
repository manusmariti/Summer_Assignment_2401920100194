QUES REVERSE WORDS IN A STRING III
class Solution {
public:
    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        int left = 0;
        int right = 0;
        int n = s.size();
        while (right <= n) {
            if (right == n || s[right] == ' ') {
                reverse(s, left, right - 1);
                left = right + 1;
            }
            right++;
        }
        return s;
    }
};
QUES DECODE STRING
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string curr = "";
        int num = 0;
        for (char ch:s) {
            if (isdigit(ch)){
                num =num*10+(ch-'0');
            }
            else if (ch =='[') {
                countStack.push(num);
                stringStack.push(curr);
                num =0;
                curr="";
            }
            else if (ch ==']') {
                int repeat=countStack.top();
                countStack.pop();
                string temp=stringStack.top();
                stringStack.pop();
                while (repeat--) {
                    temp +=curr;
                }
                curr=temp;
            }
            else {
                curr+=ch;
            }
        }
        return curr;
    }
};
QUES GENERATE PARANTHETHIS
class Solution {
public:
    vector<string> ans;
    void solve(string curr, int open, int close, int n) {
        if (curr.length()==2 * n) {
            ans.push_back(curr);
            return;
        }
        if (open<n) {
            solve(curr+"(",open+1,close,n);
        }
        if (close<open) {
            solve(curr+")",open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        solve("",0,0,n);
        return ans;
    }
};
