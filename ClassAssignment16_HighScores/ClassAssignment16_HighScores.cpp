#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

int main()
{
    std::vector<int>::const_iterator iter;

    std::cout << "Creating a list of scores.";
    std::vector<int> scores;
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    std::cout << "\nHigh Scores\n";
    for (iter = scores.begin(); iter != scores.end(); ++iter) {
        std::cout << *iter << "\n";
    }

    std::cout << "\nFinding a score.";
    int score;
    std::cout << "\nEnter a score to find: ";
    std::cin >> score;
    iter = find(scores.begin(), scores.end(), score);                       //find() searches a vector through a specified range until it finds and returns an iterator referencing the first matching element(third argument). Will return an iterator at end of range if none is found.
    if (iter != scores.end()) {
        std::cout << "Score found.\n";
    }
    else {
        std::cout << "Score not found\n";
    }

    std::cout << "\nRandomizing scores.";
    srand(static_cast<unsigned int>(time(0)));                              //Seeding randomizer with time
    std::random_shuffle(scores.begin(), scores.end());                      //random_shuffle randomizes elements of a sequence with iterators (being score.begin/end here). Wont change anything, will just shuffle.
    std::cout << "\nHigh Scores: \n";
    for (iter = scores.begin(); iter != scores.end(); ++iter) {
        std::cout << *iter << "\n";
    }

    std::cout << "\nSorting Scores\n";
    std::sort(scores.begin(), scores.end());                                //Sort() sorts elements in a range in ascending order. Must use iterators aswell. Can be used on strings and other non-STL containers.
    std::cout << "\nHigh Scores: \n";
    for (iter = scores.begin(); iter != scores.end(); ++iter) {
        std::cout << *iter << "\n";
    }

    system("pause");
    return 0;
}