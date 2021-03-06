# include <stdio.h>
# include <malloc.h>

typedef struct BTNode {
	char data;
	struct BTNode * pLchild;
	struct BTNode * pRchild;
} BTNODE, * PBTNODE;

PBTNODE createBTree();

void preTraverseBTree(PBTNODE);

void inTraverseBTree(PBTNODE);

void postTraverseBTree(PBTNODE);

void main() {
	PBTNODE pT = createBTree();
	preTraverseBTree(pT);
	inTraverseBTree(pT);
	postTraverseBTree(pT);
}

PBTNODE createBTree(void) {
	PBTNODE pA = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pB = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pC = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pD = (PBTNODE)malloc(sizeof(BTNODE));
	PBTNODE pE = (PBTNODE)malloc(sizeof(BTNODE));

	pA->data = 'a';
	pB->data = 'b';
	pC->data = 'c';
	pD->data = 'd';
	pE->data = 'e';

	pA->pLchild = pB;
	pA->pRchild = pC;

	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}

void preTraverseBTree(PBTNODE pT) {
	// 先访问根，再先序访问左子树，再先序访问右子树
	if (NULL == pT) {
		return;
	}
	printf("%c\n", pT->data);
	if (NULL != pT->pLchild) {
		preTraverseBTree(pT->pLchild);
	}
	if (NULL != pT->pRchild) {
		preTraverseBTree(pT->pRchild);
	}
}

void inTraverseBTree(PBTNODE pT){
	// 先中序遍历左子树，再访问根，再中序访问右子树
	if (NULL == pT) {
		return;
	}
	if (NULL != pT->pLchild) {
		inTraverseBTree(pT->pLchild);
	}

	printf("%c\n", pT->data);
	
	if (NULL != pT->pRchild) {
		inTraverseBTree(pT->pRchild);
	}
}

void postTraverseBTree(PBTNODE pT){
	// 先后序遍历左子树，再后序访问右子树，再访问根
	if (NULL == pT) {
		return;
	}
	if (NULL != pT->pLchild) {
		postTraverseBTree(pT->pLchild);
	}

	if (NULL != pT->pRchild) {
		postTraverseBTree(pT->pRchild);
	}

	printf("%c\n", pT->data);
}
