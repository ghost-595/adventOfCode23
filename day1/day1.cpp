#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <regex>
#include <unordered_map>

using namespace std;

int main() {

    unordered_map<string, string> numberMap = {
        {"(one)", "one1one"}, {"(two)", "two2two"}, {"(three)", "three3three"}, {"(four)", "four4four"},
        {"(five)", "five5five"}, {"(six)", "six6six"}, {"(seven)", "seven7seven"}, {"(eight)", "eight8eight"}, {"(nine)", "nine9nine"}
    };

    const char* filename = "input.txt";

    ifstream inputFile;

    inputFile.open(filename);

    string nums = "";
    int sum = 0;
    char character;
    string result = "";

    while(getline(inputFile, result)) {
        for (const auto& entry : numberMap) {
            regex regexPattern(entry.first);
            result = regex_replace(result, regexPattern, entry.second);
        }

        result += '\n';

        for (char character : result) {
            if (isdigit(character)) {
                if (nums.size() >=  2) {
                    nums.pop_back();
                }
                nums += character;
            } else if (character == '\n') {
                if (nums.size() == 1) {
                    nums += nums;
                }
                sum += stoi(nums);
                nums = "";
            }
        }
    }

    cout<<sum<<endl;

    inputFile.close();

    return 0;
}