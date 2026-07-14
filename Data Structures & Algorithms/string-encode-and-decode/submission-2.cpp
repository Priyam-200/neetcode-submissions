class Solution {
public:
    vector<string>ans;
    string encode(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        for(int i=0;i<n;i++){
            int m=strs[i].size();
            string s=to_string(m);
            ans+=(s+"#"+strs[i]);
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int n=s.size();
        int j=0;
        while(j<n){
            string s1="";
            while(s[j]!='#'){
                s1+=s[j];
                j++;
            }
            int t=stoi(s1);
            if(t==0){
                ans.push_back("");
                j+=1;
            }
            else{
                j+=1;
                string o="";
                while(t && j<n){
                    o+=s[j];
                    j++;
                    t--;
                }
                ans.push_back(o);
            }
        }
        return ans;
    }
};
