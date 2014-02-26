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
		cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
		while (cin >> vhead >> vtail)
		{
			insertArc(vhead, vtail);
		}
	}
};
#endif