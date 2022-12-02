#include <iostream>
#include <fstream>
#define FMT_HEADER_ONLY
#include <fmt/core.h>
#include <string>
#include <algorithm>

int main(int argc, char **argv)
{
    std::fstream input_file;
    input_file.open("input.txt");
    if (input_file.is_open())
    {
        std::string input;
        int current_max1 = 0;
        int current_max2 = 0;
        int current_max3 = 0;
        int current = 0;
        while (input_file)
        {
            std::getline(input_file, input);
            // ideally use max heap
            if (input == "")
            {
                if (current_max1 < current) {
                    current_max3 = current_max2;
                    current_max2 = current_max1;
                    current_max1 = current;
                }

                else if (current_max2 < current) {
                    current_max3 = current_max2;
                    current_max2 = current;
                }

                else if (current_max3 < current) {
                    current_max3 = current;
                }
                current = 0;
            } else {
                current += std::stoi(input);
            }
        }
        fmt::print("Calories being carried by the elf with most calories: {} > {} > {} \n", current_max1, current_max2, current_max3);
        fmt::print("Total of three {}", current_max1 + current_max2 + current_max3);
    }

    return 1;
}