class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> fleets;
        vector<pair<int,int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        for (int i =0; i < position.size(); i++)
        {
            double time = (double)(target - pair[i].first)/pair[i].second;
            if ((fleets.empty()) || time > fleets.top())
                fleets.push(time);
        }
        return fleets.size();
    }
};
