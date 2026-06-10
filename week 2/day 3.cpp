QUES FIND THE INDEX OF THE FIRST OCCURENCE IN A STRING 
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};

QUES IS SUBSEQUENCE
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t) {
            if (i < s.size() && s[i] == c) {
                i++;
            }
        }
        return i == s.size();
    }
};
QUES REPEATED STRING PATTERN
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = s + s;
        temp = temp.substr(1, temp.size() - 2);
        return temp.find(s) != string::npos;
    }
};
        
