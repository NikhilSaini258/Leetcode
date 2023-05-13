// https://www.codingninjas.com/codestudio/problems/975286
#include <bits/stdc++.h> 

struct ItemPair {
    int weight;
    int value;
};

bool comp (ItemPair a, ItemPair b) {
    double x = (double)a.value / (double)a.weight;
    double y = (double)b.value / (double)b.weight;
    return x > y;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector <ItemPair> v (items.size());
    for (int i = 0; i < items.size(); i++) {
        v[i].weight = items[i].first;
        v[i].value = items[i].second;
    }

    std::sort (v.begin(), v.end(), comp);

    int currentWeight = 0;
    double maxValue = 0;

    for (auto& it: v) {
        if (currentWeight + it.weight <= w) {
            currentWeight += it.weight;
            maxValue += it.value;
        } else {
            int remainingWeight = w - currentWeight;
            maxValue += (double)remainingWeight * ((double)(it.value)/(double)(it.weight));
            break;
        }
    }
    return maxValue;
}
