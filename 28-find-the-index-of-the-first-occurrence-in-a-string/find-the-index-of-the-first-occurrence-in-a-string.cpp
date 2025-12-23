class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1 = haystack.length(), length2 = needle.length();
        for (int i = 0; i <= length1 - length2; i++) {
            if (haystack.substr(i, length2) == needle) {
                return i;
            }
        }
        return -1;
    }
};