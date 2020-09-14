#include <iostream>
#include "TodoList.h"
using namespace std;

TodoList::TodoList()
{
  ifstream infile("TODOList.txt");
  string line;
  if (infile.is_open())
  {
    int j = 0;
    while (getline (infile,line))
    {
      if (j % 2 == 0)
      {
          days.push_back(line);
      }
      else 
      {
        tasks.push_back(line);
      }
      j++;
    }
    infile.close();
  }
}

TodoList::~TodoList() 
{
  ofstream outfile;
  outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
  for(int i = 0; i < tasks.size(); i++) 
  {
    outfile << days[i] << endl;
    outfile << tasks[i] << endl;
  }
  outfile.close();
}

void TodoList::add(string _duedate, string _task)
{
  days.push_back(_duedate); 
  tasks.push_back(_task);          
}

int TodoList::remove(string _task)
{
  for (int i = 0; i < tasks.size(); i++)
  {
    if (_task == tasks[i])
    {
      tasks.erase(tasks.begin()+i);
      return 1;
    }
  }
  return 0;
}

void TodoList::printTodoList() 
{
  for (int i = 0; i < tasks.size(); i++)
  {
    cout << tasks[i] << endl;
  }  
}

void TodoList::printDaysTasks(string _date)
{
  for (int i = 0; i < days.size(); i++)
  {
    if (days[i] == _date)
    {
    cout << tasks[i] << endl;
    }
  } 
}