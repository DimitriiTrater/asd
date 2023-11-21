#include "lnch_opts/lnch_opts.hpp"
#include "eighteen_lab/eighteen_lab.hpp"
#include "eighth_lab/eighth_lab.hpp"
#include "eleven_lab/eleven_lab.hpp"
#include "fifteen_lab/fifteen_lab.hpp"
#include "fifth_lab/fifth_lab.hpp"
#include "first_lab/first.hpp"
#include "fourteen_lab/fourteen_lab.hpp"
#include "fourth_lab/fourth_lab.hpp"
#include "nineteen_lab/nineteen_lab.hpp"
#include "nineth_lab/nineth_lab.hpp"
#include "second_lab/second.hpp"
#include "seventeen_lab/seventeen_lab.hpp"
#include "seventh_lab/seventh_lab.hpp"
#include "sixteen_lab/sixteen_lab.hpp"
#include "sixth_lab/sixth_lab.hpp"
#include "tenth_lab/tenth_lab.hpp"
#include "third_lab/third_lab.hpp"
#include "thirteen_lab/thirteen_lab.hpp"
#include "twelve_lab/twelve_lab.hpp"

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
  cout << "13.\"Хеш-таблица с наложением\" " << endl;
  cout << "14.\"Хеш-таблица со списками\" " << endl;
  cout << "15.\"БДП: Рекурсивные обходы\" " << endl;
  cout << "16.\"БДП: Не рекурсивный прямой обход\" " << endl;
  cout << "17.\"БДП: операции(поиск, добавление, удаление)\" " << endl;
  cout << "18.\"Сортировка БДП\" " << endl;
  cout << "19.\"Геометрия на плоскости\" " << endl;
  cout << "Если хотите выйти, то введите -1" << endl;
  cout << "#####################################" << endl;
}

void lnch_opts::choice_lab(int inp) {
  using namespace utils;
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
    start_sort(comb_sort<std::vector<int>>);
    break;
  case 5:
    start_sort(insert_sort<std::vector<int>>);
    break;
  case 6:
    start_sort(selection_sort<std::vector<int>>);
    break;
  case 7:
    start_sort(shell_sort<std::vector<int>>);
    break;
  case 8:
    start_sort(radix_sort<std::vector<int>>);
    break;
  case 9:
    start_sort(heap_sort<std::vector<int>>);
    break;
  case 10:
    start_sort(merge_sort_a<std::vector<int>>);
    break;
  case 11:
    start_sort(quick_sort_a<std::vector<int>>);
    break;
  case 12:
    start_tw();
    break;
  case 13:
    start_th();
    break;
  case 14:
    start_ft();
    break;
  case 15:
    start_fft();
    break;
  case 16:
    start_sxt();
    break;
  case 17:
    start_svt();
    break;
  case 18:
    start_et();
    break;
  case 19:
    start_nnt();
    break;
  default:
    std::cerr << "Плохой ввод" << std::endl;
    return;
  }
}
