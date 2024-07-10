class Solution {
public:
    
    vector<int> toposort(int N,vector<int> adj[]){
        vector<int> indegree(N,0);
        for(int i=0; i<N; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<N ;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            auto to=q.front(); q.pop(); topo.push_back(to);
            for(auto it: adj[to]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> topo = toposort(numCourses,adj);
        // for(auto it: topo){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        if(topo.size()==numCourses) {
            return true;
        }
        else{
            return false;
        }
    }
};