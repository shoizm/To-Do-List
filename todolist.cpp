#include <iostream>
#include <ostream>
#include <string>
#include <vector>

std::vector<std::string> List;

void addTask(std::vector<std::string> &List);
void removeTask(std::vector<std::string> &List);
void viewTask(std::vector<std::string> &List);
void markTask(std::vector<std::string> &List);

int main() {

  while (true) {
    std::cout << "--------------------" << std::endl;
    std::cout << "1. Add a task\n"
                 "2. Remove a task\n"
                 "3. View all tasks\n"
                 "4. Mark a task as complete\n"
                 "5. Exit\n";
    std::cout << "--------------------" << std::endl;
    int action = 0;
    std::cin >> action;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      continue;
    }
    std::cin.ignore(1000, '\n');

    switch (action) {
    case 1:
      addTask(List);
      break;

    case 2:
      removeTask(List);
      break;

    case 3:
      viewTask(List);
      break;

    case 4:
      markTask(List);
      break;

    case 5:
      std::cout << "You have exited the To-Do List." << std::endl;
      std::cout << "--------------------\n" << std::endl;
      return 0;
    }
  }
}

void addTask(std::vector<std::string> &List) {
  std::string tasks;

  std::cout << "Type to add a task:" << std::endl;
  std::getline(std::cin, tasks);
  List.push_back(tasks);
}

void removeTask(std::vector<std::string> &List) {

  if (List.empty()) {
    std::cout << "--------------------" << std::endl
              << "There is nothing to remove." << std::endl;
    return;
  }

  std::cout << "--------------------" << std::endl;
  for (int i = 0; i < List.size(); i++) {
    std::cout << i + 1 << ". " << List[i] << std::endl;
  }

  std::cout << "--------------------" << std::endl
            << "Select a number from the list to remove a task:" << std::endl;
  int num;
  std::cin >> num;
  int index = num - 1;

  List.erase(List.begin() + index);
  std::cout << "Removed task #:" << num << std::endl;
  return;
}

void viewTask(std::vector<std::string> &List) {

  if (List.empty()) {

    std::cout << "--------------------" << std::endl
              << "You currently have no tasks." << std::endl;
    return;
  }

  std::cout << "--------------------" << std::endl;

  for (int i = 0; i < List.size(); i++) {
    std::cout << i + 1 << ". " << List[i] << std::endl;
  }
}

void markTask(std::vector<std::string> &List) {}