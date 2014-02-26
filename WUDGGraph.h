#ifndef WUDGGRAPH_H
#define WUDGGRAPH_H

#include "ALGraph.h"

template <typename VertexType, typename WeightType>
class WUDGGraph : public ALGraph<VertexType>
{
public:
	WUDGGraph(int verNum) : ALGraph(verNum)
	{

	}

	void Create()
	{
		ALGraph::Create();
		int vhead, vtail;
		cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
		while (cin >> vhead >> vtail)
		{
			insertArc(vhead, vtail, 0);
			insertArc(vhead, vtail, 0);
		}
	}

	//打印邻接链表
	void displayGraph()
	{
		for (int i = 0; i < vexnum; i++)
		{
			cout << "第" << i+1 << "个顶点是：" << vertices[i].data
				<< " 邻接表为: ";
			ArcNode *arcNode = vertices[i].firstarc;
			while (arcNode != NULL)
			{
				cout << " -> " << vertices[arcNode->adjvex].data
					/*<< "(" << arcNode->weight << ")";*/
					arcNode = arcNode->nextarc;
			}
			cout << endl;
		}
	}

private:
	//插入一个表结点
	void insertArc(int vHead, int vTail, WeightType w)
	{
		//构造一个表结点
		ArcNode *newArcNode = new ArcNode;
		newArcNode->adjvex = vTail;
		newArcNode->nextarc = NULL;
		newArcNode->weight = w;

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

	struct ArcNode          //表结点
	{
		int adjvex;        //该弧所指向的顶点的位置
		ArcNode *nextarc;  //指向下一条弧的指针
		WeightType weight;     //该弧相关信息的指针
	};
};
#endif