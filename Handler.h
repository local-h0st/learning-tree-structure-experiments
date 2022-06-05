#ifndef HANDLER_H
#define HANDLER_H
#include "MyTreeClass.h"
class Handler {
public:
	Handler(MyTreeNode* root);
	void movTop();	//success
	void movLeft();	//success
	void movRight();//success
	bool giveMeANewNode(int varintt, string varstrr);	//success
	int getDepth();	//success
	void getMe();	//success
	void backToRoot();//success
	void deleteFromThisNode();
	void deleteAllExceptForRoot();
	bool checkIfTheKidNodesAreBothNULL();
	bool deleteCurrentNode();	//不要随意使用！！仅当currentPos在最末一层或者倒数第二层才能用！定义它只是为了辅助deleteAll（）函数而已
	void moveToOneBottomNode();	//WRONG!!!!!!!!!!也作为辅助函数
	void printTreeInAnUglyForm();
private:
	int depth;
	MyTreeNode* rootPos;
	MyTreeNode* currentPos;
	MyTreeNode* previousPos;
};

#endif