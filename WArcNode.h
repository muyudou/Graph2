#ifndef WARCNODE_H
#define WARCNODE_H

#include "ArcNode.h"

class WArcNode : public ArcNode
{
    int weight;
};

template <typename VertexType>
struct VNode           //ͷ���
{
	VertexType data;    //������Ϣ
	WArcNode *firstarc;  //ָ���һ�������ڸö���Ļ���ָ��
};

#endif