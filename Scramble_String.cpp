class Solution {
public:
    bool shouldMatch(string s1,string s2)
    {
        int arr1[26]={0};
        int arr2[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr1[i]-arr2[i]!=0)
                return false;
        }
        return true;
    }
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
        if(!shouldMatch(s1,s2))
            return false;
        bool b=false;
        for(int i=1;i<s1.length();i++)
        {
            b=b||(isScramble(s1.substr(0,i),s2.substr(0,i))&&(isScramble(s1.substr(i),s2.substr(i)))||(isScramble(s1.substr(0,i),s2.substr(s1.length()-i))&&(isScramble(s1.substr(i),s2.substr(0,s1.length()-i)))));
        }
        return b;
    }
};
