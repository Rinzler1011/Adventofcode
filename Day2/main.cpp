#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>


bool is_safe(const std::vector<int>& seq) {
    if (seq.size() < 2) return true;

    int first_diff = seq[1] - seq[0];
    if (abs(first_diff) == 0 || abs(first_diff) > 3)
        return false;

    int direction = (first_diff > 0) ? 1 : -1;
    for (size_t i = 1; i < seq.size(); ++i) {
        int diff = seq[i] - seq[i - 1];
        if (abs(diff) == 0 || abs(diff) > 3)
            return false;
        int curr_direction = (diff > 0) ? 1 : -1;
        if (curr_direction != direction)
            return false;
    }
    return true;
}

bool is_safe_with_removal(const std::vector<int>& seq) {
    if (is_safe(seq))
        return true;
    for (size_t i = 0; i < seq.size(); ++i) {
        std::vector<int> new_seq = seq;
        new_seq.erase(new_seq.begin() + i);
        if (is_safe(new_seq))
            return true;
    }
    return false;
}


int main() {

    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }

    std::vector<std::vector<int>> allNumbers; 

    std::string line;
    while (std::getline(inputFile, line)) { 
        std::istringstream lineStream(line); 
        std::vector<int> row; 
        int number;

        while (lineStream >> number) { 
            row.push_back(number);   
        }

        allNumbers.push_back(row); 
    }

    inputFile.close();

    int count;

    // for(const auto& row: allNumbers){

    //     bool all = true;
    //     bool dif = true;
    //     int increase;
    //     int decrease;
    //     bool remove = false;

    //     for(int num = 0; num < row.size() - 2; num++){

    //         int num1 = row[num];

        
    //         int num2 = row[num+1];
    //         int num3 = row[num+2];

    //         std::cout << "Num1: " << num1 << " Num2: " << num2 <<  " Num3: " << num3 << " , ";

    //         int diff1 = num1 - num2;
    //         int diff2 = num2 - num3;

    //         int absdiff1 = abs(diff1);
    //         int absdiff2 = abs(diff2); 

    //         std::cout << "Diff1: " << diff1 << " Diff2: " << diff2;
    //         if(absdiff1 > 3 || absdiff1 == 0 || absdiff2 > 3 || absdiff2 == 0){
    //             dif = false; 
    //             std::cout << "DIFFFFFFF";
    //         }


    //         if(diff1 > 0){
    //             increase++;
    //         }else if (diff1 < 0)
    //         {
    //             decrease++;
    //         }
            

    //         if(diff2 > 0){
    //             increase++;
    //         }else if (diff2 < 0)
    //         {
    //             decrease++;
    //         }
    //     }

    //     if(increase > 0 && decrease > 0){
    //         all = false;
    //         std::cout << "ALL , ";
    //     }

    //     if(all && dif && !remove){
    //         count++;
    //         std::cout << "ALL GOOD, ";
    //     }

    //     all = true; 
    //     dif = true; 

    //     increase = 0; 
    //     decrease = 0;

    //     std::cout << '\n';
    // }

    // std::cout << count;


    // Part 2

    int count2 = 0; // Initialize count2 to 0

    for (const auto& row : allNumbers) {
        if (is_safe_with_removal(row)) {
            count2++;
        }
    }

    std::cout << count2 << std::endl;


    return 0;
}
