class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        auto &it = mp[key];

        int low = 0;
        int high = it.size() - 1;
        string ans = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (it[mid].first <= timestamp) {
                ans = it[mid].second;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};