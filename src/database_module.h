#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

namespace DB {

void CreateTransactionsTable(sqlite3 *db);

void SelectTransactions(sqlite3 *db);

void InsertTransaction(sqlite3 *db, int id, std::string title, std::string date,
                       std::string category, double amount);

} // namespace DB

#endif
