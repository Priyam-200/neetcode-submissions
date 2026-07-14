class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        unordered_map<char,vector<pair<int,int>>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mp.find(board[i][j])!=mp.end()){
                    vector<pair<int,int>>ans=mp[board[i][j]];
                    for(int k=0;k<ans.size();k++){
                        int x=ans[k].first;
                        int y=ans[k].second;
                        if(x==i || y==j){
                            return false;
                        }
                        else if(x/3==i/3 && y/3==j/3){
                            return false;
                        }
                    }
                }
                if(board[i][j]!='.'){
                    mp[board[i][j]].push_back({i,j});
                }
            }
        }
        return true;
    }
};
