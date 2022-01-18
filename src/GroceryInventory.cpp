#include "../includes/GroceryInventory.hpp"

#include <algorithm>
#include <iterator>
#include <numeric>

GroceryInventory::GroceryInventory() {}
// GroceryInventory::GroceryInventory(const GroceryInventory& invent){}

void GroceryInventory::addEntry(const GroceryItem& item) {
    inventory_.push_back(item);
}

void GroceryInventory::addEntry(const std::string& n, const int& p,
                                const float& q, const bool& tf) {
    this->inventory_.emplace_back(GroceryItem(n, p, q, tf));
}

std::vector<GroceryItem>::iterator GroceryInventory::getInventoryEnd() {
    return this->inventory_.end();
}

std::ostream& operator<<(std::ostream& os, const GroceryInventory& invent) {
    for (GroceryItem item : invent.inventory_) {
        os << item << std::endl;
    }
    return os;
}

void GroceryInventory::createListFromFile(const std::string& filePath) {
    std::string line;
    std::ifstream source(filePath);

    if (source.is_open()) {
        while (std::getline(source, line)) {
            std::stringstream ss(line);

            std::string name;
            float price;
            int quantity;
            bool canTax;

            while (ss >> name >> quantity >> price >> canTax) {
                GroceryItem item(name, quantity, price, canTax);
                this->addEntry(item);
                ss.clear();
            }
        }
    } else {
        throw std::invalid_argument("Could not open file, cowardly refusing");
    }
    source.close();
}

bool operator==(const GroceryInventory& a, const GroceryInventory& b) {
    return (a.inventory_.size() == b.inventory_.size() &&
            a.inventory_ == b.inventory_);
}

bool operator!=(const GroceryInventory& a, const GroceryInventory& b) {
    return !operator==(a, b);
}

GroceryInventory GroceryInventory::operator=(const GroceryInventory& invent) {
    this->inventory_ = invent.inventory_;
    return *this;
}

std::vector<GroceryItem>::iterator GroceryInventory::getEntry(
    std::string name) {
    return std::find_if(std::begin(this->inventory_),
                        std::end(this->inventory_),
                        [&name](GroceryItem& item) { return item == name; });
}

float GroceryInventory::calculateUnitRevenue() const {
    return std::accumulate(
        std::begin(this->inventory_), std::end(this->inventory_), 0.0,
        [](const float& lhs, GroceryItem rhs) {
            return lhs + rhs.getUnitPrice() * rhs.getQuantity();
        });
}

float GroceryInventory::calculateTaxRevenue() const {
    float _taxRate = this->taxRate_;
    return std::accumulate(
        std::begin(this->inventory_), std::end(this->inventory_), 0.0,
        [&_taxRate](const float& lhs, GroceryItem item) {
            float _amount =
                item.isTaxable()
                    ? item.getQuantity() * item.getUnitPrice() * _taxRate
                    : 0;
            return lhs + _amount;
        });
}

float GroceryInventory::calculateTotalRevenue() const {
    return this->calculateUnitRevenue() + this->calculateTaxRevenue();
}

void GroceryInventory::setTaxRate(const float& rate) {
    this->taxRate_ = rate * 0.01;
}

float GroceryInventory::getTaxRate() const { return this->taxRate_; }

GroceryItem& GroceryInventory::operator[](size_t index) {
    return inventory_.at(index);
}

GroceryItem GroceryInventory::operator[](size_t index) const {
    return inventory_.at(index);
}

void GroceryInventory::createFileFromInventory(const std::string& path) {
    std::ofstream writing(path);

    if (writing.is_open()) {
        for (auto item : this->inventory_) {
            writing << "This is broken lol" << std::endl;
            //writing << "Item: " << item.getName() << "\n";
            //writing << "Amount: " << item.getQuantity() << "\n";
            //writing << "Unit Price: " << item.getUnitPrice() << std::endl;
            //writing << "Taxable: " << item.isTaxable() << "\n";
            //writing << "\n";
        }

        writing.close();
    } else {
        throw std::invalid_argument(
            "File exists currently, cowardly refusing to override");
    }
}

GroceryInventory::GroceryInventory(std::string manifest) {
    createListFromFile(manifest);
}

size_t GroceryInventory::size() const { return inventory_.size(); }
