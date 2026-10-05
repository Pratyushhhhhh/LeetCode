class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n = min(word1.size(), word2.size());

        for (int i = 0; i < n; i++) {//RUN TILL MINIMUM
            ans += word1[i];
            ans += word2[i];
        }

        ans += word1.substr(n);//ADD REMAINING SUBSTRINGS
        ans += word2.substr(n);

        return ans;
    }
};
// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         int n=word1.length();
//         int m=word2.length();
//         int i=0,j=0;
//         string temp;
//         while(i!=n || j!=m){
//             if(i<n){
//                 temp.push_back(word1[i]);
//                 i++;
//             }
//             if(j<m){
//                 temp.push_back(word2[j]);
//                 j++;
//             }
//         }
//         return temp;
//     }
// };