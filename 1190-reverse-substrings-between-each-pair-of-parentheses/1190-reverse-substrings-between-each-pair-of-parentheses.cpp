class Solution {
public:
    string reverseParentheses(string s) {
         stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                string rev="";
                while(st.top()!='(' && !st.empty()){
                    rev+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(int i=0; i<rev.size(); i++){
                    st.push(rev[i]);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};