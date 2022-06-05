#ifndef HANDLER_CPP
#define HANDLER_CPP
#include"Handler.h"

Handler::Handler(MyTreeNode* root) {
	this->rootPos = root;
	this->currentPos = root;
	this->previousPos = NULL;
	this->depth = 0;
}

void Handler::movTop() {
	this->previousPos = this->currentPos;
	this->currentPos = this->currentPos->getOrigin();
	--this->depth;
}

void Handler::movLeft() {
	this->previousPos = this->currentPos;
	this->currentPos = this->currentPos->getLeft();
	++this->depth;
}
void Handler::movRight() {
	this->previousPos = this->currentPos;
	this->currentPos = this->currentPos->getRight();
	++this->depth;
}

bool Handler::giveMeANewNode(int varintt, string varstrr) {
	MyTreeNode* p = new MyTreeNode(varintt, varstrr);
	p->bindOrigin(currentPos);
	return true;
}

int Handler::getDepth() {
	return this->depth;
}

void Handler::getMe() {
	cout << "## Depth : " << this->depth << " | Integer : " << this->currentPos->getVarint() << " | Content : " << this->currentPos->getVarstr() << " ##" << endl;
}

bool Handler::deleteCurrentNode() {
	if (!this->checkIfTheKidNodesAreBothNULL())
		return false;
	cout << "Now Deleting : " << endl;
	this->getMe();
	this->movTop();
	if (this->previousPos == this->currentPos->getLeft())
		this->currentPos->setLeftNull();
	else
		this->currentPos->setRightNull();
	delete this->previousPos;
	this->previousPos = NULL;
	cout << "Deleted successfullyyyyyyyy!" << endl;
	return true;
}

void Handler::backToRoot() {
	while (this->currentPos != this->rootPos) {
		this->movTop();
	}
}

void Handler::moveToOneBottomNode() {
	while (this->currentPos->getLeft() != NULL || this->currentPos->getRight() != NULL) {
		if (this->currentPos->getLeft() == NULL)
			this->movRight();
		else
			this->movLeft();
	}
}

bool Handler::checkIfTheKidNodesAreBothNULL() {
	if (this->currentPos->getLeft() == NULL && this->currentPos->getLeft() == NULL)
		return true;
	else
		return false;
}

void Handler::deleteFromThisNode() {
	MyTreeNode* pos = this->currentPos;
	this->previousPos = NULL;
	this->moveToOneBottomNode();
	while (this->currentPos != pos) {
		this->deleteCurrentNode();
		this->moveToOneBottomNode();
	}
}

void Handler::deleteAllExceptForRoot() {
	this->backToRoot();
	this->deleteFromThisNode();
}

void Handler::printTreeInAnUglyForm() {
	this->currentPos = this->rootPos;
	//////////remain to be continued...
}


#endif