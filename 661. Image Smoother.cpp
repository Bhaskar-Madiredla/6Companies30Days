class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();

        vector<vector<int>> result(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                double sum = img[i][j], c = 1;
                if (i > 0)
                {
                    sum += img[i - 1][j];
                    ++c;
                    if (j > 0)
                    {
                        sum += img[i - 1][j - 1];
                        ++c;
                    }
                }
                if (j > 0)
                {
                    sum += img[i][j - 1];
                    ++c;
                    if (i + 1 < m)
                    {
                        sum += img[i + 1][j - 1];
                        ++c;
                    }
                }
                if (i + 1 < m)
                {
                    sum += img[i + 1][j];
                    ++c;
                    if (j + 1 < n)
                    {
                        sum += img[i + 1][j + 1];
                        ++c;
                    }
                }
                if (j + 1 < n)
                {
                    sum += img[i][j + 1];
                    ++c;
                    if (i > 0)
                    {
                        sum += img[i - 1][j + 1];
                        ++c;
                    }
                }
                result[i][j] = sum / c;
            }
        }
        return result;
    }
};
