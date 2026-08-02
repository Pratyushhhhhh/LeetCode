class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256];
        for(int k = 0; k < 256; k++) freq[k] = -1;
        int c=0,ml=0;
        int n=s.size();
        int i=0,j=0;
        while(j<n){
           if(freq[s[j]]!=-1){
            if(freq[s[j]]>=i){
                i=freq[s[j]]+1;
            }
           }
           c=j-i+1;
           ml=max(ml,c);
           freq[s[j]]=j;
           j++;
        }
        return ml;
    }

};