#include "UDGGraph.h"
#include "DGGraph.h"
#include "WDGGraph.h"
#include "WUDGGraph.h"

int main()
{
	UDGGraph<char> udgGraph(8);
	udgGraph.Create();
	udgGraph.displayGraph();

	/*WDGGraph<char, int> wdgGraph(6);
	wdgGraph.Create();
	wdgGraph.displayGraph();*/

	system("pause");
	return 0;
}