#include <iostream>
#include <vector>
#include <unordered_set>

// Mengecek apakah papan Sudoku valid
// (tidak ada angka yang berulang di baris, kolom, atau box 3x3).
// Ini partial validator
// (tidak peduli apakah Sudoku sudah selesai, hanya validasi current state).

bool validSudoku(std::vector<std::vector<char>> &board)
{
    // untuk jumlah row, col, dan box
    int n = 9;

    // membuat array dari unordered_set
    std::vector<std::unordered_set<char>> row(n);
    std::vector<std::unordered_set<char>> col(n);
    std::vector<std::unordered_set<char>> box(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // taruh board kedalam val
            char val = board[i][j];

            // lewati cell kosong ('.')
            if (val == '.')
            {
                continue;
            }

            // cek apakah angka val sudah ada di row[i] (baris ke-i)
            if (row[i].count(val))
            {
                // jika ya board tidak valid -> return false
                return false;
            }
            // kalau belum ada, masukan angka tsb
            row[i].insert(val);

            // cek apakah angka val sudah ada di col[j] (kolom ke-j)
            if (col[j].count(val))
            {
                // jika ya, invalid
                return false;
            }
            // jika belum, masukan angka ke set kolom
            col[j].insert(val);

            // box index dihitung dengan formula
            // (i / 3) * 3 + (j / 3)
            // membagi grid 9 x 9 menjadi 9 box (index 0 - 8)
            int idx = (i / 3) * 3 + j / 3;
            // cek apakah angka val sudah ada dibox tersebut
            if (box[idx].count(val))
            {
                // jika ya, invalid
                return false;
            }
            // jika belum, masukan angka ke set box
            box[idx].insert(val);
        }
    }
    // jika tidak ada konflik disemua baris, kolom, atau box. Sudoku valid.
    return true;
}

int main()
{
    std::vector<std::vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (validSudoku(board))
    {
        std::cout << "Valid" << std::endl;
    }
    else
    {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}

/*
iterasi i = 0; j = 0;
val = '8';
row[0] belum ada '8' -> ok
col[0] belum ada '8' -> ok
box[0] belum ada '8' -> ok
masukan '8' ke row[0],col[0],box[0]

iterasi i = 3; j = 0
val = '8';
row[3] belum ada '8' -> ok
col[0] sudah ada '8' -> invalid sudoku -> return false

formula idx ->
contoh 1: cell (2,1)
    i = 2, j = 1
    (i / 3) = 2 / 3 = 0 (karena integer division)
    (j / 3) = 1 / 3 = 0
    idx = (0) * 3 + 0 = 0
    → Box 0 (kotak kiri atas)

contoh 2: cell (1,4)
    i = 1, j = 4
    (i / 3) = 1 / 3 = 0
    (j / 3) = 4 / 3 = 1
    idx = (0) * 3 + 1 = 1
    → Box 1 (kotak atas tengah)

contoh 3: cell (4,4)
    i = 4, j = 4
    (i / 3) = 4 / 3 = 1
    (j / 3) = 4 / 3 = 1
    idx = (1) * 3 + 1 = 4
    → Box 4 (kotak tengah)

dst...

[0,0][0,1][0,2] [0,3][0,4][0,5] [0,6][0,7][0,8]
[1,0][1,1][1,2] [1,3][1,4][1,5] [1,6][1,7][1,8]
[2,0][2,1][2,2] [2,3][2,4][2,5] [2,6][2,7][2,8]

[3,0][3,1][3,2] [3,3][3,4][3,5] [3,6][3,7][3,8]
[4,0][4,1][4,2] [4,3][4,4][4,5] [4,6][4,7][4,8]
[5,0][5,1][5,2] [5,3][5,4][5,5] [5,6][5,7][5,8]

[6,0][6,1][6,2] [6,3][6,4][6,5] [6,6][6,7][6,8]
[7,0][7,1][7,2] [7,3][7,4][7,5] [7,6][7,7][7,8]
[8,0][8,1][8,2] [8,3][8,4][8,5] [8,6][8,7][8,8]
*/