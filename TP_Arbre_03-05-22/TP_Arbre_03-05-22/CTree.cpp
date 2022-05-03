
#include "CTree.h"


CTree::CTree() {
	n_sizeTree = 0;
	n_depthTree = 0;
	p_racine = nullptr;
}

CTree::CTree(node* p_node) {
	n_sizeTree = 1;
	n_depthTree = 0;
	p_racine = p_node;
}
CTree::~CTree() {

}





//getters and getters computed
node* CTree::GetRacine() {
	return this->p_racine;
}
int CTree::GetNbOfNodes(node* p_node) {
	if (p_node != nullptr) {
		//we recup somme nodes retourned each call function + 1 to increment 
		return 1 + GetNbOfNodes(p_node->p_sLeft) + GetNbOfNodes(p_node->p_sRight);
	}

	return 0;

}
int CTree::CalculDepth(node* p_node) {

	//we compare the length bewteen son branch (height) and the most big is considered as the height max/dept of tree
	if (p_node!=nullptr) {

		int n_h_sLeft = CalculDepth(p_node->p_sLeft);
		int n_h_sRight = CalculDepth(p_node->p_sRight);
		return 1 + ((n_h_sLeft > n_h_sRight) ? n_h_sLeft : n_h_sRight);
	}


	return 0;
}
int CTree::GetDepth(node* p_node) {
	return CalculDepth(p_node) - 1;
}



/*
int CTree::GetNbOfNodes(rootSystem root) {
	int n_nbOfNodes = 0;

	RootPrefix(this->p_racine, featureTree::getSize);


	return n_nbOfNodes;

}*/
int CTree::GetSizeOfTree() {

	this->n_sizeTree = GetNbOfNodes(this->p_racine);
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

}
void CTree::RemoveNode(node* p_node) {

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
bool CTree::IsBalanced() {

	node* p_current = this->p_racine;

	if (this->p_racine != nullptr) {
		//Balance perfect 
	// we seek the number of nodes in sous-tree left and sous-tree right
		int n_nbNodes_Left = GetNbOfNodes(p_current->p_sLeft);
		int n_nbNodes_Right = GetNbOfNodes(p_current->p_sRight);
		cout << endl<<"nb nodes left sous tree : " << n_nbNodes_Left << "  /  " << "nb nodes right sous tree : " << n_nbNodes_Right << endl;

		// |nbNodes_Left - nbNodesRight| <= 1 : formule to know if tree is perfectly balanced
		if (abs(n_nbNodes_Left - n_nbNodes_Right) <= 1) {
			cout << "The tree is perfectly balanced" <<endl;
			return true;
		}
		else {
			// hNodes_Left - hNodesRight| <= 1 : formule to know if tree is more or less balanced
			int n_Depth_Left = GetDepth(p_current->p_sLeft);
			int n_Depth_Right = GetDepth(p_current->p_sRight);
			cout << "depth left sous tree : " << n_Depth_Left << "  /   " << "depth right sous tree : " << n_Depth_Right << endl;

			if (abs(n_Depth_Left - n_Depth_Right) <= 1) {
				cout << "The tree is more or less balanced" << endl;
				return true;
			}
		}
	}
	
	cout << "The tree is not balanced!" << endl;
	return false;
}

void CTree::BalanceTree() {

	
	if (!IsBalanced()) {
		cout << "Balance required!" << endl;
		cout << "Balance finished!" << endl;
	}
	
	cout << "The tree is already balanced" << endl;
}



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


