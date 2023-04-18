class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int i = 0;
        int j = 0;
        while (i < word1.size() && j < word2.size()) {
            s.push_back(word1[i++]);
            s.push_back(word2[j++]);
        }

        while (i < word1.size()) s.push_back(word1[i++]);
        while (j < word2.size()) s.push_back(word2[j++]);

        return s;
    }
};

// Using single index variable
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";

        for (int i = 0; i < word1.size() || i < word2.size(); i++) {
            if (i < word1.size()) s.push_back(word1[i]);
            if (i < word2.size()) s.push_back(word2[i]);
        }

        return s;
    }
};
