class Solution {
public:
    bool isPerfectSquare(int num) {
        // long long int i = 0;
        // while(i*i <= num)
        // {
        //     if(i*i == num)
        //     {
        //         return true;
        //     }
        //     i++;
        // }
        // return false;
        //sqrt of num cannot be greater than num/2 for num > 1
        if( num == 1)
            return true;
        int l = 0;
        int r = num/2;
        while(l <= r)
        {
            long long int mid = l + (r-l)/2;
            if(mid*mid == num)
                return true;
            if(mid*mid > num)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;   
            }
        }
        return false;
    }
};
