#!/bin/python3
import collections

def solving(arr)->bool:
    rows =collections.defaultdict(set)
    cols =collections.defaultdict(set)
    square =collections.defaultdict(set)
    for i in range(9):
        for j in range(9):
            if arr[i][j]==".":
                continue
            if (arr[i][j] in rows[i] or arr[i][j] in cols[j] or arr[i][j] in square[(i//3,j//3)]) :
                return False
            rows[i].add(arr[i][j])
            cols[j].add(arr[i][j])
            square[(i//3,j//3)].add(arr[i][j])
    return True



board = [["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","8",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]

k = solving(board)

print(k)

