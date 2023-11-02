#include "seventeen_lab/seventeen_lab.hpp"
#include "fifteen_lab/fifteen_lab.hpp"
#include <iostream>

void start_svt() {
  std::string query{""};
  std::cout << "Введите бинарное дерево \n";
  std::cin.ignore();
  getline(std::cin, query);
  BinaryTree<int> bt(query);
  // 8 (3 (1, 6 (4, 7)), 10 (,14(13,)))
  bool endless_flag{true};
  while (endless_flag) {
    std::cout << "Меню:\n";
    std::cout << "1. Добавить\n";
    std::cout << "2. Удалить\n";
    std::cout << "3. Поиск\n";
    std::cout << "4. Выйти\n";
    std::cout << "Выберите соответственно 1, 2, 3, 4.\n";
    int choice{};
    std::cin >> choice;
    switch (choice) {
    case 1: {
      std::cout << "Введите что вы хотели бы добавить: \n";
      int t{};
      std::cin >> t;
      bt.add(t);
      break;
    }
    case 2: {
      std::cout << "Введите, что вы хотите удалить: \n";
      int t{};
      std::cin >> t;
      bt.remove(t);
      break;
    }
    case 3: {
      std::cout << "Введите, что вы хотите найти: \n";
      int t{};
      std::cin >> t;
      auto m = bt.find(t);
      if (m == nullptr) {
        std::cout << "Увы, такого элемента нет \n";
        break;
      }
      std::cout << "Ключ: " << m->data.value() << " Левая нода: " << m->left
                << " Правая нода: " << m->right << "\n";
      break;
    }
    case 4:
      endless_flag = false;
      break;
    default:
      break;
    }
    std::cout << "Ваше бинарное дерево: \n";
    BinaryTree<>::rec_pre_order(bt);
    std::cout << "\n";
  }
}
