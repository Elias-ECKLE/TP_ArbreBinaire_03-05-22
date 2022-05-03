
#include "CTree.h"


CTree::CTree() {
	n_sizeTree = 0;
	n_depthTree = 0;
	p_racine = nullptr;
}

CTree::~CTree() {

}





//getters and getters computed
node* CTree::GetRacine() {
	return this->p_racine;
}
int CTree::GetDepth(node* p_node) {

	if (p_node==nullptr) {
		return 0;
	}
	else {

		int n_h_sLeft = GetDepth(p_node->p_sLeft);
		int n_h_sRight = GetDepth(p_node->p_sRight);
		return 1 + (n_h_sLeft > n_h_sRight) ? n_h_sLeft : n_h_sRight;
	}
}



/*
int CTree::GetNbOfNodes(rootSystem root) {
	int n_nbOfNodes = 0;

	RootPrefix(this->p_racine, featureTree::getSize);


	return n_nbOfNodes;

}*/


int CTree::GetSizeOfTree() {

	return n_sizeTree;
}


//edit tree : add/remove, place
void CTree::PutInTree(node* p_node) {

	node* p_current = p_racine;
	node* p_prcdt = nullptr;


	//if the tree is empty then we put just the node in p_racine and we out of the fct
	if (this->p_racine == nullptr) {
		this->p_racine = p_node;

		return;
	}

	//we root the tree and we stock every time the precedent node in p_prcdt
	while (p_current != nullptr) {

		p_prcdt = p_current;
		if (p_node->n_value < p_current->n_value) {
			p_current = p_current->p_sLeft;
		}
		else {
			p_current = p_current->p_sRight;
		}
	}

	//we add p_node in fille g ou d du p_prcdt
	if (p_node->n_value < p_prcdt->n_value) {
		p_prcdt->p_sLeft = p_node;
	}
	else {
		p_prcdt->p_sRight = p_node;
	}


}

void CTree::AddNode(int n_value) {

	node* p_node = new node;
	p_node->n_value = n_value;

	p_node->p_sRight = nullptr;
	p_node->p_sLeft = nullptr;

	PutInTree(p_node);

	this->n_sizeTree++;

}

void CTree::RemoveNode(node* p_node) {

	this->n_sizeTree--;

	node* p_current = this->p_racine;

	//dans le cas ou on supprime la racine 
	if (p_node == p_current) {

		p_racine = p_node->p_sRight;
		if (p_node->p_sLeft) PutInTree(p_node->p_sLeft);
		delete p_node;
		return;
	}

	//dans les autres cas, on parcoure jusqu'à trouver le node que l'on veut suppr
	while (p_current != nullptr) {
		if (p_current->p_sRight == p_node || p_current->p_sLeft == p_node)
			break;

		if (p_node->n_value < p_current->n_value)
			p_current = p_current->p_sLeft;
		else
			p_current = p_current->p_sRight;
	}

	if (p_current->p_sRight == p_node)
		p_current->p_sRight = p_node->p_sRight;
	else
		p_current->p_sLeft = p_node->p_sRight;

	// Et puis on replace l'autre fils du noeud disparu
	if (p_node->p_sLeft) PutInTree(p_node->p_sLeft);


	delete p_node;


}


//balance and modification structure


//research and  display
node* CTree::Research(int n_value) {

	node* p_current = p_racine;

	//we search the first node with the same value
	while (p_current) {
		if (n_value == p_current->n_value)
			return p_current;
		else if (n_value < p_current->n_value)
			p_current = p_current->p_sLeft;
		else
			p_current = p_current->p_sRight;
	}

	return nullptr;

}




//root tree
void CTree::RootPrefix(node* p_node) {

	if (p_node != nullptr) {
		cout << p_node->n_value << endl;
		RootPrefix(p_node->p_sLeft);
		RootPrefix(p_node->p_sRight);
	}


}

void CTree::RootPostfix(node* p_node) {
	if (p_node != nullptr) {

		RootPrefix(p_node->p_sLeft);
		RootPrefix(p_node->p_sRight);
		cout << p_node->n_value << endl;

	}
}
/*void CTree::RootInfix(node* p_node, featureTree feature) {
	RootInfix(p_node->p_sLeft, feature);


	if (p_node != nullptr) {

		switch (feature) {
		case featureTree::getSize:
			this->n_sizeTree++;
			break;
		case featureTree::display:
			cout << p_node->n_value << endl;
			break;
		}
	}

	RootInfix(p_node->p_sRight, feature);
}*/



void CTree::DisplayTree(rootSystem root) {
	switch (root) {
	case rootSystem::rootPrefix:
		RootPrefix(this->p_racine);
		break;
	case rootSystem::rootPostfix:
		RootPostfix(this->p_racine);
		break;
	/*case rootSystem::rootInfix:
		RootInfix(this->p_racine, featureTree::display);*/
	default:
		cout <<"problème, veuillez relancer le programme" << endl;
		break;
	}

}


