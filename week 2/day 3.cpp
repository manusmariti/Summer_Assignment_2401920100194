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

QUES PERMUTATION IN STRING
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (int i = 0; i < n; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        if (freq1 == freq2) return true;
        for (int i = n; i < m; i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - n] - 'a']--;
            if (freq1 == freq2) return true;
        }
        return false;
    }
};
QUES FIND ALL ANAGRAM IN A STRING 
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        int m = p.size();
        if (m > n) return ans;
        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);
        for (int i = 0; i < m; i++) {
            freqP[p[i] - 'a']++;
            freqS[s[i] - 'a']++;
        }
        if (freqP == freqS) {
            ans.push_back(0);
        }
        for (int i = m; i < n; i++) {
            freqS[s[i] - 'a']++;
            freqS[s[i - m] - 'a']--;
            if (freqP == freqS) {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};
