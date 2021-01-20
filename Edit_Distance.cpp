class Solution {
public:
    unordered_map<string,int> mp;
    int minDistance(string word1, string word2) {
        if(mp.find(word1+"|"+word2)!=mp.end())
            return mp[word1+"|"+word2];
        if(word2.length()==0)
            return word1.length();
        if(word1.length()==0)
            return word2.length();
        int s1=INT_MAX,s2=INT_MAX,s3=INT_MAX,s4=INT_MAX;
        if(word1[0]==word2[0])
        s1=minDistance(word1.substr(1),word2.substr(1));
        else
        {
            s2=minDistance(word1.substr(1),word2.substr(1))+1;
            s3=minDistance(word1,word2.substr(1))+1;
            s4=minDistance(word1.substr(1),word2)+1;
            
        }
        int s=min(s1,min(s2,min(s3,s4)));
        mp[word1+"|"+word2]=s;
        return s;
    }
};
