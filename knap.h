#pragma once
#include "item.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <memory>

int random_num(int start, int end); //Function to generate random numbers in given range

class Knap
{
public:
	Knap();
	~Knap() = default;
	void Insert(Item* item);
	Knap* CreateNewknap(std::vector<std::unique_ptr<Item>>& element);
	Knap* Mate1(Knap parent2, std::vector<std::unique_ptr<Item>>& element);
	Knap* Mate2(Knap parent2);
	int Cal_fitness();
	const int GetTotalValue() const;
	const int GetTotalSpace() const;
	const int GetPriority() const;
	const Item* GetItem(int index) const;
private:
	int mTotalValue;
	int mTotalSpace;
	int mSize;
	int mPriority;
	Item* mSackArr[10];
};