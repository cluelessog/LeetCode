class Solution {
    void floodFillUtil(vector<vector<int>>& image, int x, int y, int prev,int newC)
    {
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size())
        {
            return;
        }
        if(image[x][y] != prev)
        {
            return;
        }
        if(image[x][y] == newC)
        {
            return;
        }
        image[x][y] = newC;
        floodFillUtil(image,x+1,y,prev,newC);
        floodFillUtil(image,x-1,y,prev,newC);
        floodFillUtil(image,x,y+1,prev,newC);
        floodFillUtil(image,x,y-1,prev,newC);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int startColor = image[sr][sc];
        floodFillUtil(image,sr,sc,startColor,newColor);
        return image;
    }
};
