//Nathnael Alemu



#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <stdlib.h>
using namespace std;


int get_hash_code(string key);
int quadratic_probing_insert(string *& hash_table, string key, int max_size, int quadratic_counter);

//this method returns the hash code of the provided key
int get_hash_code(string key)
{
    string firstletter(1,key[3]);
    string secondletter(1,key[5]);
    string thirdletter(1,key[7]);
    string fourthletter(1,key[8]);



    string key1 = firstletter + secondletter + thirdletter + fourthletter;
    stringstream str(key1);
    int key2;//integer format of the hash code
    str>>key2;
    return key2;
}

//this method uses quadratic probing in order to insert the provided key into the hash table
int quadratic_probing_insert(string *& hash_table, string key, int max_size, int quadratic_counter)
{

    int hashed_key = get_hash_code(key); //get the hash code of the key
    if(hash_table[hashed_key] == "-2"){ // put the key into the hash table at the hashed_key index if it is empty
        hash_table[hashed_key] = key;
        return hashed_key;
    }
    else{
        //this method resolves any collision that might occur using quadratic probing if the original hashcode is occup
        int quadratic_shift = quadratic_counter;
        int i = (hashed_key + quadratic_shift)%max_size;
        bool overflown = true;
        while(i != hashed_key && quadratic_shift < (max_size*max_size)/4){
            if(hash_table[i] == "-2"){
                overflown = false;
                hash_table[i] = key;
                return i;
            }
            quadratic_shift = (quadratic_shift+1)*(quadratic_shift +1);
            i = (hashed_key + quadratic_shift)%max_size;

        }
        //the hash table is overflown
        if(overflown){
           return -1;
        }

    }
}


int main()
{
    ifstream in;
    ofstream out;

    in.open ("everybodys_socials.txt");
    string line;
    vector <string> numbers;

    //read in all of the social security numbers from the file
    while (!in.eof () )
    {
        getline(in,line,',');
        numbers.push_back(line);

    }



    int max_size = numbers.size();
    int quadratic_counter;
    cout<<"Please provide the a number between 1 and 450 million: ";
    cin>>quadratic_counter;
    string* hash_table= new string [max_size];//set up hash table


    //initialize all values to -2 which indicates that the hash table is empty
    for(int i=0;i<max_size;i++)
        hash_table[i]="-2";


    //hash each number in the vector
    for(int i=0;i<numbers.size();i++)
    {
        quadratic_probing_insert(hash_table,numbers.at(i),max_size,i);
    }


    //write out the contents of the hash table into a new file
    out.open("hashed_socials.txt");
    out<<hash_table[0];
    for (int j = 1 ; j < max_size; j++)
    {
        out<<", "<<hash_table[j];

    }


    in.close ();
    out.close();
    delete[] hash_table;
}
