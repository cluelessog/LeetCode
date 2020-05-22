class Solution {
public:
    int findComplement(int num) {
        int result = 0;
        int j = 0;
        if(num == 0)
        {
            return 1;
        }
        while(num > 0)
        {
            int tmp = num&1;
            num >>= 1;
            if(tmp == 0)
            {
               result += pow(2,j)*1;
            }
            j++;
        }
        return result;
    }
};
