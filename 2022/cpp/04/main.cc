#include <iostream>
#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <regex>

bool Contains(std::pair<int, int> range1, std::pair<int, int> range2) {
    if (range1.first >= range2.first && range1.second <= range2.second)
        return true;
    return false;
}

void Print(std::pair<int, int> p, std::pair<int, int> q)
{
    std::cout << p.first << "-" << p.second << "," << q.first << "," << q.second << std::endl;
}

bool Disjoint(std::pair<int, int> range1, std::pair<int, int> range2) {
    if (range1.first < range2.first && range1.second < range2.first)
        return true;
    return false;
}

int main(int argc, char **argv)
{
    std::fstream input_file;
    input_file.open("input.txt");
    if (input_file.is_open()) {
        std::regex regex("^(\\d+)-(\\d+),(\\d+)-(\\d+)$");
        std::cout << "Starting" << std::endl;
        std::pair<int, int> range1, range2;
        std::string input;
        int count = 0;
        int overlap = 0;
        while (input_file >> input)
        {
            std::smatch m;
            std::regex_match(input, m, regex);
            range1 = std::pair{std::stoi(m[1]), std::stoi(m[2])};
            range2 = std::pair{std::stoi(m[3]), std::stoi(m[4])};

            if (range1.first == 0) std::cout << "BANG";
            if (range1.second == 0) std::cout << "BANG";
            if (range2.first == 0) std::cout << "BANG";
            if (range2.second == 0) std::cout << "BANG";
            if (Contains(range1, range2) || Contains(range2, range1)) {
                std:: cout << "Contains ";
                Print(range1, range2);
                ++count;
            }
            if (!(Disjoint(range1, range2) || Disjoint(range2, range1)))
            {
                std::cout << "Overlap ";
                Print(range1, range2);
                ++overlap;
            }
            // std::getline(input_file, input);
            // std::cout << range1.first << range2.second << std::endl;
        }
        std::cout<< "Contained: " << count << std::endl;
        std::cout<< "Overlapped: " << overlap << std::endl;
    }
     
    return 1;
}