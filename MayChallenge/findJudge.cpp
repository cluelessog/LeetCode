class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> incomingTrust(N+1);
        vector<int> outgoingTrust(N+1);
        for(auto i : trust)
        {
            incomingTrust[i[1]]++;
            outgoingTrust[i[0]]++;
        }
        for(int i = 1; i <=N ; i++)
        {
            //for any person to be judge, outgoing trust must be zero and incoming trust must me N-1(all except him)
            if(outgoingTrust[i] == 0 && incomingTrust[i] == N - 1)
            {
                return i;
            }
        }
        return -1;
    }
};
