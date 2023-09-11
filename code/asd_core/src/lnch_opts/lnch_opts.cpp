#include "lnch_opts/lnch_opts.hpp"
#include "first_lab/first.hpp"
#include "second_lab/second.hpp"

void lnch_opts::build_hello() {
  using namespace std;
  cout << "Лаунчер Лаб Раб" << endl;
  cout << "Выполнил: -" << endl;
  cout << "#####################################" << endl;
  cout << "Список лабораторных" << endl;
  cout << "Выберите, что запустить" << endl;
  cout << " 1.\"Задача о скобках\" " << endl;
  cout << " 2.\"Задача об арифметических выражениях\" " << endl;
  cout << " 3.\"Задача о скобках\" " << endl;
  cout << " 4.\"Задача о скобках\" " << endl;
  cout << " 5.\"Задача о скобках\" " << endl;
  cout << " 6.\"Задача о скобках\" " << endl;
  cout << " 7.\"Задача о скобках\" " << endl;
  cout << " 8.\"Задача о скобках\" " << endl;
  cout << " 9.\"Задача о скобках\" " << endl;
  cout << "10.\"Задача о скобках\" " << endl;
  cout << "11.\"Задача о скобках\" " << endl;
  cout << "12.\"Задача о скобках\" " << endl;
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
    break;
  case 2: {
    second_start();
    break;
  }
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
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
