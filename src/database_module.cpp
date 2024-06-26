#include "database_module.h"
#include <iostream>

void CreateTransactionsTable(sqlite3 *db) {
  sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS transactions", NULL, NULL, NULL);
}

void SelectTransactions(sqlite3 *db) {
  int rc = sqlite3_exec(db, "SELECT * FROM transactions", NULL, NULL, NULL);
  if (rc != SQLITE_OK) {
    sqlite3_free(0);
  }

  std::cout << "Successfully queried database" << std::endl;
}

void InsertTransaction(sqlite3 *db, int id, std::string title, std::string date,
                       std::string category, double amount) {
  std::string sql = "INSERT INTO transactions VALUES (" + title + "', '" +
                    date + "', '" + category + "', " + std::to_string(amount) +
                    ");";
  sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}
