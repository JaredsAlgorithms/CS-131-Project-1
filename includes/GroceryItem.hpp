#pragma once
#include <iostream>
#include <string>

class GroceryItem {
 public:
  GroceryItem(){};
  GroceryItem(const std::string&, const int&, const float&, const bool&);

  std::string getName() const;
  bool isTaxable() const;
  float getUnitPrice() const;
  int getQuantity() const;

  friend std::ostream& operator<<(std::ostream&, const GroceryItem&);
  friend bool operator==(const GroceryItem&, const GroceryItem&);
  friend bool operator!=(const GroceryItem&, const GroceryItem&);

  friend bool operator==(const GroceryItem&, std::string);
  friend bool operator!=(const GroceryItem&, std::string);

 private:
  std::string name_;
  int quantity_;
  float unitPrice_;
  bool isTaxable_;
};

