class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string s1;
        if(x>y){
             s1="ab";
                
        }
        else{
            s1="ba";
            swap(x,y);
        }
        
        stack<char>st;
        int ans=0;
        for(auto c: s){
            if(!st.empty() && c==s1[1] && st.top()==s1[0]){
                ans+=x;
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        vector<char> res;
        while(!st.empty()){
            auto x=st.top();
            res.push_back(x);
            st.pop();
        }
        reverse(res.begin(),res.end());
        // for(auto c: res){
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        stack<char> st2;
        for(auto c: res){
            //s1=ba ab
            if(!st2.empty() && c==s1[0] && st2.top()==s1[1]){
                ans+=y;
                st2.pop();
            }
            else{
                st2.push(c);
            }
        }
        
        
        return ans;
    }
};