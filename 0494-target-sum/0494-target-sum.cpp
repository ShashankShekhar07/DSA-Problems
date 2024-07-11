class Solution {
public:
    
    int f(int ind,int sum,vector<int> &nums,vector<vector<int>> &dp){
        if(ind==0){
            if(nums[ind]==0 && sum==0){
                return 2;
            }
            else if(sum==0 || sum==nums[0]){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int nottake = f(ind-1,sum,nums,dp);
        int take = 0;
        if(nums[ind]<=sum){
            take = f(ind-1,sum-nums[ind],nums,dp);
        }
        
        return dp[ind][sum]=take+nottake;
    }    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        int diff  = (sum-target)/2;
        if((sum-target)%2!=0  || (sum-target)<0){
            return 0;
        }
        // vector<vector<int>> dp(n+1, vector<int> (sum+1,-1));
        // int ans = f(n-1,diff,nums,dp);
        // return ans;
        
        //Tabulation
        
//         vector<vector<int>> dp(n+2, vector<int> (diff+2,0));
//         if(nums[0]==0){
//             dp[0][0]=2;
//         }
//         else{
//             dp[0][0]=1;
//         }
        
//         if(nums[0]<=diff && nums[0]!=0){
//             dp[0][nums[0]]=1;
//         }
        
//         for(int i=1; i<n; i++){
//             for(int su=0; su<=diff; su++){
//                 int nottake =dp[i-1][su];
//         int take = 0;
//         if(nums[i]<=su){
//             take = dp[i-1][su-nums[i]];
//         }
        
//         dp[i][su]=take+nottake;
//             }
//         }

        
//         // for(int i=0; i<n; i++){
//         //     for(int tar=0; tar<=diff; tar++){
//         //         cout<<dp[i][tar]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         return dp[n-1][diff];
        
        //Space Optimization 
        vector<int> prev(diff+2,0),cur(diff+2,0);
        if(nums[0]==0){
            prev[0]=2;
        }
        else{
            prev[0]=1;
        }
        
        if(nums[0]<=diff && nums[0]!=0){
            prev[nums[0]]=1;
        }
        
        for(int i=1; i<n; i++){
            for(int su=0; su<=diff; su++){
                int nottake =prev[su];
        int take = 0;
        if(nums[i]<=su){
            take = prev[su-nums[i]];
        }
        
        cur[su]=take+nottake;
            }
            prev=cur;
        }
return prev[diff];
        
        // for(int i=0; i<n; i++){
        //     for(int tar=0; tar<=diff; tar++){
        //         cout<<dp[i][tar]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
};