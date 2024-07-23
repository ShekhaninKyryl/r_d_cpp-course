#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <stack>

unsigned int uniqueWordsCount(const std::string& line, char delimiter = ' ') {
    std::set<std::string> set;
    std::string token;
    std::istringstream stream(line);

    while (std::getline(stream, token, delimiter)) {
            set.insert(token);
    }

    return set.size();
};

std::string mostOccuredWord(const std::string& line, char delimiter = ' ') {
    std::map<std::string, std::size_t> map;

    std::string token;
    std::istringstream stream(line);

    while (std::getline(stream, token, delimiter)) {
        ++map[token];
    }

    std::string mostOccurred;
    std::size_t maxCount = 0;
    for (const auto& pair : map) {
        if (pair.second > maxCount) {
            mostOccurred = pair.first;
            maxCount = pair.second;
        }
    }

    return mostOccurred;
};

enum class Brackets {
    CurvedOpen = '(',
    CurvedClose = ')',

    SquareOpen = '[',
    SquareClose = ']',

    CurlyOpen = '{',
    CurlyClose = '}',

    AngleOpen = '<',
    AngleClose = '>',
};

bool isBalancedBrackets(const std::string& line) {
    std::stack<char> stack;

    for (char c : line) {
        switch ((c) )
        {
        case static_cast<char>(Brackets::CurvedOpen):
        case static_cast<char>(Brackets::SquareOpen):
        case static_cast<char>(Brackets::CurlyOpen):
        case static_cast<char>(Brackets::AngleOpen): {
            stack.push(c);
            break;
        }
        case static_cast<char>(Brackets::CurvedClose): {
            char prevBracket = stack.top();
            if (prevBracket != static_cast<char>(Brackets::CurvedOpen)) return false;
            stack.pop();
            break;
        }
        case static_cast<char>(Brackets::SquareClose): {
            char prevBracket = stack.top();
            if (prevBracket != static_cast<char>(Brackets::SquareOpen)) return false;
            stack.pop();
            break;
        }
        case static_cast<char>(Brackets::CurlyClose): {
            char prevBracket = stack.top();
            if (prevBracket != static_cast<char>(Brackets::CurlyOpen)) return false;
            stack.pop();
            break;
        }
        case static_cast<char>(Brackets::AngleClose): {
            char prevBracket = stack.top();
            if (prevBracket != static_cast<char>(Brackets::AngleOpen)) return false;
            stack.pop();
            break;
        }

        default:
            break;
        }
    }

    return true;
}


struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};


Node* create_list_with_cycle() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;  // cycle

    return head;
}

Node* create_list_without_cycle() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    return head;
}

template <typename T>
bool has_cycle(T* head) {
    std::map<T*, int> elements;

    while (head) {
        if (elements[head]) return true;
        elements[head]++;
        head = head->next;
    }

    return false;
}

int main()
{
    std::cout << uniqueWordsCount("Hello is a best a Hello") << '\n'; // 4
    std::cout << uniqueWordsCount("") << '\n'; // 0

    std::cout << mostOccuredWord("Hello is a best a Hello") << '\n'; // Hello
    std::cout << mostOccuredWord("") << '\n'; // 

    std::cout << isBalancedBrackets("(  ( {21} ) sadasd )  [< asd >] ") << '\n'; // true
    std::cout << isBalancedBrackets("( { [) } ]") << '\n'; // false 

    std::cout << has_cycle(create_list_with_cycle()) << '\n'; // true
    std::cout << has_cycle(create_list_without_cycle()) << '\n'; // false 
}