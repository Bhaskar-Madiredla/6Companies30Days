class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& brd) {
        vector<set<int>> rst(9); 
        vector<set<int>> cst(9); 
        vector<set<int>> colst(9); 

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (brd[i][j] == '.') continue;

                int num = brd[i][j] - '0';

                if (rst[i].find(num) != rst[i].end()) return false;
                rst[i].insert(num);

                if (colst[j].find(num) != colst[j].end()) return false;
                colst[j].insert(num);

                int boxIndex = (i / 3) * 3 + (j / 3);
                if (cst[boxIndex].find(num) != cst[boxIndex].end()) return false;
                cst[boxIndex].insert(num);
            }
        }
        return true;
    }
};
