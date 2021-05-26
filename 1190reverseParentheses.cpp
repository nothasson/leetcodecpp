class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res = "";
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                reverse(s,st.top() + 1,i - 1);
                st.pop();
            }
        }
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != '(' && s[i] != ')' ){
                res += s[i];
            }
        }
        return res;
    }
private:
    void reverse(string &s, int start, int end){
        char temp = ' ';
        while(start < end){
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};