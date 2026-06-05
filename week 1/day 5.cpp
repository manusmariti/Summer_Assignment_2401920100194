QUES VALID PALINDROME
class Solution {
public:
char lowert(int ch){
    char temp;
    if(ch>='a' && ch<='z'){
       return ch;
    }
    else{
        temp= ch-'A'+'a';
        return temp;
    }
    return ch;
}
    bool isPalindrome(string s) {
        int n=s.size();
        int st=0;
        int e=n-1;
        while(st<e){
            if(!isalnum(s[st])){
                st++;
                continue;
            }
            if(!isalnum(s[e])){
                e--;
                continue;
            }

            if(lowert(s[st])!=lowert(s[e])){
                return 0;
            }
                st++;
                e--;
            
        }
        return 1;
    }
};
QUES REVERSE STRING
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int st=0;
        int e=n-1;
        while(st<e){
            swap(s[st++],s[e--]);
        }
    }
};
QUES LONGEST COMMON PREFIX
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        string result = "";

        for (int i = 0; i < min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) {
                break;
            }
            result += first[i];
        }

        return result;
    }
};

    
