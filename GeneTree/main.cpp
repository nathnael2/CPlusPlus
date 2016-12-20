#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>
#include "GeneTree.h"
#include <string>

using namespace std;

/*class myTreeNode
{
	public:
		char Data;
		myTreeNode *childA;   //A's always go in child1
		myTreeNode *childT;   //T's always go in child2
		myTreeNode *childC;   //c's always go in child3
		myTreeNode *childG;   //G's always go in child4
};*/

bool get_words_from_the_file(char * my_file_name, vector<string> &vector_of_words);
bool get_the_reads_from_file(char * my_file_name, vector<string> &reads);
bool write_out_the_vector_to_screen(vector<string> my_vector);
bool write_out_the_vector_to_file(vector<string> my_vector, char * my_file_name);

int main()
{
    vector<string> words_in_genome;
    char * genome_file_name="my_genome.txt";          //make certain to place this file in the correct folder. Do not change path.
    if(!get_words_from_the_file(genome_file_name,words_in_genome))
        return 1;

    //1. Create a tree based on myTreeNode --> transforming the vector of words into the tree
    //2. Read in file reads using function get_the_reads_from_file
    vector<string> reads_to_be_tested;

    char * reads_file_name="reads.txt";
    cout<<"It works";             //make certain to place this file in the correct folder. Do not change path.
    if(!get_the_reads_from_file(reads_file_name,reads_to_be_tested))
        return 1;

    //3. for each read, map it through the tree. If it follows a path in the tree, this read belongs to this genome.
    //Write out a file named "myResults.txt".
    //For each read, list its sequence and either "Yes" or "No".
    //This will indicate if it does or doesn't map to the genome.

    //make sure you have included the right files
    //make sure you delete the memory!


    GeneTree T;

    T.createTree(words_in_genome);


   // vector<bool> virus_or_not;//this vector holds the result of weather each read is a virus or not. It is related to the read by the indices of the two vectors

    //checks to see if each word in read is a virus or not and saves the result in the vector virus_or_not
   /* for(int i = 0;i < reads_to_be_tested.size();i++){
        virus_or_not.push_back(T.wordExists(reads_to_be_tested.at(i),T.root));
    }


    ofstream out;
    out.open("myResults.txt");
    //writes out the result of each read in the required format
    for(int i = 0; i < virus_or_not.size();i++){
        string text;
        if(virus_or_not.at(i) == true){
            text = "Yes";

        }
        else{
            text = "No";
        }
        out<<reads_to_be_tested.at(i) + "--->" + text<<endl;
    }

    */
    /** these function calls are here so that you can check that you are reading and writing correctly.
    REMOVE once you have tested
        cout << "words" << endl;
        write_vector_to_screen(words);
        write_vector_to_file(words,"testing.txt");
        cout << "reads" << endl;
        write_vector_to_screen(reads);
 ***/
}


/*******************************************************************************
This function takes the genome file's name
that it will read in. It will then read all of the overlapping
words of size 10 that are present in the file.
Each word it reads will then be stored in a vector.
The vector is passed to this function as a parameter -- by reference.
Doing so will allow the calling function has access to the vector of words.
*******************************************************************************/
bool get_words_from_the_file(char * my_file_name, vector<string> &vector_of_words)
{
    int i,j;
    int len=0;
    ifstream in;
    in.open(my_file_name);
    if(!in.is_open())
    {
        cout << "I could not find " << my_file_name << endl;
        cout << "Check the location.\n";
        return false;
    }

    char * my_word=new char [11];                              //this is a default, we'll be looking at words of size 10
    while(in.peek()!=EOF) {in>>my_word[0]; len++;}             //gets the length of the sequence
    in.clear(); in.close(); in.open(my_file_name);             //have to close and reopen file to reset filestream to beginning of file

    for(i=0; i<10; i++)
    {
        in>> my_word[i];
        if(my_word[i]<97) my_word[i]+=32;     //makes it lowercase
    }
    my_word[10]='\0';
    vector_of_words.push_back(my_word);

    for(i=1; i<(len-10-1); i++)   //read until the end of the file
    {
        //shift
        for(j=0; j<9; j++) my_word[j]=my_word[j+1];
        in>> my_word[9];
        if(my_word[9]<97) my_word[9]+=32;     //makes it lowercase
        my_word[10]='\0';
        //cout << i << "\t" << my_word << endl; cout.flush();
        vector_of_words.push_back(my_word);
    }
    in.clear(); in.close();

    return true;
}

/*******************************************************************************
This function takes the reads file name to read and reads each individual word
in the file and stores each word in a vector.
The vector is passed to this function as a parameter -- by reference such
that the calling function has access to the vector of words.
*******************************************************************************/
bool get_the_reads_from_file(char * my_file_name, vector<string> &reads)
{
    int i;
    ifstream in;
    in.open(my_file_name);
    if(!in.is_open())
    {
        cout << "The read file " << my_file_name << " could not be opened.\nCheck the location.\n";
        return false;
    }

    char * word=new char [20];                              //this is a default, we'll be looking at words of size 10

    while(in.peek()!=EOF)
    {
        in.getline(word,20,'\n');
        for(i=0; i<10; i++) {if(word[i]<97) word[i]+=32;}     //makes it lowercase
        reads.push_back(word);
    }
    in.clear(); in.close();
    delete word;
    return true;
}

/*******************************************************************************
This function writes out the vector of words to the screen. Written here to help
you with debugging.
*******************************************************************************/
bool write_out_the_vector_to_screen(vector<string> my_vector)
{
    int i;
    for(i=0; i<my_vector.size(); i++)
        cout << my_vector[i] << endl;
    return true;
}

/*******************************************************************************
This function writes out the vector of words to file.
*******************************************************************************/
bool write_out_the_vector_to_file(vector<string> my_vector, char * my_file_name)
{
    ofstream out;
    out.open(my_file_name);
    int i;
    for(i=0; i<my_vector.size(); i++)
        out << my_vector[i] << endl;
    out.clear();
    out.close();
    return true;
}
