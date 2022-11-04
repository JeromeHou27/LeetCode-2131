#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct Counter {
    int plusCount = 0;
    int minusCount = 0;
};

int longestPalindrome(vector<string>& words) {
    const char alphabetCount = 'z' - 'a' + 1;
    Counter* wordsArray[alphabetCount];

    for (char i = 0; i < alphabetCount; ++i) {
        wordsArray[i] = new Counter[alphabetCount - i];
    }

    for (string& word : words) {
        if (word[1] < word[0]) {
            wordsArray[word[1] - 'a'][word[0] - word[1]].minusCount++;
        }
        else {
            wordsArray[word[0] - 'a'][word[1] - word[0]].plusCount++;
        }
    }

    bool centerWord = false;
    int worldCount = 0;
    char secOffset = 0;
    for (char i = 0; i < alphabetCount; ++i) {
        secOffset = alphabetCount - i;

        worldCount += wordsArray[i][0].plusCount / 2;
        if (!centerWord)
            centerWord = wordsArray[i][0].plusCount % 2 == 1;

        for (char j = 1; j < secOffset; ++j) {
            worldCount += wordsArray[i][j].plusCount > wordsArray[i][j].minusCount ? wordsArray[i][j].minusCount : wordsArray[i][j].plusCount;
        }
    }

    return (worldCount * 2 + (centerWord ? 1 : 0)) * 2;
}

int main()
{
    vector<string> words = { "tw","az","fb" };

    printf("%d\n", longestPalindrome(words));
}

