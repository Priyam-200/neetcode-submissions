class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxf=0;
        unordered_map<char,int>mp;
        int left=0;
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            maxf=max(maxf,mp[s[i]]);
            while((i-left+1)-maxf>k){
                mp[s[left]]--;
                left++;
            }
            maxi=max(maxi,i-left+1);
        }
        return maxi;
    }
};