#pragma once
#include <iostream>
using namespace std;

#include "SNode.h"
#include "ERootSystem.h"
#include "EFeatureTree.h"


class CTree {

	int n_sizeTree;
	int n_depthTree;
	node* p_racine;

	//root system of tree
	void RootPrefix(node* p_node); 
	void RootPostfix(node* p_node);
	void RootInfix(node* p_node);

public:
	CTree();
	CTree(node* p_node);
	~CTree();


	//getters
	node* GetRacine();
	int CalculDepth(node* p_node);
	int GetDepth(node* p_node);
	int GetNbOfNodes(node*);
	//int GetNbOfSheetNodes(rootSystem);
	int GetSizeOfTree();

	//Edit : add, remove node tree
	void PutInTree(node* p_node);
	void AddNode(int n_value);
	void RemoveNode(node* p_node);
	//void DeleteTree();


	bool IsBalanced();
	void BalanceTree();

	//display tree, research of several possibilities with rootprefix/rootpostfix
	node* Research(int n_value);
	void DisplayTree(rootSystem root); 


};