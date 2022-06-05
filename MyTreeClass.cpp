#ifndef MYTREECLASS_CPP
#define MYTREECLASS_CPP
#include"MyTreeClass.h"

MyTreeNode::MyTreeNode(int varintt, string varstrr) {
	this->varint = varintt;
	this->varstr = varstrr;
	this->pLeft = NULL;
	this->pOrigin = NULL;
	this->pRight = NULL;
}

bool MyTreeNode::setOrigin(MyTreeNode* pOri) {
	this->pOrigin = pOri;
	return true;
}

bool MyTreeNode::setKidNode(MyTreeNode* pKid) {
	if (this->pLeft == NULL) {
		this->pLeft = pKid;
	}
	else if (this->pLeft->varint <= pKid->varint) {
		this->pRight = pKid;
	}
	else {
		this->pRight = this->pLeft;
		this->pLeft = pKid;
	}
	return true;
}
bool MyTreeNode::bindOrigin(MyTreeNode* pOri) {
	this->setOrigin(pOri);
	pOri->setKidNode(this);
	return true;
}

int MyTreeNode::getVarint() {
	return this->varint;
}

string MyTreeNode::getVarstr() {
	return this->varstr;
}

MyTreeNode* MyTreeNode::getOrigin() {
	return this->pOrigin;
}

MyTreeNode* MyTreeNode::getLeft() {
	return this->pLeft;
}

MyTreeNode* MyTreeNode::getRight() {
	return this->pRight;
}

void MyTreeNode::setLeftNull() {
	this->pLeft = NULL;
}

void MyTreeNode::setRightNull() {
	this->pRight = NULL;
}
#endif