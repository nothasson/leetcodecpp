class Solution {
public:
    int lengthOfLongestSubstring1(string s) {   
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr=0,left=0;
        for(int i = 0;i<s.size();++i){
            while(lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
    int lengthOfLongestSubstring2(string s) {
        if (s.size() == 0) return 0;
        int ans = 0;
        unordered_map<char, int> map;
        for (int start = 0, end = 0; end < s.size(); ++end) {
            if (map.find(s[end]) != map.end()) {
                start = max(map[s[end]], start);
            }
            ans = max(ans, end - start + 1);
            map[s[end]] = end + 1;
        }
        return ans;
    }
};