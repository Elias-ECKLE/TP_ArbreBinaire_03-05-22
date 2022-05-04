#include "CTree.h"


int main() {

	CTree tree;
	tree.AddNode(4);
	tree.AddNode(3);
	tree.AddNode(12);
	tree.AddNode(5);
	tree.AddNode(20);
	tree.AddNode(1);
	tree.AddNode(10);
	tree.AddNode(25);
	tree.AddNode(100);



	//node* p_node = tree.Research(4);
	//tree.RemoveNode(p_node);

	cout << "-----------------------------Display by prefix root-----------------------------------" << endl;
	tree.DisplayTree(rootSystem::rootPrefix);

	cout << "-----------------------------Display by postfix root-----------------------------------" << endl << endl;
	tree.DisplayTree(rootSystem::rootPostfix);


	 
	cout << endl <<"Size of tree : " << tree.GetSizeOfTree() << endl;
	int depth = tree.GetDepth(tree.GetRacine());
	cout << "Depth of tree : " << depth << endl;

	tree.IsBalanced();
	//tree.BalanceTree(); //problem of infiny loop





	return 0;
}


//TACHES A FAIRE--------------------------
// 
//libérer mémoire 
//voir pour depth 