//
// Created by user on 13.05.2024.
//
#include <iostream>
#include <string>
#include <vector>

struct CommandSet{
 private:
  std::vector<std::pair<std::string, double>> mem;
  double value = 0;
  int CommandNumber = 0;
 public:
  CommandSet() = default;
  ~CommandSet() = default;
  void Append(const std::string &a, const double &b){
    if (a == "ADD" || a == "SUB" || a == "MUL" || a == "DIV") {
      mem.emplace_back(a, b);
      Complete(a, b);
    }
    //else
      //Recall((int)b);
  }

  /*void Recall(int N){
    //TODO: if n value is very high it is possible that it deletes more than one command set, maybe make it as independent void
    CommandNumber -= N;
  }*/

  void Complete(const std::string &a, const double &b){
    if (a == "ADD") value += b;
    else if(a == "SUB") value -= b;
    else if (a == "MUL") value *= b;
    else value /= b;
  }

  [[nodiscard]] int CommN() const {return CommandNumber;}

  void Resize(double &N){
    CommandNumber = abs((int)N);
  }

  double Get(){
    return value;
  }
};

std::vector<CommandSet> buf;

void Rev(double &N){
  while (!buf.empty()){
    N -= buf[buf.size() - 1].CommN();
    if (N < 0) {
      buf[buf.size() - 1].Resize(N);
      break;
    }
    else
      buf.pop_back();
  }
}

int main(){
  std::string command;
  double number;
  while (std::cin >> command && std::cin >> number){
    if (command == "OUT") {
      CommandSet set = CommandSet();
      buf.emplace_back(set);
    }
    else{
      if (command == "REV")
        Rev(number);
      else
        buf[buf.size() - 1].Append(command, number);
    }
    std::cout << buf[buf.size() - 1].Get() << "\n";
    std::cout << command << ' ' << number << "\n";
  }
}