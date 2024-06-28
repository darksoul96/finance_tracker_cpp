#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction {
public:
  int id;
  static int current_id;
  std::string title;
  std::string date;
  std::string category;
  double amount;

  Transaction(std::string title, std::string date, std::string category,
              double amount) {
    this->id = this->current_id++;
    this->title = title;
    this->date = date;
    this->category = category;
    this->amount = amount;
  }
};
#endif
