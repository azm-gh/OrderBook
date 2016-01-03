#pragma once

#include <map>
#include <iostream>
#include <boost\optional\optional.hpp>

class OrderBook
{
private:
	std::map<int, int> bids, asks;
	void add(int price, int amount, bool bid);
	void remove(int price, int amount, bool bid);

public:
	struct BidAsk 
	{
		typedef boost::optional<std::pair<int, int>> Entry;
		Entry bid, ask;
		boost::optional<int> spread() const;
	};
	
	inline bool is_empty() const;
	void add_bid(int price, int amount);
	void add_ask(int price, int amount);

	void remove_bid(int price, int amount);
	void remove_ask(int price, int amount);

	BidAsk get_Bid_Ask() const;

	friend std::ostream& operator<<
		(std::ostream& os, const OrderBook& book);

	friend std::ostream& operator<<
		(std::ostream& os, const OrderBook::BidAsk& ba);
	
};

bool OrderBook::is_empty() const
{
	return bids.empty() && asks.empty();
}

