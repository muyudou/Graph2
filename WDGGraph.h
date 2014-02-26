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
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail)
		{
			insertArc(vhead, vtail, 0);
		}
	}

	//��ӡ�ڽ�����
	void displayGraph()
	{
		for (int i = 0; i < vexnum; i++)
		{
			cout << "��" << i+1 << "�������ǣ�" << vertices[i].data
				<< " �ڽӱ�Ϊ: ";
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
	//����һ������
	void insertArc(int vHead, int vTail, WeightType w)
	{
		//����һ������
		ArcNode *newArcNode = new ArcNode;
		newArcNode->adjvex = vTail;
		newArcNode->nextarc = NULL;
		newArcNode->weight = w;

		//arcNode ��vertics[vHead]���ڽӱ�
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

	static const int MAX_VERTEX_NUM = 20;  //��󶥵����

    VNode<VertexType> vertices[MAX_VERTEX_NUM];
};

#endif