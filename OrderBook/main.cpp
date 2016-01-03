#include "OrderBook.h"

int main()

{
	using namespace std;
	OrderBook book;
	book.add_bid(100, 5);
	book.add_ask(100, 6);
	std::cout << book << endl;

	std::cout << book.get_Bid_Ask();

	std::cout << std::endl;
	


	system("pause");
	return 0;
}
