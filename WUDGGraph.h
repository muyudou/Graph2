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
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail)
		{
			insertArc(vhead, vtail, 0);
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
					/*<< "(" << arcNode->weight << ")";*/
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

	struct ArcNode          //����
	{
		int adjvex;        //�û���ָ��Ķ����λ��
		ArcNode *nextarc;  //ָ����һ������ָ��
		WeightType weight;     //�û������Ϣ��ָ��
	};
};
#endif