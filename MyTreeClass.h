#ifndef MYTREECLASS_H
#define MYTREECLASS_H
#include<string>
using namespace std;

class MyTreeNode {
public:
	MyTreeNode(int varintt, string varstrr);
	bool bindOrigin(MyTreeNode* pOri);//应该是双向绑定，也就是第一，指定自己的pOrigin，第二，在OriginNode中指定该节点为pLeft或者pRight,默认指定为左
	bool setOrigin(MyTreeNode* pOri);
	bool setKidNode(MyTreeNode* pKid);
	MyTreeNode* getOrigin();
	MyTreeNode* getLeft();
	MyTreeNode* getRight();
	void setLeftNull();
	void setRightNull();
	int getVarint();
	string getVarstr();
private:
	int varint;
	string varstr;
	MyTreeNode* pOrigin;
	MyTreeNode* pLeft;
	MyTreeNode* pRight;
};

#endif
