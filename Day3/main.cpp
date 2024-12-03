#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>


int main() {


    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }

    std::string line;
    std::regex mul_regex(R"(mul\(\d*,\d*\)|do\(\)|don't\(\))");

    // name is stack because I was using a stack for part 1.
    std::queue<std::string> stack;

    while (std::getline(inputFile, line)) {
        
        auto begin = std::sregex_iterator(line.begin(), line.end(), mul_regex);
        auto end = std::sregex_iterator();
 
        for (std::sregex_iterator i = begin; i != end; ++i) {
        
            std::string string = i->str();

          

            std::regex number_regex(R"(\d+|do\(\)|don't\(\))");
            std::smatch match;
            
            std::string::const_iterator search_start(string.cbegin());
            while (std::regex_search(search_start, string.cend(), match, number_regex)) {
                std::string num = (match[0].str());
                stack.push(num);
                search_start = match.suffix().first;

            }
        }

    }

    inputFile.close();

    int count = 0;
    bool skip = false;

    std::regex number_regex(R"(\d+)");

    // while (!stack.empty()){
    //     std::cout << stack.front() << '\n'; 
    //     stack.pop();
    // }

    while (!stack.empty()) {

        std::string top = stack.front();
        stack.pop();

        if (!skip) {
            if (std::regex_match(top, number_regex)) {
                // Pop the second number and calculate the product
                if (!stack.empty()) {
                    int num1 = std::stoi(top);
                    std::string second = stack.front();
                    stack.pop();

                    if (std::regex_match(second, number_regex)) {
                        int num2 = std::stoi(second);
                        count += num1 * num2;
                        //std::cout << "Num1: " << num1 << ", Num2: " << num2 << ", Count: " << count << '\n';
                    }
                }
            } else if (top == "do()") {
                skip = false;
                std::cout << "Switch Do";
            } else if (top == "don't()") {
                std::cout << "Switch Dont";
                skip = true;
            }
        } else { 
           if (std::regex_match(top, number_regex)){
                stack.pop();
           } else if (top == "do()")
           {
            skip = false;
           } else { 
            skip = true;
           }
        }
    }

    // Output the result
    std::cout << "Final count: " << count << std::endl;
   

    return 0;
}