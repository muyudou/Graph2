#ifndef UDGGRAPH_H
#define UDGGRAPH_H

#include "ALGraph.h"

template <typename VertexType>
class UDGGraph : public ALGraph<VertexType>
{
public:
	UDGGraph(int verNum) : ALGraph(verNum)
	{

	}

	void Create()
	{
		ALGraph::Create();
		int vhead, vtail;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail)
		{
			insertArc(vhead, vtail);
			insertArc(vtail, vhead);
		}
	}
};

#endif