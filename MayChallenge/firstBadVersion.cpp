// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1; 
        int r = n;
        int bad = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if((isBadVersion(mid) == true) && (mid == 1 || isBadVersion(mid - 1) == false))
            {
                bad = mid;
                break;
            }
            else if(isBadVersion(mid) == false)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return bad;
    }
};
