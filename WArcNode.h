#ifndef WARCNODE_H
#define WARCNODE_H

#include "ArcNode.h"

class WArcNode : public ArcNode
{
    int weight;
};

template <typename VertexType>
struct VNode           //头结点
{
	VertexType data;    //顶点信息
	WArcNode *firstarc;  //指向第一条依附于该顶点的弧的指针
};

#endif