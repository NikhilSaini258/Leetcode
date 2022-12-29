class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) tasks[i].push_back(i);
        std::sort(tasks.begin(), tasks.end());

        vector<int> ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int i = 0;
        int currentTime = 0;

        while (ans.size() < tasks.size()) {
            if (i < tasks.size() && pq.empty()) {
                currentTime = max(currentTime, tasks[i][0]);
            }
            while (i < tasks.size() && tasks[i][0] <= currentTime) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            auto temp = pq.top();
            pq.pop();
            currentTime = min(1000000000, currentTime+temp[0]);
            ans.push_back(temp[1]);
        }

        return ans;
    }
};
