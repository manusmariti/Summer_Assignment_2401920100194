QUES VALID ANAGRAM
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        vector<int> bucket(26, 0);
        for (int i = 0; i < s.length(); i++) {
            bucket[s[i] - 'a']++;
            bucket[t[i] - 'a']--;
        }
        for (int x : bucket) {
            if (x != 0)
                return false;
        }
        return true;
    }
};
QUES FIRST UNIQUE CHARACTER IN A STRING
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
QUES RANSOM NOTE
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        for (char ch : magazine) {
            freq[ch - 'a']++;
        }

        for (char ch : ransomNote) {
            if (freq[ch - 'a'] == 0) {
                return false;
            }
            freq[ch - 'a']--;
        }

        return true;
    }
};
