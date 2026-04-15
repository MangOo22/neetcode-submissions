class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        map<int,double> fleet;
        for (int i = 0; i < n; i++) {
            fleet[-position[i]] = double (target - position[i]) / speed[i];
        }

        int fleet_count = 0;
        double fleet_time = 0;
        for (auto &[_, cur_time] : fleet) {
            if (cur_time <= fleet_time) continue;
            ++fleet_count, fleet_time = cur_time;
        }
        return fleet_count;
    }
};
