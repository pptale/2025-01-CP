class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0) return true;

        int i = 0; // iterator for s
        for (int j = 0; j<t.length(); j++) {
            if (s[i] == t[j]) {
                i++;
                if (i == s.length()) return true;
            }
        }
        return false; // String not found
    }
};
