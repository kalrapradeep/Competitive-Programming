class Solution {
public:
    bool checkAsciiContained(int arr1[],vector<int> arr)
    {
        for(int i=0;i<140;i++)
        {
            arr[i]=arr[i]-arr1[i];
            if(arr[i]<0)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int arr1[140]={0};
        for(int i=0;i<t.length();i++)
        {
            arr1[t[i]]++;
        }
        vector<int> arr;
        for(int i=0;i<140;i++)
        {
            arr.push_back(0);
        }
        queue<char> q;
        string res="";
        int start=0;
        int min=INT_MAX;
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]]++;
            q.push(s[i]);
            if(checkAsciiContained(arr1,arr))
            {
                arr[q.front()]--;
                while(checkAsciiContained(arr1,arr))
                {
                    start++;
                    q.pop();
                    arr[q.front()]--;
                }
                if(min>i-start+1)
                {
                    res=s.substr(start,i-start+1);
                    min=i-start+1;
                }
                start++;
                q.pop();
            }
            
            
        }
        return res;
        
    }
};
