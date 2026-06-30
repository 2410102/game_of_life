// The implementation of Game of Life by John Convey.
// '#' means an alive cell, '.' means a dead one

#include <iostream>
#include <vector>
#include <algorithm>

constexpr int TO_REVIVE = 3;
constexpr int MAX_TO_SURVIVE = 3;
constexpr int MIN_TO_SURVIVE = 2;

std::vector<std::vector<int>>
build(const std::vector<std::vector<int>> & mtrx)
{
    unsigned long long rows = mtrx.size();
    unsigned long long cols = mtrx[0].size();
    std::vector<std::vector<int>> res(rows, std::vector<int>(cols, 0));
    for (unsigned long long i = 0; i < rows; ++i) {
        for (unsigned long long j = 0; j < cols; ++j) {
            int alive_cnt = 0;
            alive_cnt += mtrx[(i + 1 + rows) % rows][(j + 1 + cols) % cols];
            alive_cnt += mtrx[(i + 1 + rows) % rows][(j + cols) % cols];
            alive_cnt += mtrx[(i + 1 + rows) % rows][(j - 1 + cols) % cols];
            alive_cnt += mtrx[(i + rows) % rows][(j + 1 + cols) % cols];
            alive_cnt += mtrx[(i + rows) % rows][(j - 1 + cols) % cols];
            alive_cnt += mtrx[(i - 1 + rows) % rows][(j + 1 + cols) % cols];
            alive_cnt += mtrx[(i - 1 + rows) % rows][(j + cols) % cols];
            alive_cnt += mtrx[(i - 1 + rows) % rows][(j - 1 + cols) % cols];
            if (!mtrx[i][j] && alive_cnt == TO_REVIVE) {
                res[i][j] = 1;
            } else if (mtrx[i][j] && (alive_cnt >= MIN_TO_SURVIVE && alive_cnt <= MAX_TO_SURVIVE)) {
                res[i][j] = 1;
            } else if (mtrx[i][j]) {
                res[i][j] = 0;
            } else {
                res[i][j] = mtrx[i][j];
            }
        }
    }
    return res;
}

int
main(void)
{
    unsigned long long rows = 0;
    unsigned long long cols = 0;
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;
    if (!rows || !cols) {
        std::cout << "Empty place." << std::endl;
        return 0;
    }
    std::cout << std::endl;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    std::cout << "Enter the generation 0:" << std::endl;
    for (unsigned long long i = 0; i < rows; ++i) {
        for (unsigned long long j = 0; j < cols; ++j) {
            bool flag = true;
            char sym = 0;
            while (flag && (std::cin >> sym)) {
                if (sym == '#' || sym == '.') {
                    flag = false;
                } else {
                    std::cout << "Wrong symbol." << std::endl;
                }
            }
            matrix[i][j] = (sym == '#') ? 1 : 0;
        }
    }
    std::vector<std::vector<std::vector<int>>> states;
    while (std::find(states.begin(), states.end(), matrix) == states.end()) {
        states.push_back(matrix);
        matrix = build(matrix);
        std::cout << std::endl;
        std::cout << "Generation " << states.size() << ":" << std::endl;
        for (const auto & line : matrix) {
            for (const auto & elm : line) {
                std::cout << (elm ? '#' : '.');
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "The generation " << states.size() << " coincides with generation ";
    std::cout << std::distance(states.begin(), std::find(states.begin(), states.end(), matrix)) << std::endl;
    std::cout << "Game of Life over" << std::endl;
    return 0;
}
