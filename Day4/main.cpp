#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

void part1(std::vector<std::string> puzzle){

    int l1 = puzzle.size(); 
    int l2 = puzzle[0].size();
    int d[] = {-1, 0, 1}; 
    std::string word = "XMAS";
    int total = 0;

    for(int i = 0; i < l1; i++){
        for(int j = 0; j < l2; j++){
            for(int dx : d){
                for(int dy : d){
                    if(dx == 0 && dy == 0){
                        continue;
                    }
                    int x = i; 
                    int y = j;
                    bool found = true;
                    for (char letter : word){
                        if(x < 0 || x >= l1 || y < 0 || y >= l2 || puzzle[x][y] != letter){
                            found = false;
                            break; 
                        }
                        x += dx; 
                        y += dy;
                    }
                    if(found){
                        total++;
                    }
                }
            }
        }
    }

    std::cout << total;

}

void part2(std::vector<std::string> puzzle){

    int l1 = puzzle.size(); 
    int l2 = puzzle[0].size();
    int d[] = {-1, 0, 1}; 
    std::string word = "XMAS";
    int total = 0;

    for(int i = 1; i < l1 - 1; i++){
        for(int j = 1; j < l2 - 1; j++){
            if(puzzle[i][j] != 'A'){
                continue;
            } 

            std::string s = ""; 
            s += puzzle[i-1][j-1]; 
            s += puzzle[i+1][j+1];

            std::string s2 = ""; 
            s2 += puzzle[i-1][j+1]; 
            s2 += puzzle[i+1][j-1];

            if (s != "MS" && s != "SM"){ 
                continue;
            }

            if (s2 != "MS" && s2 != "SM"){ 
                continue;
            }
            total++;
        }
    }

    std::cout << total;

}


int main() {


    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }

    std::string line;

    // name is stack because I was using a stack for part 1.
    std::vector<std::string> puzzle;

    while (std::getline(inputFile, line)) {
        puzzle.push_back(line);
    }

    inputFile.close();


    for (int i = 0; i < puzzle.size(); i++) { 
    
    std::cout << puzzle[i] << '\n';
    }

    part1(puzzle);
    part2(puzzle);
   

    return 0;
}