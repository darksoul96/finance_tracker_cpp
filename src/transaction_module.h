#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction {
public:
  int id;
  std::string title;
  std::string date;
  std::string category;
  double amount;

  Transaction(int id, std::string title, std::string date, std::string category,
              double amount) {
    this->id = id;
    this->title = title;
    this->date = date;
    this->category = category;
    this->amount = amount;
  }
};
#endif
