class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<int> arr[10];
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'0'].push_back(i);
        }
        int ct=s.length()-1;
        for(int i=t.length()-1;i>=0;i--)
        {
            while(s[ct]=='-'&&ct>=0)
                ct--;
            if(ct<0)
                return false;
            if(s[ct]<t[i])
            {
                if(arr[t[i]-'0'].size()!=0)
                {
                    for(int j=t[i]-'0'+1;j<=9;j++)
                    {
                        if(arr[j].size()!=0&&arr[j][arr[j].size()-1]>arr[t[i]-'0'][arr[t[i]-'0'].size()-1])
                            return false;
                    }
                    s[arr[t[i]-'0'][arr[t[i]-'0'].size()-1]]='-';
                    arr[t[i]-'0'].pop_back();
                }
                else
                    return false;
                
            }
            else if(s[ct]>t[i])
            {
                return false;
            }
            else
            {
                arr[t[i]-'0'].pop_back();
                ct--;
            }
            //cout<<s<<" ";
        }
        return true;
    }
};
