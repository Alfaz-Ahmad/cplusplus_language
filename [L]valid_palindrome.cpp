class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        int i, l = s.size();
        char ch;
        for(i=0;i<l;i++){
            if(iswalnum(s[i])){
                ch = tolower(s[i]);
                s1 += ch;
            }
        }
        l = s1.size();
        for(i=0;i<l/2;i++){
            if(s1[i]!=s1[l-i-1]){
                return false;
            }
        }
        return true;
    }
};