#include <iostream>
#include <fstream>
#include <cstdlib>

  /* replace below value with the max amount of times you want
     to make commits per run of the program */
const int kContributionCountPerRuntimeUpperBound = 100;

int main(int argc, const char** argv)
{
  std::cout <<"\n-------------------------------------------------------\n";
  std::cout << "\n\tWelcome to VOID's Git Commit Booster v1.1!\n";
  std::cout <<"\n-------------------------------------------------------\n";
  std::cout <<"\n\n\tMaking " << kContributionCountPerRuntimeUpperBound << " commits...\n";

  for(int i = 0; i < kContributionCountPerRuntimeUpperBound; i++)
  {
    // Open the file in read/write mode
    const char* fileName = "datadumpfile.txt";
    std::ifstream inputFile(fileName);

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

    outputFile << currentValue;
    outputFile.close();

    std::string commitMessage = "Incremented Data Dump File Count";
    std::system("git add datadumpfile.txt");
    std::string gitCommitCommand = "git commit --quiet -m \"" + commitMessage + "\"";
    std::system(gitCommitCommand.c_str());
  }

    std::system("git push --quiet");
    std::cout <<"\n\n\t" << kContributionCountPerRuntimeUpperBound << " Pushed to Remote! \n\n\t(enter any char to exit)";
    std::cout <<"\n-------------------------------------------------------\n";
    char temp{};
    std::cin >> temp;
  return 0;

}
