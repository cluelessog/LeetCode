class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) return 0;
        int numPapers = citations.size();
        int l = 0;
        int r = numPapers-1;
        int mid = 0;
        while(l <= r)
        {
            mid = l + (r-l)/2;
            if(citations[mid] == (numPapers-mid))
            {
                return (numPapers-mid);
            }
            else if(citations[mid] < (numPapers-mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            
        }
        return numPapers-l;
    }
};
