#pragma once
#include <cstdlib>
#include <map>
#include <vector>


template <typename T>
class Deck
{
protected:

    ~Deck()
    {
        for (auto& pair : database)
        {
            delete pair.first;
        }
        database.clear();
    }

	T* generate(bool shuffleTheDeck = false) {
        if (available.empty() && shuffleTheDeck)
        {
            for (const auto& pair : database)
            {
                for (int i = 0; i < pair.second; ++i)
                {
                    available.push_back(pair.first);
                }
            }
        }

        if (available.empty()) return nullptr;

        const int choice = std::rand() % available.size();
        T* selected = available[choice];
        this->available.erase(available.begin() + choice);

        return selected;
	}

    void fill() {
        for (const auto& pair : database)
        {
            for (int i = 0; i < pair.second; ++i)
            {
                available.push_back(pair.first);
            }
        }
    }

	std::map<T*, std::size_t> database;
	std::vector<T*> available;
};