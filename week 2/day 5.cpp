QUES GROUP ANAGRAMS
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        )
        return ans;
    }
};
QUES STRING CPMPRESSION
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int i = 0;
        while (i < n) {
            char current = chars[i];
            int count = 0;
            while (i < n && chars[i] == current) {
                count++;
                i++;
            }
            chars[write++] = current;
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};
QUES LONGEST PALINDROME SUBSTRING
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "^";
        for (char c : s) {
            t += "#" + string(1, c);
        }
        t += "#$";
        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;
        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            if (i < right)
                p[i] = min(right - i, p[mirror]);
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
                p[i]++;
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};
