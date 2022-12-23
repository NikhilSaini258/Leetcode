int Solution::maxProfit(const vector<int> &A) {
    int maxProfit = 0;
    int minPrice = INT_MAX;
  
    for (int i = 0; i < A.size(); i++) {
        minPrice = std::min(minPrice, A[i]);
        maxProfit = std::max(maxProfit, A[i] - minPrice);
    }
  
    return maxProfit;
}
