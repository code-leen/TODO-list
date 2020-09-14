#include "TodoList.h"
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{ 
  TodoList userTodoList;
    
  string firstarg = argv[1];

  if (firstarg == "add")
  {
    string duedate = argv[2];
    string task = argv[3];
          
    userTodoList.add(duedate, task);
  }
      
  else if (firstarg ==  "remove")
  {
    string task = argv[2];
    userTodoList.remove(task);
  }
  
  else if (firstarg ==  "printList")
  {
    userTodoList.printTodoList();
  }
  
  else if (firstarg ==  "printDay")
  {
    string duedate = argv[2];
    userTodoList.printDaysTasks(duedate);
  }

  return 0;
}