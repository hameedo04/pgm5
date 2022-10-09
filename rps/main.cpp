//
//  main.cpp
//
//
//  Created by Muhammad Reed on 10/9/22.
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
using namespace std;

int main() {
    
    ifstream inFS;
    const int MAX_BOOKS = 25;
    string name[MAX_BOOKS];
    int readerNum = 0;
    int numBooks[MAX_BOOKS];
    int i;
    int totalBooks = 0;
    int mostBooks;
    int leastBooks;
    int neutralBooks;
    string topReader;
    int topReaderNum;
    string lowestReader;
    int lowestReaderNum;
    
    inFS.open("pgm5.txt");
    while (!inFS.eof() && readerNum <= MAX_BOOKS) {
        inFS >> name[readerNum];
        inFS >> numBooks[readerNum];
        ++readerNum;
        if (numBooks[readerNum] < 0) {
            numBooks[readerNum] = numBooks[readerNum] * -1;
        }
    }
    
        int max = numBooks[0];
        int min = numBooks[0];
    
    for (int i = 0; i < MAX_BOOKS; ++i) {
        totalBooks += numBooks[i];
        if (numBooks[i] > max) {
            mostBooks = numBooks[i];
            topReader = name[i];
            topReaderNum = i + 1;
        }
        if (numBooks[i] < min) {
            leastBooks = numBooks[i];
            lowestReader = name[i];;
            lowestReaderNum = i + 1;
        }
    }
    for (int i = 0; i < readerNum; ++i) {
        cout << "Reader " << i + 1 << " who is named " << name[i] << " read " << numBooks[i] << " books." << endl;
    }
    
    cout << "The winner is Reader " << topReaderNum << " who is named " << topReader << " by reading " << mostBooks << " books." << endl;
    cout << "Reader " << lowestReaderNum << " who is named " << lowestReader << " read the least number of books: " << leastBooks << "." << endl;
    cout << "And in total all readers read " << totalBooks << " books." << endl;

    inFS.close();
    
    
    return 0;
}
