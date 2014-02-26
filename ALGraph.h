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

	//����ͼ������ѡ��
	virtual void Create()
	{
		InitVertics();
	}

	//��ӡ�ڽ�����
	virtual void displayGraph()
	{
		for (int i = 0; i < vexnum; i++)
		{
			cout << "��" << i+1 << "�������ǣ�" << vertices[i].data
				<< " �ڽӱ�Ϊ: ";
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
	//��ʼ���ڽ�����ı�ͷ����
	void InitVertics()
	{
		cout << "������ÿ������Ĺؼ��֣�" << endl;
		VertexType val;
		for (int i = 0; i < vexnum; i++)
		{
			cin >> val;
			vertices[i].data = val;
		}
	}

	//����һ������
	void insertArc(int vHead, int vTail)
	{
		//����һ������
		ArcNode *newArcNode = new ArcNode;
		newArcNode->adjvex = vTail;
		newArcNode->nextarc = NULL;

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

private:
	//const���ݳ�Ա�����ڹ��캯�����ʼ��
	static const int MAX_VERTEX_NUM = 20;  //��󶥵����

	VNode<VertexType> vertices[MAX_VERTEX_NUM];
	int vexnum;             //ͼ�ĵ�ǰ������
	int arcnum;             //ͼ�Ļ���
};

#endif