#ifndef ALGRAPH_H
#define ALGRAPH_H

#include <vector>
#include <iostream>
#include <queue>
#include "ArcNode.h"
using namespace std;

template <typename VertexType>
class ALGraph
{
public:
	ALGraph(int verNum) : vexnum(verNum), arcnum(0)
	{
		for (int i = 0; i < MAX_VERTEX_NUM; i++)
			vertices[i].firstarc = NULL;
	}

	//构造图，进行选择
	virtual void Create()
	{
		InitVertics();
	}

	//打印邻接链表
	virtual void displayGraph()
	{
		for (int i = 0; i < vexnum; i++)
		{
			cout << "第" << i+1 << "个顶点是：" << vertices[i].data
				<< " 邻接表为: ";
			ArcNode *arcNode = vertices[i].firstarc;
			while (arcNode != NULL)
			{
				cout << " -> " << vertices[arcNode->adjvex].data;
					/*<< "(" << arcNode->weight << ")";*/
				arcNode = arcNode->nextarc;
			}
			cout << endl;
		}
	}

protected:
	//初始化邻接链表的表头数组
	void InitVertics()
	{
		cout << "请输入每个顶点的关键字：" << endl;
		VertexType val;
		for (int i = 0; i < vexnum; i++)
		{
			cin >> val;
			vertices[i].data = val;
		}
	}

	//插入一个表结点
	void insertArc(int vHead, int vTail)
	{
		//构造一个表结点
		ArcNode *newArcNode = new ArcNode;
		newArcNode->adjvex = vTail;
		newArcNode->nextarc = NULL;

		//arcNode 是vertics[vHead]的邻接表
		ArcNode *arcNode = vertices[vHead].firstarc;
		if (arcNode == NULL)
			vertices[vHead].firstarc = newArcNode;
		else
		{
			while (arcNode->nextarc != NULL)
			{
				arcNode = arcNode->nextarc;		
			}
			arcNode->nextarc = newArcNode;
		}
		arcnum++;
	}

private:
	//const数据成员必须在构造函数里初始化
	static const int MAX_VERTEX_NUM = 20;  //最大顶点个数

	VNode<VertexType> vertices[MAX_VERTEX_NUM];
	int vexnum;             //图的当前顶点数
	int arcnum;             //图的弧数
};

#endif