class Solution {
public:
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        vector<int> v;
    unordered_map<int,int> mp1;
    vector<int> hash;
        void checkStartingIndex(int index,int len,queue<pair<int,int>> q)
        {
            
            if(mp1.size()==0)
            {
                mp1[q.front().second]=1;
                int ind=q.front().first;
                v.push_back(ind);
                q.pop();
                checkStartingIndex(index,len,q);
                return;
            }
            if(index>=hash.size())
                return;
            if(mp1.find(hash[index])!=mp1.end())
            {
                if(mp1[hash[index]]==1)
                    mp1.erase(hash[index]);
                else
                    mp1[hash[index]]--;
                q.push(make_pair(index,hash[index]));
                checkStartingIndex(index+len,len,q);
            }
            else
            {
                
                while(!q.empty())
                {
                    if(q.front().second==hash[index])
                    {
                        
                        q.pop();
                        break;
                    }
                    if(mp1.find(q.front().second)==mp1.end())
                        {
                            mp1[q.front().second]=1;
                        }
                        else
                            mp1[q.front().second]++;
                
                        
                    q.pop();
                }
                    if(mp.find(hash[index])==mp.end())
                    {
                        checkStartingIndex(index+len,len,q);
                    }
                    else
                    {
                q.push(make_pair(index,hash[index]));
                checkStartingIndex(index+len,len,q);
                    }
                return;
            }
        }
    vector<int> findSubstring(string s, vector<string>& words) {
            
        if(s.length()<words[0].length())
            return v;
        mp.clear();
       long long int x=7;
        long long int MODULO=pow(10,9)+7;
        for(int i=0;i<words.size();i++)
        {
            long long int sum=0;
            for(int j=0;j<words[i].length();j++)
            {
                sum=((sum*x)%MODULO+words[i][j])%MODULO;
            }
            if(mp.find(sum)==mp.end())
            mp[sum]=1;
            else
                mp[sum]+=1;
        }
        long long int sum=0;
        long long int num=1;
        for(int i=0;i<words[0].length();i++)
        {
            if(i>=1)
                num=(num*x)%MODULO;
                sum=((sum*x)%MODULO+s[i])%MODULO;
        }
        hash.push_back(sum);
        for(int i=1;i<s.length()-words[0].length()+1;i++)
        {
            sum=((sum-s[i-1]*num)*x+s[i+words[0].length()-1])%MODULO;
            hash.push_back(sum<0?sum+MODULO:sum);
        }
        for(int i=0;i<words[0].length();i++)
        {
        queue<pair<int,int>> q;
        mp1=mp;
            checkStartingIndex(i,words[0].length(),q);
               
        }
               return v;
    }
};
