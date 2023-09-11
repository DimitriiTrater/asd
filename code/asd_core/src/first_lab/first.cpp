#include "first_lab/first.hpp"
#include "first_lab/tests.hpp"
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

bool check(const char *str) {
  auto string = std::string{str};
  std::stack<char> stack;
  for (auto &&el : string) {
    switch (el) {
    case '(':
      stack.push(')');
      break;
    case '{':
      stack.push('}');
      break;
    case '[':
      stack.push(']');
      break;
    case ')':
    case '}':
    case ']':
      if (stack.empty() || stack.top() != el)
        return false;
      stack.pop();
      break;
    default:
      throw std::runtime_error("Плохой ввод");
      break;
    }
  }
  return stack.empty();
}

void first_start() {
  std::string inp{};
  std::cout << "Введите строку:" << std::endl;
  std::cin >> inp;
  std::cout << (check(inp.c_str()) ? "Строка существует"
                                   : "Строка не существует")
            << std::endl;
}
