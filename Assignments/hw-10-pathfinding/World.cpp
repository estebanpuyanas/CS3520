#include "World.hpp"
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;


void World::initialize(int worldId) {
  mt19937 mt_rand(worldId);

  size = 10 + int(mt_rand() % 10);

  start = { int(mt_rand() % size), int(mt_rand() % size) };
  do {
    goal = { int(mt_rand() % size), int(mt_rand() % size) };
  } while(start == goal);

  int nblocks = size * size / 3;
  for (int ii = 0; ii < nblocks; ++ ii) {
    Point block = { int(mt_rand() % size), int(mt_rand() % size) };
    if (block != start && block != goal) {
      blocks.insert(block);
    }
  }
}

void World::display(const std::list<Point> & path) const {
  std::set<Point> pathPoints(path.begin(), path.end());
  for (int r = 0; r < size; ++r) {
      for (int c = 0; c < size; ++c) {
          Point cur(r, c);
          bool onPath = (pathPoints.find(cur) != pathPoints.end());
          char ch = ' ';
          if (blocks.find(cur) != blocks.end()) {
              ch = onPath ? 'x' : 'X';
          } else if (cur == start) {
              ch = onPath ? 's' : 'S';
          } else if (cur == goal) {
              ch = onPath ? 'g' : 'G';
          } else if (onPath) {
              ch = '.';
          }
          std::cout << ch << (c < size - 1 ? " " : "");
      }
      std::cout << "\n";
  }
}

void World::get_neighbors(const Point & p, std::set<Point> & neighbors) const {
  neighbors.clear();
  // if p is off the world or is a block, it has no neighbors
  if (p.row < 0 || p.row >= size || p.col < 0 || p.col >= size ||
      blocks.find(p) != blocks.end()) {
      return;
  }
  // potential neighbors (up, down, left, right)
  static const int dRow[] = {-1, 1, 0, 0};
  static const int dCol[] = {0, 0, -1, 1};
  for (int i = 0; i < 4; ++i) {
      int nr = p.row + dRow[i];
      int nc = p.col + dCol[i];
      Point neighbor(nr, nc);
      if (nr >= 0 && nr < size && nc >= 0 && nc < size &&
          blocks.find(neighbor) == blocks.end()) {
          neighbors.insert(neighbor);
      }
  }
}
