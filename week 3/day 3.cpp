QUES VALID PARANTHESIS
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
            }
            else{
            if(st.size()==0) return false;
            if(st.top()=='('&& s[i]==')'||st.top()=='{'&& s[i]=='}'
            ||st.top()=='['&& s[i]==']'){
            st.pop();}
            else {
                return false;
        }
            }
        }
         return st.size()==0;
    }
    

};
QUES MIN STACK
class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(minSt.empty())
            minSt.push(val);
        else
            minSt.push(min(val, minSt.top()));
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
QUES NEXT GREATER ELEMENT 1
    class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }

        return ans;
    }
};
