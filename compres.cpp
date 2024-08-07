class Solution {
public:
    int compress(vector<char>& chars) {
        std::string s;
        int size = chars.size();
        int j;
        //if group len = 1 append char to s
        //if group len = 10 append len to single char and continue
        //else append len to single char
        for (int i = 0; i < size; i++) {
            j = 0;
            while (chars[i] + 1 == chars[i]) {
                j++;
            }
            s[i] = chars[i];
            if (j >= 10) {
                s[i + 1] = (j + 1) / 10;
                s[i + 2] = (j + 1) % 10;
                i = i + j;
            }
            else {
                s[i + 1] = j + 1;
                i = i + j;
            }
        }
};