#include <iostream>
#include<vector>
#include "MyTreeClass.cpp"
#include "Handler.cpp"

bool generateAFullTree(MyTreeNode* pRoot,int depth,int mode = 0) {
    //mode=0则默认为生成的所有节点全部置空（虽然我也不知道置空有什么用）
    //如果指定mode=1则是随机填充数据
    //如果指定mode=2则是按一定规律填充数据（按一定的规律固定生成一棵树）
    return true;
}


int main()
{
    MyTreeNode rootNode(16, "This tree is created by PureLov3 and this is the root node!");
    Handler handle(&rootNode);
    handle.getMe();
    handle.giveMeANewNode(4810, "Montblanc 146");
    handle.giveMeANewNode(1947, "WingSung 629");
    handle.movLeft();
    handle.getMe(); //1947{1 Root}
    handle.movTop();
    handle.movRight();
    handle.getMe(); //4810{1 Root}
    handle.giveMeANewNode(585, "This is the kid of 4810");
    handle.movLeft();
    handle.getMe(); //585{2 Root 4810}
    handle.backToRoot();
    //Now root
    handle.movLeft();//mov to 1947{1 Root}
    handle.giveMeANewNode(100, "Hero 100 and this is the kid of 629");
    handle.movLeft();
    handle.getMe();//100{2 Root 1947}
    handle.backToRoot();

    cout << "########### Calling for deleteAllExceptForRoot() : " << endl;
    handle.deleteAllExceptForRoot();
    if (handle.checkIfTheKidNodesAreBothNULL()) {
        cout << "Deleted successfully!" << endl;
    }
    else {
        cout << "Oops!Deletion Failed" << endl;
    }



    /*
    cout << endl;
    cout << "########### CurrentPos : " << endl;
    handle.getMe();//root
    cout << "########### Calling for moveToOneBottomNode() and currentPos is : " << endl;
    handle.moveToOneBottomNode();
    handle.getMe();//100{2 Root 629}
    cout << "########### Calling for deleteCurrentNode() : " << endl;
    handle.deleteCurrentNode();//100 deleted
    cout << "########### CurrentPos : " << endl;
    handle.getMe();//1947{1 Root}
    cout << "Checking if the two kid-nodes of are both NULL : " << endl;
    if (handle.checkIfTheKidNodesAreBothNULL()) {
        cout << "Both null" << endl;
    }
    else {
        cout << "At least one is not null" << endl;
    }//1947 become a buttom node , but the previousPos is set to be null so we just cannot find the top of 1947

    handle.backToRoot();
    cout << "########### CurrentPos : " << endl;
    handle.getMe();//root
    cout << "########### Calling for moveToOneBottomNode() and currentPos is : " << endl;
    handle.moveToOneBottomNode();
    handle.getMe();//1947{1 root}
    cout << "########### Calling for deleteCurrentNode() : " << endl;
    handle.deleteCurrentNode();//1947 deleted
    cout << "########### CurrentPos : " << endl;
    handle.getMe();//root

    handle.backToRoot();
    cout << "########### CurrentPos : " << endl;
    handle.getMe();//root
    cout << "########### Calling for moveToOneBottomNode() and currentPos is : " << endl;
    handle.moveToOneBottomNode();
    handle.getMe();//should be 585
    cout << "########### Calling for deleteCurrentNode() : " << endl;
    handle.deleteCurrentNode();//585 deleted
    cout << "########### CurrentPos : " << endl;
    handle.getMe();//4810{1 root}

 


    */
    /*====================================================
    手动声明变量太慢了
    我在考虑不如直接上数组搭配new和delete
    用函数成一颗树
    生成树的函数接受已有的一个根节点，通过new生成一颗树
    由于是new生成的因此不会在函数结束之后被销毁
    此时这棵树对外暴露的只有根节点
    通过几个get地址的函数就能实现currentPos在树中的移动
    新增Node也定义成全局函数giveMeANewNode（）
    用new生成，返回地址之后紧接着直接绑定到currrentPos：
    giveMeANewNode（integer,strings）->bindOrigin（currentPos）
    我有个想法，把move操作直接封装成类，叫做handler，然后记录currentPos和上一次position
    操作直接叫move
    把giveMeANewNode()也放到成员函数里面去

    PS : 下一个目标是模拟栈结构，实现push和pop
    要不要考虑模拟寄存器？
    ################# Author : PureLov3 ##################
    =====================================================*/
}