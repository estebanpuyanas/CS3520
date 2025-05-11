#include "Pathfinding.hpp"
#include "Point.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// utility function to compute a path from start to goal given the came_from information
void came_from_to_path(const map<Point, Point> & came_from, const Point & start, const Point & goal, list<Point> & path) {
  path.clear();
  // if goal isn't in came_from, then no path
  if (came_from.find(goal) == came_from.end()) {
      return;
  }
  // reconstruct path
  Point current = goal;
  while (current != start) {
      path.push_front(current);
      current = came_from.at(current);
  }
  path.push_front(start);
}

void pathfind_bfs(const World & w, list<Point> & path) {
  path.clear();
  deque<Point> frontier;
  map<Point, Point> came_from;
  
  frontier.push_back(w.start);
  came_from[w.start] = w.start;
  
  while (!frontier.empty()) {
      Point current = frontier.front();
      frontier.pop_front();
      if (current == w.goal) {
          break;
      }
      set<Point> neighbors;
      w.get_neighbors(current, neighbors);
      for (auto & n : neighbors) {
          if (came_from.find(n) == came_from.end()) {
              came_from[n] = current;
              frontier.push_back(n);
          }
      }
  }
  came_from_to_path(came_from, w.start, w.goal, path);
}

// point for heap
struct PriorityPoint {
  double priority;
  Point point;
};

// comparison for heap - lowest first!
bool operator<(const PriorityPoint & lhs, const PriorityPoint & rhs) {
  return lhs.priority > rhs.priority;
}

// heuristic for A*
double heuristic(const Point & a, const Point & b) {
  return abs(a.row - b.row) + abs(a.col - b.col);
}

// assume cost of moving is always 1
const double move_cost = 1.0;

void pathfind_astar(const World & w, list<Point> & path) {
  path.clear();
  vector<PriorityPoint> frontier;
  map<Point, Point> came_from;
  map<Point, double> cost_so_far;

  frontier.push_back({0.0, w.start});
  push_heap(frontier.begin(), frontier.end());
  cost_so_far[w.start] = 0.0;
  came_from[w.start] = w.start;

  while (!frontier.empty()) {
      pop_heap(frontier.begin(), frontier.end());
      PriorityPoint current = frontier.back();
      frontier.pop_back();

      if (current.point == w.goal) {
          break;
      }
      set<Point> neighbors;
      w.get_neighbors(current.point, neighbors);
      for (auto & n : neighbors) {
          double new_cost = cost_so_far[current.point] + move_cost;
          if (cost_so_far.find(n) == cost_so_far.end() || new_cost < cost_so_far[n]) {
              cost_so_far[n] = new_cost;
              double priority = new_cost + heuristic(n, w.goal);
              frontier.push_back({priority, n});
              push_heap(frontier.begin(), frontier.end());
              came_from[n] = current.point;
          }
      }
  }
  came_from_to_path(came_from, w.start, w.goal, path);
}
