class Solution {
public:
    string frequencySort(string s) {
        
        int freq[256] = {0};
        for(int i = 0 ; i < s.size(); i++)
        {
                freq[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i = 0 ; i < 256; i++)
        {
            if(freq[i] != 0) pq.push(make_pair(freq[i],i));
        }
        string ret = "";
        pair<int,char> top;
        while(!pq.empty())
        {
            top = pq.top();
            while(top.first--) ret += top.second;
            pq.pop();   
        }
        return ret;
        
    }
};
