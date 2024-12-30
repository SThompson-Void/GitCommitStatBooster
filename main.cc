#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>

// replace below value with the max amount of times you want to make commits per run of the program
const int kContributionCountPerRuntimeUpperBound = 250;
const int kContributionCountPerRuntimeLowerBound = 50;

int main(int argc, const char** argv)
{
  //marsenne twister rand prng using kContributionCountPerRuntimeUpperBound as lim:
  std::mt19937 generator(std::random_device{}());
  std::uniform_int_distribution<int> distribution(kContributionCountPerRuntimeLowerBound, kContributionCountPerRuntimeUpperBound);
  int randSelectedLimit = distribution(generator);

  //cli app intro formatting
  std::cout <<"\n-------------------------------------------------------\n";
  std::cout << "\n\tWelcome to VOID's Git Commit Booster v1.1!\n";
  std::cout <<"\n-------------------------------------------------------\n";
  std::cout <<"\n\n\tMaking " << randSelectedLimit << " commits...\n";

  for(int i = 0; i < randSelectedLimit; i++)
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
    std::cout <<"\n\n\t" << randSelectedLimit << " Pushed to Remote! \n\n\t(enter any char to exit)";
    std::cout <<"\n-------------------------------------------------------\n";
    char temp{};
    std::cin >> temp;
  return 0;
}
