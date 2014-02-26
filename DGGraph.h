#ifndef DGGRAPH_H
#define DGGRAPH_H

#include "ALGraph.h"

template <typename VertexType>
class DGGraph : public ALGraph<VertexType>
{
public:
	DGGraph(int verNum) : ALGraph(verNum)
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
		}
	}
};
#endif