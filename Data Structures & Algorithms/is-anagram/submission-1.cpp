class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26]={0};
        int n=s.size();
        int m=t.size();
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            hash[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(hash[i]!=0){
                return false;
            }
        }
        return true;
    }
};
