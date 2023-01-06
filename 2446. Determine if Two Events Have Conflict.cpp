class Solution {
    const int START = 0;
    const int END = 1;
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        // event1.start <= event2.start <= event1.end
        // event2.start <= events1.start <= event2 <= end
        return (e1[START] <= e2[START] && e2[START] <= e1[END]) ||
                (e2[START] <= e1[START] && e1[START] <= e2[END]);
    }
};
