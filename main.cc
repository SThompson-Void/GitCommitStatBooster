#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>

// replace below value with the max amount of times you want to make commits per run of the program
const int kContributionCountPerRuntimeUpperBound = 200;
const int kContributionCountPerRuntimeLowerBound = 25;

int GenerateRandomNumber();
void PrintIntroText(int random_number_for_commits);
void PrintOutroText(int random_number_for_commits);
void GitCommitListExec(int random_number_for_commits);


int main(int argc, const char** argv)
{
  char main_while_loop_selection{'Y'};
  while(main_while_loop_selection == 'y' || main_while_loop_selection == 'Y')
  {
    main_while_loop_selection = ' ';

    int random_number_for_commits{GenerateRandomNumber()};
    PrintIntroText(random_number_for_commits);
    GitCommitListExec(random_number_for_commits);
    PrintOutroText(random_number_for_commits);

    std::cout <<"Would you like to run again? (Y/N): ";
    std::cin >> main_while_loop_selection;

  }
  return 0;
}

int GenerateRandomNumber()
{
  std::mt19937 generator(std::random_device{}());
  std::uniform_int_distribution<int> distribution(kContributionCountPerRuntimeLowerBound, kContributionCountPerRuntimeUpperBound);
  int random_number_for_commits = distribution(generator);
  return random_number_for_commits;
}

void PrintIntroText(int random_number_for_commits)
{
  std::cout <<"\n-------------------------------------------------------\n";
  std::cout << "\n\tWelcome to VOID's Git Commit Booster v1.1!\n";
  std::cout <<"\n-------------------------------------------------------\n";
  std::cout <<"\n\nMaking " << random_number_for_commits << " commits...\n";
}

void PrintOutroText(int random_number_for_commits)
{
    std::cout <<"\n\n\tFinally pushing commits to git!";
    //std::system("git push --quiet");
    std::cout <<"\n\n\t" << random_number_for_commits << " commits Pushed to Remote! \n\n\t(enter any char to exit)";
    std::cout <<"\n-------------------------------------------------------\n";
}

void GitCommitListExec(int random_number_for_commits)
{
  for(int i = 0; i < random_number_for_commits; i++)
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

    //temp test git methods:
    /*
    std::cout <<
    "\nCommit message: Incremented Data Dump File Count" <<
    "\ngit add datadumpfile.txt" <<
    "\ngit commit --quiet -m commit message!";
  */
    std::string commitMessage = "Incremented Data Dump File Count";
    std::system("git add datadumpfile.txt");
    std::string gitCommitCommand = "git commit --quiet -m \"" + commitMessage + "\"";
    std::system(gitCommitCommand.c_str());
  }

}