#include <iostream>

template<typename... Tpacket>
void functempla(Tpacket... args) {
    std::cout << " Template function functempla\n "
              << __PRETTY_FUNCTION__
              << "\n received packet of "
              << (sizeof...(Tpacket))
              << " arguments " << std::endl;
}

template<typename T, typename... Tpacket>
void print(T first, Tpacket... rest) {
    std::cout << "\n Template function \n "
              << __PRETTY_FUNCTION__
              << "\n received (1 argument + pack of "
              << (sizeof...(Tpacket))
              << " arguments)" << std::endl;

    std::cout << " Print of first argument: " << first << std::endl;
}

template<typename T, typename... Tpacket>
void printAll(T first, Tpacket... rest) {
    std::cout << first << " ";
    if constexpr(sizeof...(Tpacket) > 0) {
        printAll(rest...);
    }
}

template<typename T, typename... Tpakiet>
auto sum(T arg, Tpakiet... reszta) {
    if constexpr(sizeof...(Tpakiet) > 0) {
        return arg + sum(reszta...);
    } else return arg;
}

int main() {
    std::cout << "Hello, World!\n" << std::endl;

    functempla<int, char, double>(100, '$', 3.14);

    print("alert", 12, 3.33, '#', 100, "ion engines", 3,
          "overheating", std::string("ASDFG"));

    std::cout << "\n All arguments printed:\n ";
    printAll("alert", 12, 3.33, '#', 100, "ion engine", 3,
             "overheating", std::string("ASDFG"));

    std::cout << "\n\n Sum of numbers 1..5: " << sum(1, 2, 3, 4, 5);

    return 0;
}
