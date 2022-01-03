#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>
#include <string>

class Graph {
 private:
  int size;
  std::vector<std::list<int> > adj_list;
  std::vector<char>            labels;
  void                         Depthfirst(int);

  std::vector <char> pos;
  std::string current;

 public:
  Graph(const char* filename);
  ~Graph();
  int  Getsize() const;
  void Traverse();
  void Print() const;
};

#endif  // GRAPH_H
