class TimeMap {
    unordered_map<string,vector<pair<string,int>>> storeTime;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        storeTime[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> store = storeTime[key];
        int l = 0, r= store.size() - 1;
        string ans = "";
        while(l <= r) {
            int mid = l + (r - l) / 2;
            auto [value, time] = store[mid];
            if (time <= timestamp) {
                ans = value;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
