class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        vector<vector<vector<int>>> v(n, vector<vector<int>>(m));
        vector<vector<int>> res(n, vector<int>(m));

        for (int i = 0; i < n - 2; i++)
        {

            for (int j = 0; j < m - 2; j++)
            {
                int temp_sum = 0;
                bool excluded = false;
                for (int k = i; k < i + 3 && k < n; k++)
                {
                    for (int l = j; l < j + 3 && l < m; l++)
                    {
                        if (!(((k == i) || (abs(image[k - 1][l] - image[k][l]) <= threshold)) && ((k == i + 2) || (abs(image[k + 1][l] - image[k][l]) <= threshold)) && ((l == j) || (abs(image[k][l - 1] - image[k][l]) <= threshold)) && ((l == j + 2) || (abs(image[k][l + 1] - image[k][l]) <= threshold))))
                        {
                            excluded = true;
                        }
                        else
                        {
                            temp_sum += image[k][l];
                            ;
                        }
                    }
                }
                if (!excluded)
                {
                    for (int k = i; k < i + 3 && k < n; k++)
                    {
                        for (int l = j; l < j + 3 && l < m; l++)
                        {
                            v[k][l].push_back(temp_sum / 9);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int temp_sum = 0;
                for (int x : v[i][j])
                {
                    temp_sum += x;
                }
                res[i][j] = v[i][j].size() == 0 ? image[i][j] : temp_sum / v[i][j].size();
            }
        }
        return res;
    }
};