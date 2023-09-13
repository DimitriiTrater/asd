#include "second_lab/second.hpp"
#include "second_lab/tests.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>

double multiplicationAndDivision(std::string &expression) {
  double result = prefixAndBracket(expression);

  while (true) {

    while (isspace(expression[0]))
      expression.erase(0, 1);

    switch (expression[0]) {
    case 0:
      return result;

    case '*':
      expression.erase(0, 1);
      result *= prefixAndBracket(expression);
      break;

    case '/':
      if (expression[1] == '0')
        throw std::runtime_error("Деление на ноль");
      expression.erase(0, 1);
      result /= prefixAndBracket(expression);
      break;

    default:
      return result;
    }
  }
}

double additionAndSubtraction(std::string &expression) {
  double result = multiplicationAndDivision(expression);

  while (true) {
    while (isspace(expression[0]))
      expression.erase(0, 1);

    switch (expression[0]) {
    case 0:
      return result;
    case '+':
      expression.erase(0, 1);
      result += multiplicationAndDivision(expression);
      break;
    case '-':
      expression.erase(0, 1);
      result -= multiplicationAndDivision(expression);
      break;
    default:
      return result;
    }
  }
}

bool checkSign(std::string &expression) {
  if (expression[0] == '=') {
    expression.clear();
    return 0;
  }

  if (expression[0] == '+')
    return false;

  if (expression[0] == '-')
    return false;

  if (expression[0] == '*')
    return false;

  if (expression[0] == '/')
    return false;

  if (expression[0] == '\0')
    return false;

  if (expression[0] == ')')
    return false;

  if (expression[0] == '(')
    return false;

  return true;
}

double prefixAndBracket(std::string &expression) {
  while (isspace(expression[0]))
    expression.erase(0, 1);
  switch (expression[0]) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9': {
    double a = strtod(expression.c_str(), NULL);
    expression.erase(0, 1);
    while (checkSign(expression))
      expression.erase(0, 1);
    return a;
  }
  case '-': {
    expression.erase(0, 1);
    return -prefixAndBracket(expression);
  }
  case '+': {
    expression.erase(0, 1);
    return prefixAndBracket(expression);
  }
  case '(': {
    expression.erase(0, 1);
    double result = additionAndSubtraction(expression);
    if (expression[0] == ')')
      expression.erase(0, 1);
    return result;
  }
  default:
    throw std::runtime_error("Плохое выражение");
  }
}

double expression(std::string &expression) {
  const double result = additionAndSubtraction(expression);

  while (isspace(expression[0]))
    expression.erase(0, 1);

  return result;
}

void second_start() {
  // tests();
  std::string inp{};
  std::cin >> inp;
  auto ex = expression(inp);
  std::cout << ex << std::endl;
}
