#include "knap.h"
#include "item.h"

int random_num(int start, int end)
{
	int range = (end - start) + 1;
	int random_int = start + (rand() % range);
	return random_int;
}

Knap::Knap()
	: mSize(0)
	, mTotalValue(0)
	, mTotalSpace(0)
	, mPriority(0)
{
	for (int i = 0; i < 10; i++)
	{
		mSackArr[i] = nullptr;
	}
}

void Knap::Insert(Item* item)
{
	mSackArr[mSize] = item;
	mSize++;

	if (item != nullptr)
	{
		mTotalValue += item->GetValue();
		mTotalSpace += item->GetSpace();
	}

	mPriority = mTotalValue - std::max(mTotalSpace - 30, 0);
}

Knap* Knap::CreateNewknap(const std::vector<std::unique_ptr<Item>>& element)
{
	int r;
	Knap* new_knap = nullptr;

	while (true)
	{
		new_knap = new Knap();

		for (int i = 0; i < 10; i++)
		{
			r = random_num(0, 1);
			if (r == 1)
			{
				new_knap->Insert(element[i]);
			}
			else
			{
				new_knap->Insert(nullptr);
			}
		}

		if (new_knap->mTotalSpace <= 30)
		{
			break;
		}

		delete new_knap;
	}

	return new_knap;
}

Knap* Knap::Mate1(Knap parent2, std::vector<std::unique_ptr<Item>>& element)
{
	std::unique_ptr<Knap> child = std::make_unique<Knap>();

	int r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[0]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[0]);
	}
	else if (r < 90)
	{
		child->Insert(element[0]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[1]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[1]);
	}
	else if (r < 90)
	{
		child->Insert(element[1]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[2]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[2]);
	}
	else if (r < 90)
	{
		child->Insert(element[2]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[3]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[3]);
	}
	else if (r < 90)
	{
		child->Insert(element[3]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[4]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[4]);
	}
	else if (r < 90)
	{
		child->Insert(element[4]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[5]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[5]);
	}
	else if (r < 90)
	{
		child->Insert(element[5]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[6]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[6]);
	}
	else if (r < 90)
	{
		child->Insert(element[6]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[7]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[7]);
	}
	else if (r < 90)
	{
		child->Insert(element[7]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[8]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[8]);
	}
	else if (r < 90)
	{
		child->Insert(element[8]);
	}
	else
	{
		child->Insert(nullptr);
	}

	r = random_num(0, 99);
	if (r < 40)
	{
		child->Insert(this->mSackArr[9]);
	}
	else if (r < 80)
	{
		child->Insert(parent2.mSackArr[9]);
	}
	else if (r < 90)
	{
		child->Insert(element[9]);
	}
	else
	{
		child->Insert(nullptr);
	}

	return child;
}

Knap* Knap::Mate2(Knap parent2)
{
	Knap* child = new Knap();

	if (random_num(0, 1) == 1)
	{
		child->Insert(parent2.mSackArr[0]);
	}
	else
	{
		child->Insert(nullptr);
	}

	child->Insert(parent2.mSackArr[1]);
	child->Insert(parent2.mSackArr[2]);
	child->Insert(parent2.mSackArr[3]);
	child->Insert(parent2.mSackArr[4]);
	child->Insert(this->mSackArr[5]);
	child->Insert(this->mSackArr[6]);

	if (random_num(0, 1) == 1)
	{
		child->Insert(this->mSackArr[7]);
	}
	else
	{
		child->Insert(nullptr);
	}
	child->Insert(this->mSackArr[8]);
	child->Insert(this->mSackArr[9]);

	return child;
}

const int Knap::GetTotalValue() const
{
	return mTotalValue;
}

const int Knap::GetTotalSpace() const
{
	return mTotalSpace;
}

const int Knap::GetPriority() const
{
	return mPriority;
}

const Item* Knap::GetItem(int index) const
{
	return mSackArr[index];
}

/*
int Knap::TotalValue()
{
	int len = this->mSize;
	int value = 0;

	for (int i=0; i<len; i++)
	{
		if (this->mSackArr[i] == nullptr)
			value += 0;
		else
			value += this->mSackArr[i]->GetValue();
	}

	return value;
}

int Knap::TotalSpace()
{
	int len = mSize;
	int space = 0;

	for (int i=0; i<len; i++)
	{
		if (mSackArr[i] == nullptr)
			space += 0;
		else
			space += mSackArr[i]->GetSpace();
	}

	return space;
}
*/
