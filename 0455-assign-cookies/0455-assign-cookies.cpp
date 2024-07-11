class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0, j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                j++; i++;
                ans++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};