class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();

        unordered_map<char,int>mp1;
        for(int i=0;i<m;i++){
            mp1[t[i]]++;
        }
        int count=0;
        unordered_map<char,int>mp2;
        int left=0;
        int ans=INT_MAX;
        string s1="";
        for(int j=0;j<n;j++){
            mp2[s[j]]++;
            if(mp2[s[j]]<=mp1[s[j]]){
                count++;
            }
            if(count==t.size()){
                while(mp2[s[left]]>mp1[s[left]]){
                    mp2[s[left]]--;
                    left++;
                }
                if(ans>j-left+1){
                    ans=min(ans,j-left+1);
                    s1=s.substr(left,j-left+1);
                }
            }
        }
        return s1;

    }
};
