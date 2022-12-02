#include <iostream>
#include <fstream>
#define FMT_HEADER_ONLY
#include <fmt/core.h>

int main(int argc, char **argv)
{
    std::fstream input_file;
    input_file.open("input.txt");
    if (input_file.is_open()) {
        std::string input;
        while (input_file >> input) {
            // std::getline(input_file, input);
            fmt::print("{}\n", input);
        }
    }
     
    return 1;
}