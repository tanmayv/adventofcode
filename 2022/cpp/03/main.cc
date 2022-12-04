#include <fstream>
#include <map>
#include <cctype>

int GetScore(char c) {
    if (std::isupper(c)) {
        return c - 'A' + 27;
    }
    return c - 'a' + 1;
}
template <typename T>
int vlog(T x) {
    std::cout << x << std::endl;
}
int main1(int argc, char **argv)
{
    std::fstream input_file;
    input_file.open("input.txt");
    if (input_file.is_open()) {
        std::string input;
        int sum = 0;
        while (input_file >> input) {
            // std::getline(input_file, input);
            std::map<char, bool> map;
            vlog(input);
            int half = input.length() / 2;
            std::cout << "Half point: " << half << std::endl;
            int current = 0;
            for(auto& c: input) {
                if (current < half) {
                    map.insert({c, true});
                } else {
                    auto it = map.find(c);
                    if (it != map.end()) {
                        std::cout << "Score for " << c << " is " << GetScore(c) << std::endl;
                        sum += GetScore(c);     
                        break;
                    }
                }
                ++current;
            }
        }
        std:: cout << "Result: " << sum;
    }
     
    return 1;
}

void FillTable(int* table, std::string string, int base) {
    for (auto& c: string) {
        if (table[c] == base)
            table[c]++;
    }
}

int GetScoreFromTable(int* table, int size) {
    for (int i = 0; i < size; ++i) {
        if (table[i] == 3) {
            std:: cout << "Scoring for " << (char) i << " " << GetScore(i)<<std::endl;
            return GetScore(i);
        }
    }
    std::cout << "INVALID LOGIC" << std::endl;;
    return -1;
}

int main(int argc, char **argv)
{
    std::fstream input_file;
    input_file.open("input.txt");
    if (input_file.is_open()) {
        std::string input1, input2, input3;
        int sum = 0;
        while (input_file >> input1 >> input2 >> input3) {
            // std::getline(input_file, input);
            int table[256] = {0};
            FillTable(table, input1, 0);
            FillTable(table, input2, 1);
            FillTable(table, input3, 2);
            sum += GetScoreFromTable(table, 256);
        }
        std:: cout << "Result: " << sum;
    }
     
    return 1;
}