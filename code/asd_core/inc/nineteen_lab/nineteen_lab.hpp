#pragma once

#include <cmath>
#include <optional>
#include <ostream>
#include <vector>

// struct vec {
//   float x{}, y{};
//   vec() = default;
//   vec(float x, float y) : x(x), y(y) {}
//   static double len(vec v) {
//     return std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));
//   }
//
//   vec operator-(const vec &other) const {
//     return vec{x - other.x, y - other.y};
//   }
//   vec operator+(const vec &other) const {
//     return vec{x + other.x, y + other.y};
//   }
//
//   friend std::ostream &operator<<(std::ostream &os, const vec &v) {
//     os << "x: " << v.x << " "
//        << "y: " << v.y << "\n";
//     return os;
//   }
// };
//
// struct line {
//   line(vec pt1, vec pt2) {
//     A = pt1.y - pt2.y;
//     B = pt2.x - pt1.x;
//     C = pt1.x * pt2.y - pt2.x * pt1.y;
//     // k = -A / B;
//   }
//   float A{}, B{}, C{}, k{};
// };
//
// struct segment {
//   vec point_first{};
//   vec point_second{};
// };
//
// struct circle {
//   float radius{}, x{}, y{};
// };
//
// std::optional<vec> inter_lines(const line &first, const line &second);
// std::optional<vec> inter_line_segment(const line &line, const segment &segment);
// std::optional<vec> inter_segments(const segment &first, const segment &second);
// std::vector<vec> inter_line_circle(const line &line, const circle &circle);
// vec inter_segment_circle(const segment &segment, const circle &circle);
// vec inter_circles(const circle &first, const circle &second);
//
void start_nnt();
