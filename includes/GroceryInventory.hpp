#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "GroceryItem.hpp"

class GroceryInventory {
  public:
   GroceryInventory();
   GroceryInventory operator=(const GroceryInventory& invent);
   GroceryInventory(std::string);
   // GroceryInventory(const GroceryInventory& invent);
   std::vector<GroceryItem>::iterator getEntry(const std::string);

   // GroceryItem& getEntry(const std::string);

   void addEntry(const GroceryItem& item);
   void addEntry(const std::string&, const int&, const float&, const bool&);
   float getTaxRate() const;
   void setTaxRate(const float&);

   void createListFromFile(const std::string&);
   void createFileFromInventory(const std::string&);
   float calculateUnitRevenue() const;
   float calculateTaxRevenue() const;
   float calculateTotalRevenue() const;
   size_t size() const;
   std::vector<GroceryItem>::iterator getInventoryEnd();

   GroceryItem& operator[](size_t);
   GroceryItem operator[](size_t) const;
   friend bool operator==(const GroceryInventory& a, const GroceryInventory& b);
   friend bool operator!=(const GroceryInventory& a, const GroceryInventory& b);
   friend std::ostream& operator<<(std::ostream& os,
                                   const GroceryInventory& invent);
   friend std::ofstream& operator>>(std::ifstream& is,
                                    const GroceryInventory& invent);

  private:
   std::vector<GroceryItem> inventory_;
   float taxRate_ = 0.075;
   size_t size_;
};

