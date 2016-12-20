/*************************************************************************
YOU'VE BEEN ASSIGNED A TEAM. YOUR TEAM MUST WORK TO COMPLETE THE REQUIRED
FUNCTIONALITY. MAKE SURE TO TEST IT IN THE MAIN!!!! AND TEST IT FULLY!

COME UP WITH A PLAN BEFORE YOU START CODING.
*************************************************************************/

#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
	public:
		char Data;
		TreeNode *Lchild;
		TreeNode *Rchild;
};

class BinaryTree
{
	public:
		TreeNode *Root;
	public:
		BinaryTree() {Root=NULL;}       //constructor
		void Preorder();
		void Inorder();
		void Postorder();
		void PreorderR(TreeNode*);
		void InorderR(TreeNode*);
        void PostorderR(TreeNode*);
        void InsertNode(char Val);

        //TEAM OAK
        TreeNode* Find_Node_Inorder(char D);

        //TEAM MAPLE
        TreeNode * TreeCopy(TreeNode *x);    //makes a copy of the linked binary tree. It should allocate the necessary nodes and copy the respective content to them.
        void Mirror(TreeNode* x);   //swaps left and right subtrees for all subtrees of the root x.

        //TEAM SEQUOIA
        int getTreeHeight(TreeNode *x); //returns the height of the tree
        int CountLeaves();  //returns the numbr of leaves in the tree
        int CountNodes();   //returns the number of nodes that are in the tree

        //TEAM COCONUT
        void DeleteNode(TreeNode* x);

        //TEAM PECAN
        void Mirror(TreeNode* x);   //swaps left and right subtrees for all subtrees of the root x.

        //TEAM ASPEN
        bool Are_Equal(BinaryTree other);   //compare the Binary Tree other to self. Return true if the same.
};

void BinaryTree::Preorder()
{
	TreeNode * Tmp=Root;
	stack<TreeNode*> S;
	while(1)
	{
		//traverse left until its NULL & push
		while(Tmp!=NULL)
		{
			cout << Tmp->Data;
			S.push(Tmp);
			Tmp=Tmp->Lchild;
		}

        //if stack is empty stop the process
		if(S.empty()) return;

		//if not empty, pop 1 and go right
		Tmp=S.top();
		S.pop();
		Tmp=Tmp->Rchild;
	}
}

void BinaryTree::Inorder()
{
	TreeNode * Tmp=Root;
	stack<TreeNode*> S;
	while(1)
	{
		//traverse left until its NULL & push
		while(Tmp!=NULL)
		{
			S.push(Tmp);
			Tmp=Tmp->Lchild;
		}
		//if stack is empty stop the process
		if(S.empty()) return;

		//if not empty, pop 1 and go right
		Tmp=S.top();
		S.pop();
		cout << Tmp->Data;
		Tmp=Tmp->Rchild;
	}
}

void BinaryTree::Postorder()
{
	TreeNode * Tmp=Root;
	stack<TreeNode*> S;		//stores nodes
	stack<char> F;	//stores flag
	char flag;	//’L’ or ‘R’
	while(1)
	{
		//traverse left until its NULL & push
		while(Tmp!=NULL)
		{
			S.push(Tmp);
			F.push('L');
			Tmp=Tmp->Lchild;
		}
		//if stack is empty stop the process
		if(S.empty()) return;
		else
		{
			Tmp=S.top();
			S.pop();		//pop node
			flag=F.top();
			F.pop();		//pop flag value
			if(flag=='R')
			{
				cout << Tmp->Data;
				Tmp=NULL;
			}
			else	//if flag is ‘L’
			{
				S.push(Tmp);
				F.push('R');   //push Tmp with ‘R’
				Tmp=Tmp->Rchild;	//move to right
			}
		}
	}
}

void BinaryTree::PreorderR(TreeNode*)
{
	if(Root!=NULL)
	{
		cout << Root->Data;
		PreorderR(Root->Lchild);
		PreorderR(Root->Rchild);
	}

}

void BinaryTree::InorderR(TreeNode*)
{
    if(Root!=NULL)
	{
		InorderR(Root->Lchild);
		cout << Root->Data;
		InorderR(Root->Rchild);
	}
}

void BinaryTree::PostorderR(TreeNode*)
{
    if(Root!=NULL)
	{
		PostorderR(Root->Lchild);
		PostorderR(Root->Rchild);
		cout << Root->Data;
	}

}

void BinaryTree::InsertNode(char Val)
{
	TreeNode *newNode,	// Pointer to a new node
	         *nodePtr;	// Pointer to traverse the tree

	// Create a new node
	newNode = new TreeNode;
	newNode->Data = Val;
	newNode->Lchild = newNode->Rchild = NULL;

	if (!Root)	// Is the tree empty?
		Root = newNode;
	else
	{
		nodePtr = Root;
		while (nodePtr != NULL)
		{
			if (Val < nodePtr->Data)
			{
				if (nodePtr->Lchild)
					nodePtr = nodePtr->Lchild;
				else
				{
					nodePtr->Lchild = newNode;
					break;
				}
			}
			else if (Val > nodePtr->Data)
			{
				if (nodePtr->Rchild)
					nodePtr = nodePtr->Rchild;
				else
				{
					nodePtr->Rchild = newNode;
					break;
				}
			}
			else
			{
				cout << "Duplicate value found in tree.\n";
				break;
			}
		}
	}
}
TreeNode* Find_Node_Inorder(char D){
  TreeNode * Tmp=Root;
	stack<TreeNode*> S;
	while(1)
	{
		//traverse left until its NULL & push
		while(Tmp!=NULL)
		{
			S.push(Tmp);
			Tmp=Tmp->Lchild;
		}
		//if stack is empty stop the process
		if(S.empty()) return NULL;

		//if not empty, pop 1 and go right
		Tmp=S.top();
		if(Tmp->Data == D){
            return Tmp;
		}
		S.pop();
		Tmp=Tmp->Rchild;
	}
	return NULL;

}
TreeNode * TreeCopy(TreeNode *x){
    TreeNode * temp;
    if(x->Lchild != NULL){
        temp->Lchild = TreeCopy(x->Lchild);
    }
    else if(x->Rchild != NULL){

        temp->Rchild = TreeCopy(x->Rchild);
    }
    else{
        return x;
    }
    return temp;


}


/************************************* MAIN FUNCTION *************************************/
int main()
{
    BinaryTree b;
    b.InsertNode('m');
    b.InsertNode('a');
    b.InsertNode('q');

    cout << "Postorder: ";
    b.Postorder();
    cout << endl;

    cout << "Inorder: ";
    b.Inorder();
    cout << endl;

    cout << "Preorder: ";
    b.Preorder();
    cout << endl;

    return 0;
}
