#include "../includes/GroceryItem.hpp"

GroceryItem::GroceryItem(const std::string& name, const int& quantity,
                         const float& pricePer, const bool& taxable) {
    this->isTaxable_ = taxable;
    this->name_ = name;
    this->quantity_ = quantity;
    this->unitPrice_ = pricePer;
}

std::string GroceryItem::getName() const { return name_; }

int GroceryItem::getQuantity() const { return quantity_; }

float GroceryItem::getUnitPrice() const { return unitPrice_; }

bool GroceryItem::isTaxable() const { return isTaxable_; }

std::ostream& operator<<(std::ostream& os, const GroceryItem& item) {
    os << "Item: " << item.name_ << std::endl;
    os << "Amount: " << item.quantity_ << std::endl;
    os << "Unit Price: " << item.unitPrice_ << std::endl;
    os << "Taxable: " << (item.isTaxable_ ? "true" : "false") << std::endl;
    return os;
}

bool operator==(const GroceryItem& a, const GroceryItem& b) {
    return a.name_ == b.name_ && a.quantity_ == b.quantity_ &&
           a.unitPrice_ == b.unitPrice_ && a.isTaxable_ == b.isTaxable_;
}

bool operator==(const GroceryItem& a, std::string _name) {
    return a.name_ == _name;
}
bool operator!=(const GroceryItem& a, std::string _name) {
    return !operator==(a, _name);
}

bool operator!=(const GroceryItem& a, const GroceryItem& b) {
    return !operator==(a, b);
}

