#include <iostream>
#include <fstream>
#define FMT_HEADER_ONLY
#include <fmt/core.h>

// move = ROCK(0), PAPER(1), SCISSOR(2)
int GetScore(int move1, int move2) {
    //  win
    if (move1 == move2) return 4 + move2;
    int can_win = move2 - 1;
    if (can_win < 0) can_win += 3;
    return (can_win == move1 ? 7: 1) + move2;
}

int GetMove(int move1, int outcome) {
    // DRAW
    if (outcome == 1) {
        return move1;
    }
    // WIN
    if (outcome == 2)  {
        return (move1 + 1) % 3;
    }
    // LOSE
    return move1 == 0 ? 2 : move1 - 1;
}

int main(int argc, char **argv)
{
    std::fstream input_file;
    fmt::print("Program start \n");
    input_file.open("input.txt");
    if (input_file.is_open()) {
        char opponent_move, player_move;
        int total_1 = 0;
        int total_2 = 0;
        while (input_file >> opponent_move >> player_move) {
            // input_file >> opponent_move;
            // input_file >> player_move;
            // std::getline(input_file, input);
            int move1 = opponent_move - 'A';
            int move2 = player_move - 'X';
            int req_outcome = move2;
            total_1 += GetScore(move1, move2);
            total_2 += GetScore(move1, GetMove(move1, req_outcome));
        }
        fmt::print("Result for part 1: {}\n", total_1);
        fmt::print("Result for part 2: {}\n", total_2);
    }
    else {
        fmt::print("Couldn't open input.txt");
    }
     
    return 1;
}