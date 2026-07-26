
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();

        unordered_map<char, int> mp;

        for (int i = 0; i < m; i++) {
            mp[tasks[i]]++;
        }

        vector<pair<int, char>> ans;

        for (auto it : mp) {
            ans.push_back({it.second, it.first});
        }

        sort(ans.rbegin(), ans.rend());

        int maxFreq = ans[0].first;

        int countMax = 0;

        for (auto it : ans) {
            if (it.first == maxFreq) {
                countMax++;
            }
        }

        int length = (maxFreq - 1) * (n + 1) + countMax;
        return max(length, m);
    }
};
