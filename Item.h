#pragma once

class Item
{
public:
	Item(int value, int space);
	~Item() = default;
	const int GetValue() const;
	const int GetSpace() const;
private:
	int mValue;
	int mSpace;
};