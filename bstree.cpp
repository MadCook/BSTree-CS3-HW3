#include "bstree.h"
#include <iostream> 
#include <string> 

 using namespace std ; 

TreeNode::TreeNode(){
    ptrLeft = NULL;
	ptrRight = NULL;
}

TreeNode::TreeNode(string s){
	word = s;
	ptrLeft = NULL;
	ptrRight = NULL;
}

BSTree::BSTree(){
	root = NULL;
}

//Call the recursive function to count how many nodes are in your tree
int BSTree::Size(){
	return sizeCount(root);
}

//Recursively run through the tree count each node only the first time you touch it
int BSTree::sizeCount(TreeNodeptr node, int &count){
	if(root==NULL) return 0;
	else if(root==node) count =1;
	
	if(root->ptrLeft !=NULL){
		sizeCount(root->ptrLeft, count+1);
	}
	
	if(root->ptrRight !=NULL){
		sizeCount(root->ptrRight, count+1);
	}
	
	return count;	
}


void BSTree::Insert(string s){
	if(root == NULL){
		TreeNodeptr insert = new TreeNode(s);
		root = insert;
	}
	else{
		TreeNodeptr currentLoc = root;
		while(currentLoc != NULL){
			if(currentLoc->word == s)
				break;
			if(currentLoc->word > s){
				if(currentLoc->ptrLeft != NULL)
				 currentLoc = currentLoc->ptrLeft;
				else{
				 TreeNodeptr insert = new TreeNode(s);
				 currentLoc->ptrLeft = insert;
				 break;
				}
			}
			else{
				if(currentLoc->ptrRight != NULL)
				 currentLoc = currentLoc->ptrRight;
				else{
				 TreeNodeptr insert = new TreeNode(s);
				 currentLoc->ptrRight = insert;
				 break;
				}
			}	
		}
	}
}

bool BSTree::Find (string s){
	TreeNodeptr currentLoc = root;
	while(currentLoc !=NULL){
		if(currentLoc->word == s){
			return true;
		}
		else if(currentLoc->word > s){
			currentLoc = currentLoc->ptrLeft;
		}
		else if(currentLoc->word < s){
			currentLoc = currentLoc->ptrRight;
		}
	}
	return false;
}







