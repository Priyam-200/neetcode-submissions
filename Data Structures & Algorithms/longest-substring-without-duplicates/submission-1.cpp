class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int left=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]>1){
                while(mp[s[i]]!=1){
                    mp[s[left]]--;
                    left++;
                }
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};
