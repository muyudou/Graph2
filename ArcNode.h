#ifndef ARCNODE_H
#define ARCNODE_H

class ArcNode
{
public:
	int adjvex;        //该弧所指向的顶点的位置
	ArcNode *nextarc;  //指向下一条弧的指针
	ArcNode() : adjvex(-1), nextarc(NULL) {}
};

template <typename VertexType>
struct VNode           //头结点
{
	VertexType data;    //顶点信息
	ArcNode *firstarc;  //指向第一条依附于该顶点的弧的指针
};

#endif