class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIndex = 0;
        int totalGas = 0;
        int totalCost = 0;
        int currGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                startIndex = i+1;
                currGas = 0;
            }
        }
        if (totalCost <= totalGas) return startIndex;
        return -1;
    }
};
