
class Solution {
public:
    vector<vector<int>> rects;
    vector<int> prefixSums;
    int totalArea;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        totalArea = 0;
        for (const auto& rect : rects) {
            int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            totalArea += area;
            prefixSums.push_back(totalArea);
        }
    }

    vector<int> pick() {
        int randArea = rand() % totalArea;
        int rectIdx = upper_bound(prefixSums.begin(), prefixSums.end(), randArea) - prefixSums.begin();
        const auto& rect = rects[rectIdx];

        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);

        return {x, y};
    }
};
