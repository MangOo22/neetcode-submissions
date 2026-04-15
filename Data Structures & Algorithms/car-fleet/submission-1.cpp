class Solution {
public:
   int carFleet(int target, vector<int>& position, vector<int>& speed) {
  int n = position.size();
  vector<pair<int, int>> fleet(n);
  for (int i = 0; i < n; i++) {
    fleet[i] = { position[i], speed[i] };
  }
  sort(fleet.begin(), fleet.end(), [&](pair<int, int>& a, pair<int, int>& b) {
    return a.first > b.first;
  });

  vector<double> time_at_end(n);
  int fleet_count = 0;
  for (int i = 0; i < n; i++) {
    time_at_end[i] = 1.0*(target - fleet[i].first) / fleet[i].second;
    if (time_at_end[i] <= time_at_end[i - 1]) {
      // it means those cars are at the same fleet
      time_at_end[i] = time_at_end[i - 1];
    }
    else fleet_count++;
  }
  return fleet_count;
}
};
