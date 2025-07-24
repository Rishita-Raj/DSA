class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        vector<int> vowels(s.size(),0), consonants(s.size(), 0);
        string str = "aeiou";
        int v = 0, c = 0;
        for(int i=0;i<s.size();i++){
            if(str.find(s[i]) != string::npos){
                v++;
                vowels[i] = v;
                consonants[i] = c;
            }
            else{
                c++;
                vowels[i] = v;
                consonants[i] = c;
            }
        }
        int ans = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                int vc = vowels[j] - (i == 0?0:vowels[i-1]);
                int cc = consonants[j] - (i == 0?0:consonants[i-1]);
                if(vc == cc and (vc*cc)%k == 0) ans++;
            }
        }
        return ans;
        
    }
};