#include "lnch_opts/lnch_opts.hpp"
#include "eighth_lab/eighth_lab.hpp"
#include "fifth_lab/fifth_lab.hpp"
#include "first_lab/first.hpp"
#include "fourth_lab/fourth_lab.hpp"
#include "second_lab/second.hpp"
#include "seventh_lab/seventh_lab.hpp"
#include "sixth_lab/sixth_lab.hpp"
#include "third_lab/third_lab.hpp"

void lnch_opts::build_hello() {
  using namespace std;
  cout << "Лаунчер Лаб Раб" << endl;
  cout << "Выполнил: -" << endl;
  cout << "#####################################" << endl;
  cout << "Список лабораторных" << endl;
  cout << "Выберите, что запустить" << endl;
  cout << " 1.\"Задача о скобках\" " << endl;
  cout << " 2.\"Задача об арифметических выражениях\" " << endl;
  cout << " 3.\"Задача о простых множителях\" " << endl;
  cout << " 4.\"Сортировка методом прочесывания\" " << endl;
  cout << " 5.\"Сортировка вставками\" " << endl;
  cout << " 6.\"Сортировка посредством выбора\" " << endl;
  cout << " 7.\"Сортировка Шелла\" " << endl;
  cout << " 8.\"Сортировка Поразрядная\" " << endl;
  cout << " 9.\"Сортировка Пирамидальная\" " << endl;
  cout << "10.\"Сортировка Слиянием\" " << endl;
  cout << "11.\"Сортировка Быстрая\" " << endl;
  cout << "12.\"Сортировка Внешняя многофазовая\" " << endl;
  cout << "13.\"Задача о скобках\" " << endl;
  cout << "14.\"Задача о скобках\" " << endl;
  cout << "15.\"Задача о скобках\" " << endl;
  cout << "16.\"Задача о скобках\" " << endl;
  cout << "17.\"Задача о скобках\" " << endl;
  cout << "Если хотите выйти, то введите -1" << endl;
  cout << "#####################################" << endl;
}

void lnch_opts::choice_lab(int inp) {
  switch (inp) {
  case 1:
    first_start();
    break;
  case 2:
    second_start();
    break;
  case 3:
    third_start();
    break;
  case 4:
    fourth_start();
    break;
  case 5:
    fifth_start();
    break;
  case 6:
    sixth_start();
    break;
  case 7:
    seventh_start();
    break;
  case 8:
    eighth_start();
    break;
  case 9:
    break;
  case 10:
    break;
  case 11:
    break;
  case 12:
    break;
  case 13:
    break;
  case 14:
    break;
  case 15:
    break;
  case 16:
    break;
  case 17:
    break;
  default:
    std::cerr << "Плохой ввод" << std::endl;
    return;
  }
}
