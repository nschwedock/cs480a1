#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

#include "dicttree.h"

#define NUM_ARGUMENTS 2

using namespace std;

const char *delimiters = "\n\r !\"#$%&()*+,-./0123456789:;<=>?@[\\]^_`{|}~";

int main(int argc, char **argv){

    Trie trie = Trie();



    string dictfile;
    string testFile;

    ifstream inFile;

    string word;

    //if both files are included in the arguments, run the program
    if (argc > NUM_ARGUMENTS){
        dictfile = argv[1];
        testFile = argv[2];

        //open the dictionary file.  If it doesn't open properly, give an errorCode
        inFile.open(dictfile);
        if (!inFile){
            cerr << "unable to open dictionary file " << endl;
            exit(1);
        }
        while (!inFile.eof()){
            inFile >> word;
            //add each new word to the dictionary tree
            trie.addWord(word);
        }

        inFile.close();


        //open the test file.  If it doesn't open properly, give an errorCode
        inFile.open(testFile);
        if (!inFile){
            cerr << "unable to open test file " << endl;
            exit(1);
        }

        inFile.close();

        string line;
        char *words;

        ifstream input_file(testFile);

        //read in line by line
        while (getline(input_file, line)){
            char *line_c = new char[line.length() + 1];
            strcpy(line_c, line.c_str());
            //tokenize each line into each word
            words = strtok(line_c, delimiters);
            while (words != nullptr){
                //counts each word and spits it out
                int num_count = trie.countWords(trie.findEndingNode(std::string(words)));
                cout << words << " " << num_count << endl;
                words = strtok(NULL, delimiters);
            }
        }

        input_file.close();

    }
    else{
        //incorrect number of arguments given
        cout << "Incorrect number of arguments given" << endl;
    }

    return 0;
}