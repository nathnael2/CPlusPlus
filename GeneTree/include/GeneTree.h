#ifndef GENETREE_H
#define GENETREE_H
#include <vector>
#include <cstring>
//#include "myTreeNode.h"
#include <string>

using namespace std;

class myTreeNode
{
public:
    char data;
    myTreeNode* childA;
    myTreeNode* childT;
    myTreeNode* childC;
    myTreeNode* childG;
public:
    myTreeNode(){};
};

class GeneTree
{
public:
    myTreeNode *root;

public:
    GeneTree(){};
    void createTree(vector<string> & words);
    bool wordExists(string word, myTreeNode *x);
private:
    myTreeNode* addWordToTree(string word, myTreeNode * x);
};


#endif // GENETREE_H
