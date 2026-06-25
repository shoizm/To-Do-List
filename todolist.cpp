#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Task {
  std::string desc;
  bool completed;
};

std::vector<Task> List;

void addTask(std::vector<Task> &List);
void removeTask(std::vector<Task> &List);
void viewTask(std::vector<Task> &List);
void markTask(std::vector<Task> &List);
void loadTask(std::vector<Task> &List);
void saveTask(std::vector<Task> &List);

int main() {
  loadTask(List);

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
      saveTask(List);
      std::cout << "You have exited the To-Do List." << std::endl;
      std::cout << "--------------------\n" << std::endl;
      return 0;
    }
  }
}

void addTask(std::vector<Task> &List) {
  Task addtask;
  std::string tasks;

  std::cout << "--------------------\n" << "Type to add a task:" << std::endl;
  std::getline(std::cin, tasks);
  addtask.desc = tasks;
  addtask.completed = false;
  List.push_back(addtask);
  std::cout << "--------------------\n" << "Added task." << std::endl;
}

void removeTask(std::vector<Task> &List) {
  if (List.empty()) {
    std::cout << "--------------------" << std::endl
              << "There is nothing to remove." << std::endl;
    return;
  }

  std::cout << "--------------------\n" << "TASKS:" << std::endl;
  for (int i = 0; i < List.size(); i++) {
    std::cout << i + 1 << ". " << (List[i].desc) << std::endl;
  }

  std::cout << "--------------------" << std::endl
            << "Select a number from the list to remove a task:" << std::endl;
  int num;
  std::cin >> num;
  int index = num - 1;

  List.erase(List.begin() + index);
  std::cout << "--------------------\n"
            << "Removed task #:" << num << std::endl;
  return;
}

void viewTask(std::vector<Task> &List) {
  Task readtask;

  if (List.empty()) {

    std::cout << "--------------------" << std::endl
              << "You currently have no tasks." << std::endl;
    return;
  }

  std::cout << "--------------------\n" << "TASKS:" << std::endl;

  for (int i = 0; i < List.size(); i++) {
    std::cout << i + 1 << ". "
              << (List[i].completed ? "[Completed] " : "[Not Completed] ")
              << List[i].desc << std::endl;
  }
}

void markTask(std::vector<Task> &List) {
  if (List.empty()) {
    std::cout << "There are currently no tasks to mark as completed!"
              << std::endl;
    return;
  }

  std::cout << "--------------------\n" << "TASKS: " << std::endl;

  for (int i = 0; i < List.size(); i++) {
    std::cout << i + 1 << ". "
              << (List[i].completed ? "[Completed]" : "[Not Completed]")
              << List[i].desc << std::endl;
  }

  std::cout << "Select a task from the list to mark as completed.\n"
            << "--------------------" << std::endl;
  int num;
  std::cin >> num;
  int i = num - 1;
  List[i].completed = true;

  std::cout << "--------------------\n"
            << "Task: #" << num << " has been completed." << std::endl;
}

void loadTask(std::vector<Task> &List) {
  std::ifstream inputFile("tasks.txt");

  if (!inputFile.is_open()) {
    std::cout << "File could not open!" << std::endl;
    return;
  }

  std::string tasks;
  while (std::getline(inputFile, tasks)) {
    int colonPos = tasks.find(':');
    std::string taskCompleted = tasks.substr(0, colonPos);
    std::string taskDescription = tasks.substr(colonPos + 1);

    Task t;
    t.completed = (taskCompleted == "1");
    t.desc = taskDescription;
    List.push_back(t);
  }
  inputFile.close();
}

void saveTask(std::vector<Task> &List) {
  std::ofstream outputfile("tasks.txt");

  for (int i = 0; i < List.size(); i++) {
    outputfile << List[i].completed << ":" << List[i].desc << std::endl;
  }
  outputfile.close();
}