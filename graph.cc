#include "graph.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

/***************************************************************
Class destructor
***************************************************************/
Graph::~Graph(){
}

/***************************************************************
get the size of the graph (vertices count)

@return size of graph
***************************************************************/
int Graph::Getsize() const{
  return size;
}

/***************************************************************
Class constructor of graph
This method takes the input file and turns it into a graph in computer memory

@param filename file to get information from
***************************************************************/
Graph::Graph(const char* filename){
  current = "";

  ifstream infile(filename, ios::in);
  string line;
  infile >> size;

  for(int i = 0; i < size; i ++)
  {
    infile >> line;
    labels.push_back(line[0]);
  }

  for(int i = 0; i < size; i ++)
  {
    infile >> line;
    adj_list.push_back(*(new list<int>()));

    for(int j = 0; j < size; j ++){
      int num;
      infile >> num;
      adj_list[i].push_back(num);
    }

  }

}

/***************************************************************
Depth first search method
This method trapverses the graph with depth first search

@param v integer of number to look for
***************************************************************/
void Graph::Depthfirst(int v){
  int count = 0;

  cout << labels[v] << " ";

  pos.push_back(v);

  for(list<int>::iterator it = adj_list[v].begin(); it != adj_list[v].end(); it ++){
    if(*it == 1 && find(pos.begin(),pos.end(), count) == pos.end())
    {
      current += string("(") + labels[v] + string(", ") + labels[count] + string(") ");

      Depthfirst(count);
    }

    count++;
  }
}

/***************************************************************
Helper method for depth first search
This funciton sets up the graph, so depth frist can execute
***************************************************************/
void Graph::Traverse(){
  cout << "------ traverse of graph ------" << endl;

  for(int i = 0; i < size; i++)
  {
    if(find(pos.begin(), pos.end(), i) == pos.end())
      Depthfirst(i);
  }

  cout << endl << current << endl;

  current = "";

  cout << "--------- end of traverse -------" << endl << endl;
}

/***************************************************************
Print method
Fucntion prints the fraph onto the output stream
***************************************************************/
void Graph::Print() const{
  cout << endl << "Number of verticies in the graph: " << size << endl << endl;
  cout << "------ graph ------" << endl;

  for(int i = 0; i < size; i++)
  {
    cout << labels[i] << "; ";
    int count = 0;

    for(list<int>::const_iterator it = adj_list[i].begin(); it !=adj_list[i].end(); it++)
    {
      if(*it == 1){
        cout << labels[count] << ", ";
      }

      count++;
    }

    cout << endl;
  }

  cout << "------ end of graph ------" << endl << endl;
}