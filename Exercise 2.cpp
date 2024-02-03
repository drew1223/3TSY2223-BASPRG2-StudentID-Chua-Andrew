#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::string> fillInventory() {
    std::vector<std::string> inventory;
    std::vector<std::string> itemOptions = {"RedPotion", "Elixir", "EmptyBottle", "BluePotion"};

    std::cout << "Choose 10 items for the inventory:\n";

    for (int i = 0; i < 10; ++i) {
        std::cout << "Item " << (i + 1) << " (choose RedPotion, Elixir, EmptyBottle, or BluePotion): ";
        std::string item;
        std::cin >> item;

        while (std::find(itemOptions.begin(), itemOptions.end(), item) == itemOptions.end()) {
            std::cout << "Invalid item. Please choose RedPotion, Elixir, EmptyBottle, or BluePotion: ";
            std::cin >> item;
        }

        inventory.push_back(item);
    }

    return inventory;
}

void displayInventory(const std::vector<std::string>& inventory) {
    std::cout << "Inventory Items:\n";
    for (const auto& item : inventory) {
        std::cout << item << "\n";
    }
}


int countItem(const std::vector<std::string>& inventory, const std::string& itemToCount) {
    int count = std::count(inventory.begin(), inventory.end(), itemToCount);
    return count;
}


void removeItem(std::vector<std::string>& inventory, const std::string& itemToRemove) {
    inventory.erase(std::remove(inventory.begin(), inventory.end(), itemToRemove), inventory.end());
}

int main() {

    std::vector<std::string> inventory = fillInventory();


    displayInventory(inventory);


    std::string itemToCount;
    std::cout << "\nEnter an item to count in the inventory (RedPotion, Elixir, EmptyBottle, BluePotion): ";
    std::cin >> itemToCount;
    int itemCount = countItem(inventory, itemToCount);
    std::cout << "Number of " << itemToCount << " in the inventory: " << itemCount << "\n";


    std::string itemToRemove;
    std::cout << "\nEnter an item to remove from the inventory (RedPotion, Elixir, EmptyBottle, BluePotion): ";
    std::cin >> itemToRemove;


        std::cout << "Item not found in the inventory. Please choose a valid item: ";
        std::cin >> itemToRemove;
    }

    removeItem(inventory, itemToRemove);

    std::cout << "\nInventory after removing " << itemToRemove << ":\n";
    displayInventory(inventory);

    return 0;
}