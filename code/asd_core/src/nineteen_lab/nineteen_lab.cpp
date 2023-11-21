#include "nineteen_lab/nineteen_lab.hpp"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <optional>
#include <set>

constexpr double EPS = 1E-9;

struct pt {
  double x{}, y{};

  bool operator<(const pt &p) const {
    return x < p.x - EPS || std::abs(x - p.x) < EPS && y < p.y - EPS;
  }
};

struct line {
  double a, b, c;

  line() = default;
  line(pt p, pt q) {
    a = p.y - q.y;
    b = q.x - p.x;
    c = -a * p.x - b * p.y;
    norm();
  }

  void norm() {
    double z = std::sqrt(a * a + b * b);
    if (std::abs(z) > EPS)
      a /= z, b /= z, c /= z;
  }

  double dist(pt p) const { return a * p.x + b * p.y + c; }
};

namespace {
auto det = [](auto a, auto b, auto c, auto d) { return a * d - b * c; };
}

inline bool betw(double l, double r, double x) {
  return std::min(l, r) <= x + EPS && x <= std::max(l, r) + EPS;
}

inline bool intersect_1d(double a, double b, double c, double d) {
  if (a > b)
    std::swap(a, b);
  if (c > d)
    std::swap(c, d);
  return std::max(a, c) <= std::min(b, d) + EPS;
}

bool intersect(pt a, pt b, pt c, pt d, pt &left, pt &right) {
  if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y))
    return false;
  line m(a, b);
  line n(c, d);
  double zn = det(m.a, m.b, n.a, n.b);
  if (std::abs(zn) < EPS) {
    if (std::abs(m.dist(c)) > EPS || std::abs(n.dist(a)) > EPS)
      return false;
    if (b < a)
      std::swap(a, b);
    if (d < c)
      std::swap(c, d);
    left = std::max(a, c);
    right = std::min(b, d);
    return true;
  } else {
    left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
    left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
    return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
           betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
  }
}

void start_nnt() {
  std::set<pt> intersections;
  // intersections.emplace();

  // B4:
  auto A = pt(1, 1);
  auto B = pt(1, 5);
  auto C = pt(3, 5);
  auto D = pt(3, 1);

  // M4:
  auto L = pt(1, 4);
  auto K = pt(2, 5);
  auto M = pt(3, 4);
  auto N = pt(2, 3.5);

  // M3:
  auto O = pt(1, 3);
  auto P = pt(3, 3);
  auto Q = pt(2, 1);

  pt ansl, ansr;
  // std::cout << ansl.x << " " << ansl.y << "\n";
  // int B4
  intersect(A, B, B, C, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
  intersect(B, C, C, D, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
  intersect(C, D, D, A, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
  intersect(D, A, A, B, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";

  // int M4
  intersect(L, K, K, M, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
  intersect(K, M, M, N, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
  intersect(M, N, N, L, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
  intersect(N, L, L, K, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";

  // int M3
  intersect(O, P, P, Q, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
  intersect(P, Q, Q, O, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
  intersect(Q, O, O, P, ansl, ansr);
  std::cout << ansl.x << " " << ansl.y << "\n";
}
