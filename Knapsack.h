#pragma once
#include "Item.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <memory>

int GenerateRandomNumber(int start, int end);

class Knapsack
{
public:
	Knapsack();
	Knapsack(const Knapsack& other);
	~Knapsack() = default;
	void Insert(std::shared_ptr<Item> item);
	std::shared_ptr<Knapsack> CreateNewKnapsack(std::vector<std::shared_ptr<Item>>& itemArr);
	std::shared_ptr<Knapsack> Mate(Knapsack& parent2, std::vector<std::shared_ptr<Item>>& itemArr);
	const int GetTotalValue() const;
	const int GetTotalSpace() const;
	const int GetPriority() const;
	std::shared_ptr<Item> GetItem(int index);
private:
	int mTotalValue;
	int mTotalSpace;
	int mSize;
	int mPriority;
	std::vector<std::shared_ptr<Item>> mItems;
};