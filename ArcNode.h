#ifndef ARCNODE_H
#define ARCNODE_H

class ArcNode
{
public:
	int adjvex;        //�û���ָ��Ķ����λ��
	ArcNode *nextarc;  //ָ����һ������ָ��
	ArcNode() : adjvex(-1), nextarc(NULL) {}
};

template <typename VertexType>
struct VNode           //ͷ���
{
	VertexType data;    //������Ϣ
	ArcNode *firstarc;  //ָ���һ�������ڸö���Ļ���ָ��
};

#endif