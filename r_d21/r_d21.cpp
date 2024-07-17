#include <algorithm>
#include <iostream>
#include <vector>




bool compareByLength(std::string left, std::string right) {
    return left.length() < right.length();
}

class LengthComparator {
public:
    bool operator()(std::string& left, std::string& right) {
        return left.length() < right.length();
    }
};


unsigned int countDivisibleBy(const std::vector<int>& vec, int number) {
    return std::count_if(vec.begin(), vec.end(), [&number](int i) { return i % number == 0; });
}


int main()
{
    std::vector<std::string> stringContainer;
    stringContainer.insert(stringContainer.begin(), {
        "test",
        "sun",
        "qwerty",
        "cpp_is_cool",
        "oop"
        });


    // Function
    //std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);


    // Functor
    //LengthComparator comparator;
    //std::sort(stringContainer.begin(), stringContainer.end(), comparator);


    // Lambda
    std::sort(stringContainer.begin(), stringContainer.end(),
        [&](std::string left, std::string right) { return left.length() < right.length(); }
        );

    for (std::size_t i = 0; i < stringContainer.size(); i++) {
        std::cout << stringContainer[i] << '\n';
    }

    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };
    std::cout << countDivisibleBy(numbers, 2) << '\n';
}