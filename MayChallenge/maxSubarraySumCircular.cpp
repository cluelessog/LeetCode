class Solution {
    int Kadane(vector<int>& A)
    {
        int maxSoFar = A[0];
        int currentMax = 0;
        int i = 0;
        while(i < A.size())
        {
            currentMax = currentMax + A[i];
            if(currentMax > maxSoFar)
            {
                maxSoFar = currentMax;
            }
            if(currentMax < 0)
            {
                currentMax = 0;
            }
            i++;
        }
        return maxSoFar;
    }
public:
    int maxSubarraySumCircular(vector<int>& A) {
        // int maxSoFar = INT_MIN;
        // int maxEndHere;
        // int i = 0;
        // while(i < A.size())
        // {
        //     maxEndHere = 0;
        //     int start = i;
        //     int end = i + A.size();
        //     while(start < end)
        //     {
        //         int j = start%A.size();
        //         maxEndHere = maxEndHere + A[j];
        //         if(maxEndHere > maxSoFar)
        //         {
        //             maxSoFar = maxEndHere;
        //         }
        //         if(maxEndHere < 0)
        //         {
        //             maxEndHere = 0;
        //         }
        //         start++;
        //     }
        //     //cout << endl;
        //    i++; 
        // }
        // return maxSoFar; TLE exceeded
        int kadMax = Kadane(A);
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i < A.size(); i++)
        {
            sum += A[i];
            if(A[i] < 0) count++;
            A[i] = -A[i];
        }
        int kad = Kadane(A);
        int finalKad = sum + kad;
        if(count == A.size()) return kadMax;
        return kadMax > finalKad ? kadMax : finalKad;
        
    }
};
