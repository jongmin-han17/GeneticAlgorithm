//Genetic algorithm in C++ by Jongmin Han
//jongmin.han17@gmail.com

/* I applied natural selection to find the best method to put items in a sack under limited space.
 * The more total value of items means the higher priority.
 * The higher priority means higher chance to make child.
 * However, those whose the total space of items exceeds the total space of a sack die every generation.
 * Also, 'natural selection' kills 5 entities who have low priority.
 * This program collects 'item' in 'knap' as the form of array.
 * 'population' vector saves collection of knaps.
 * Every generation, population gets new entities as previous entities
*/
#include "Item.h"
#include "Knapsack.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <memory>

using std::cout;
using std::endl;

bool operator<(const Knapsack& kn1, const Knapsack& kn2)
{
	return kn1.GetPriority() > kn2.GetPriority();
}

int main()
{
	srand((unsigned)(time(0)));
	int generation = 0;
	int fin = 0;
	const int POPULATION_SIZE = 15;
	const int KNAPSACK_SIZE = 30;

	std::shared_ptr<Item> a0 = std::make_shared<Item>(4, 8);
	std::shared_ptr<Item> a1 = std::make_shared<Item>(2, 10);
	std::shared_ptr<Item> a2 = std::make_shared<Item>(11, 10);
	std::shared_ptr<Item> a3 = std::make_shared<Item>(8, 5);
	std::shared_ptr<Item> a4 = std::make_shared<Item>(7, 8);
	std::shared_ptr<Item> a5 = std::make_shared<Item>(6, 3);
	std::shared_ptr<Item> a6 = std::make_shared<Item>(2, 9);
	std::shared_ptr<Item> a7 = std::make_shared<Item>(5, 10);
	std::shared_ptr<Item> a8 = std::make_shared<Item>(7, 5);
	std::shared_ptr<Item> a9 = std::make_shared<Item>(2, 7);


	std::vector<std::shared_ptr<Item>> elements;//{ a0, a1, a2, a3, a4, a5, a6, a7, a8, a9 };
	elements.reserve(10);

	elements.push_back(std::move(a0));
	elements.push_back(std::move(a1));
	elements.push_back(std::move(a2));
	elements.push_back(std::move(a3));
	elements.push_back(std::move(a4));
	elements.push_back(std::move(a5));
	elements.push_back(std::move(a6));
	elements.push_back(std::move(a7));
	elements.push_back(std::move(a8));
	elements.push_back(std::move(a9));

	std::shared_ptr<Knapsack> knap = std::make_shared<Knapsack>();

	std::vector<Knapsack> population;
	population.reserve(POPULATION_SIZE);

	for (int i = 0; i < POPULATION_SIZE; i++)   //Create initial population
	{
		std::shared_ptr<Knapsack> new_knap = knap->CreateNewKnapsack(elements);
		population.push_back(*new_knap);
	}

	for (int i = 0; i < 100; i++) //Repeat generation
	{
		generation++;
		sort(population.begin(), population.end());

		cout << "Generation: " << generation << "\t";
		cout << "Total Value: " << population[0].GetTotalValue() << "\t";
		cout << "Total Space: " << population[0].GetTotalSpace() << "\t";
		cout << "Priority: " << population[0].GetPriority() << endl;

		for (int i = 0; i < 10; i++)
		{
			if (population[fin].GetItem(i) == nullptr)
			{
				cout << "0 ";
			}
			else
			{
				cout << "1 ";
			}
		}
		cout << endl;

		//Step A: remove 5 candidates when its size reaches 15
		for (int i = 0; i < 5; i++)
		{
			population.pop_back();
		}

		//Step B:adding 1 mutant solution to the pool
		//after the size of the pool is reduced from 15 to 10.

		std::shared_ptr<Knapsack> mutant = population[GenerateRandomNumber(0, 9)].Mate(population[GenerateRandomNumber(0, 9)], elements);

		population.push_back(*mutant);

		//Step C:Selecting a pair of parents from the pool of size 11;
		//adding two of their children to the pool.

		std::shared_ptr<Knapsack> child = nullptr;
		child = population[GenerateRandomNumber(0, 10)].Mate(population[GenerateRandomNumber(0, 10)], elements);
		population.push_back(*child);
		child = population[GenerateRandomNumber(0, 10)].Mate(population[GenerateRandomNumber(0, 10)], elements);
		population.push_back(*child);


		for (int i = 0; i < (signed)population.size(); i++) //Kill objects which have space bigger than 30.
		{
			if (population[i].GetTotalSpace() > KNAPSACK_SIZE)
			{
				population.erase(population.begin() + i);
				mutant = population[GenerateRandomNumber(0, 10)].Mate(population[GenerateRandomNumber(0, 10)], elements);  //Make new mutant every time killing object
				population.push_back(*mutant);
			}
		}

		//Step C:Selecting a pair of parents from the pool of size 13;
		//adding two of their children to the pool.

		child = population[GenerateRandomNumber(0, 12)].Mate(population[GenerateRandomNumber(0, 12)], elements);
		population.push_back(*child);
		child = population[GenerateRandomNumber(0, 12)].Mate(population[GenerateRandomNumber(0, 12)], elements);
		population.push_back(*child);


		for (int i = 0; i < (signed)population.size(); i++) //Kill objects which have space bigger than 30.
		{
			if (population[i].GetTotalSpace() > KNAPSACK_SIZE)
			{
				population.erase(population.begin() + i);
				mutant = population[GenerateRandomNumber(0, 10)].Mate(population[GenerateRandomNumber(0, 10)], elements);  //Make new mutant every time killing object
				population.push_back(*mutant);
			}
		}
	}

	sort(population.begin(), population.end());
	cout << endl;

	for (int i = 0; i < (signed)population.size(); i++) //Kill objects which have space bigger than 30.
	{
		if (population[i].GetTotalSpace() > KNAPSACK_SIZE)
		{
			population.erase(population.begin() + i);
		}
	}


	for (int i = 0; i < 10; i++)
	{
		if (population[0].GetItem(i) == nullptr)
		{
			cout << "0 ";
		}
		else
		{
			cout << "1 ";
		}
	}

	cout << endl;

	cout << "Total Value: " << population[fin].GetTotalValue() << endl;
	cout << "Total Space: " << population[fin].GetTotalSpace() << endl;

	return 0;
}
