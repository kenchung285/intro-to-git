#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
using namespace std;


int main(){
    char sentence[] = "This is a sentence with 7 tokens";
    char *tokenPtr;
    cout << "The string to be tokenized is:\n" << sentence << "\n\nThe tokens are:\n\n";
    tokenPtr = strtok(sentence, " ");
    cout << strlen(sentence);
}
