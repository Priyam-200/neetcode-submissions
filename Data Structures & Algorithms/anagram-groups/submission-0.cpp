class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ans;
        int m=strs.size();
        for(int i=0;i<m;i++){
            string s=strs[i];
            int hash[26]={0};
            int n=s.size();
            for(int j=0;j<n;j++){
                hash[s[j]-'a']++;
            }
            string key(hash,hash+26);
            mp[key].push_back(s);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
