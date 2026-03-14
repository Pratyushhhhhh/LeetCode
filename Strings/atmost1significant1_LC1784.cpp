class Solution {
public:
    bool checkOnesSegment(string s) {
        int flag=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0') flag=-1;
            if(flag == 1 && s[i]=='1') continue;
            if(flag == -1 && s[i]=='0') continue;
            if(flag == -1 && s[i]=='1') return false;
        }
        return true;
    }
};