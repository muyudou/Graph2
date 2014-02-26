#ifndef WDGGRAPH_H
#define WDGGRAPH_H

#include "ALGraph.h"
#include "WArcNode.h"

template <typename VertexType, typename WeightType>
class WDGGraph : public ALGraph<VertexType>
{
public:
	WDGGraph(int verNum) : ALGraph(verNum)
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
					<< "(" << arcNode->weight << ")";
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

	static const int MAX_VERTEX_NUM = 20;  //最大顶点个数

    VNode<VertexType> vertices[MAX_VERTEX_NUM];
};

#endif