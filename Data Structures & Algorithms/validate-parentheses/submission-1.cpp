class Solution {
public:
    bool isValid(string s) {
        while(true) {
            int pos = -1;
            if((pos = s.find("()")) != -1) {
                s.erase(pos, 2);
            } else if((pos = s.find("[]")) != -1) {
                s.erase(pos, 2);
            }  else if((pos = s.find("{}")) != -1) {
                s.erase(pos, 2);
            } else {
                break;
            }
        }
        return s.empty();
    }
};
