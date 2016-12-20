#include "GeneTree.h"
#include <iostream>
#include <stack>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <stdlib.h>


using namespace std;

//GeneTree::GeneTree()
//{
    /*root->data = 'e';
    root->childA = NULL;
    root->childC = NULL;
    root->childG = NULL;
    root->childT = NULL;*/
//}


//This method will add the word provided as a parameter to the tree
myTreeNode* GeneTree::addWordToTree(string word, myTreeNode* x)
{
    cout<<word.size()<<endl;
    if(word.size()==0){
            cout<<"NULL"<<endl;
        return x;

    }
    else{
        char gene = word[0];
        myTreeNode* temp;
        temp->data = gene;
        string newWord = word.substr(1,word.size()-1);
        if(gene == 'A' || gene == 'a'){
            cout<<"A1"<<endl;
            x->childA = addWordToTree(newWord,temp);
            x=x->childA;
            cout<<"A2"<<endl;
        }
        else if(gene == 'T' || gene == 't'){
            cout<<"T1"<<endl;
            x->childT = addWordToTree(newWord,temp);
            x=x->childT;
            cout<<"T2"<<endl;

        }
        else if(gene == 'C' || gene == 'c'){
            cout<<"C1"<<endl;
            x->childC = addWordToTree(newWord,temp);
            x=x->childC;
            cout<<"C2"<<endl;

        }
        else{
            cout<<"G"<<endl;

            x->childG = addWordToTree(newWord,temp);
            x=x->childG;
            cout<<"G2"<<endl;

        }
    }
    return x;


}
//this method will create a tree out of the list of words by making use of the addWordToTree method above
void GeneTree::createTree(vector<string> & words)
{

    for(int i=0;i<words.size();i++){

        addWordToTree(words.at(i),root);
        cout<<"gotcha";

    }

}
//this method will check if the word provided as a parameter exists in the tree
bool GeneTree::wordExists(string word, myTreeNode* x)
{
    if(word.size() == 0){
        return true;
    }
    else{
        char character = word[0];
        if(x->childA->data == character){
            return wordExists(word.substr(1,word.size()-1),x->childA);
        }
        else if(x->childC->data == character){
            return wordExists(word.substr(1,word.size()-1),x->childC);

        }
        else if(x->childG->data == character){
            return wordExists(word.substr(1,word.size()-1),x->childG);

        }
        else if(x->childT->data == character){
            return wordExists(word.substr(1,word.size()-1),x->childT);
        }
    }
    return false;

}


