class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int> pq;

        for (auto& e : piles) {
            sum += e;
            pq.push(e);
        }

        for (int i = 0; i < k; i++) {
            if (!pq.empty()) {
                int temp = pq.top();
                pq.pop();
                sum -= temp/2;
                pq.push(temp - (temp/2));
            }
        }

        return sum;
    }
};
