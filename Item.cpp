#include "Item.h"

Item::Item(int value, int space)
	: mValue(value)
	, mSpace(space)
{
}

const int Item::GetValue() const
{
    return mValue;
}

const int Item::GetSpace() const
{
    return mSpace;
}
