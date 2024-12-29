#include <iostream>
#include <fstream>
#include <cstdlib>

  /* replace below value with the max amount of times you want
     to make commits per run of the program */
const int kContributionCountPerRuntimeUpperBound = 100;

int main(int argc, const char** argv)
{

  for(int i = 0; i<kContributionCountPerRuntimeUpperBound; i++)
  {
    // Open the file in read/write mode
    const char* fileName = "datadumpfile.txt";
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file " << fileName << "\n";
        return 1;
    }

    // Read the current integer value from the file
    int currentValue = 0;
    inputFile >> currentValue;
    inputFile.close();

    //current security bounds
    if (currentValue >= 10956){
      currentValue = 0;
    }
    // Increment the value
    currentValue++;

    // Write the incremented value back to the file
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to write to the file " << fileName << "\n";
        return 1;
    }

    outputFile << currentValue;
    outputFile.close();

    std::string commitMessage = "Incremented Data Dump File Count";
    std::system("git add datadumpfile.txt");
    std::string gitCommitCommand = "git commit -m \"" + commitMessage + "\"";
    std::system(gitCommitCommand.c_str());
  }

    std::system("git push");

  return 0;

}
