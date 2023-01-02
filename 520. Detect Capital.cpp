class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allUpper = true;
        bool allLower = true;
        if (word.size() <= 1) return true;

        for (int i = 1; i < word.size(); i++) {
            if (islower(word[i]))
                allUpper = false;
            if (isupper(word[i]))
                allLower = false;
        }

        return allLower || (allUpper && isupper(word[0]));
    }
};

/* Start checking form 2nd character. 
   If all lower from 2nd char onwards, then no need to check first char ('Google' or 'leetcode', both are correct).
   If all upper from 2nd char onwards, need to verify whether first is capital or not ('USA' is valid, but 'rUSSIA' is not valid.
  USA
  rUSSIA
  leetcode
  Google
*/
