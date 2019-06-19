#include "Knapsack.h"

int GenerateRandomNumber(int start, int end)
{
	int range = (end - start) + 1;
    int randomInt = start + (rand() % range);
	return randomInt;
}

Knapsack::Knapsack()
	: mTotalValue(0)
	, mTotalSpace(0)
	, mPriority(0)
	, mSize(0)
{
	mItems.reserve(10);

	for (int i = 0; i < 10; i++)
	{
		mItems.push_back(nullptr);
	}
}

Knapsack::Knapsack(const Knapsack& other)
	: mTotalValue(other.mTotalValue)
	, mTotalSpace(other.mTotalSpace)
	, mPriority(other.mPriority)
	, mSize(other.mSize)
{
	mItems.reserve(10);
	for (int i = 0; i < 10; i++)
	{
		mItems.push_back(other.mItems[i]);
	}
}

void Knapsack::Insert(std::shared_ptr<Item> item)
{
	mItems[mSize++] = item;

	if (item != nullptr)
	{
		mTotalValue += item->GetValue();
		mTotalSpace += item->GetSpace();
	}

	mPriority = mTotalValue - std::max(mTotalSpace - 30, 0);
}

std::shared_ptr<Knapsack> Knapsack::CreateNewKnapsack(std::vector<std::shared_ptr<Item>>& itemArr)
{
	int randomNum;
	std::shared_ptr<Knapsack> newKnapsack = nullptr;

	while (true)
	{
		newKnapsack = std::make_shared<Knapsack>();

		for (int i = 0; i < 10; i++)
		{
			randomNum = GenerateRandomNumber(0, 1);
			if (randomNum == 1)
			{
				newKnapsack->Insert(itemArr[i]);
			}
			else
			{
				newKnapsack->Insert(nullptr);
			}
		}

		if (newKnapsack->GetTotalSpace() <= 30)
		{
			break;
		}

		newKnapsack.reset();
	}

	return newKnapsack;
}

std::shared_ptr<Knapsack> Knapsack::Mate(Knapsack& parent2, std::vector<std::shared_ptr<Item>>& itemArr)
{
	std::shared_ptr<Knapsack> child = std::make_shared<Knapsack>();

	int r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[0]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[0]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[0]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[1]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[1]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[1]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[2]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[2]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[2]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[3]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[3]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[3]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[4]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[4]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[4]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[5]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[5]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[5]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[6]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[6]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[6]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[7]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[7]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[7]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[8]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[8]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[8]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = GenerateRandomNumber(0, 99);
	if (r < 40)
	{
		child->Insert(this->mItems[9]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mItems[9]);
	}
	else if (r < 90)
	{
		child->Insert(itemArr[9]);
	}
	else
	{
		child->Insert(nullptr);
	}

	return child;
}

const int Knapsack::GetTotalValue() const
{
	return mTotalValue;
}

const int Knapsack::GetTotalSpace() const
{
	return mTotalSpace;
}

const int Knapsack::GetPriority() const
{
	return mPriority;
}

std::shared_ptr<Item> Knapsack::GetItem(int index)
{
	return mItems[index];
}