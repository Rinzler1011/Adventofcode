#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>



int main() {

    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }



    std::vector<int> groupOne; 
    std::vector<int> groupTwo;
    int distance;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int left, right;
        if (iss >> left >> right) { 
            groupOne.push_back(left);
            groupTwo.push_back(right);
        }
    }

    inputFile.close();

    sort(groupOne.begin(), groupOne.end());
    sort(groupTwo.begin(), groupTwo.end());

    for (int i = 0; i < groupOne.size(); i++) { 
    
    std::cout << groupOne[i] << " , " << groupTwo[i] << '\n';
   

    distance += std::abs(groupOne[i] - groupTwo[i]);

    }

    std::cout << distance << '\n';


    int simScore;
    
    for (int i = 0; i < groupOne.size(); i++){
        int num = groupOne[i];
        int count = 0;
        for (int j = 0; j < groupTwo.size(); j++){
            if(num == groupTwo[j]){
                count++;
            }
        }
        simScore += num * count;
    }

    std::cout << simScore << '\n';




    return 0;
}
