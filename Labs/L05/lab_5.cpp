#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

// Mostrar el inventario
void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

// Agregar o actualizar un producto en el inventario
void addOrUpdateProduct(std::map<std::string, int>& inventory, const std::string& product, int quantity) {
    inventory[product] += quantity;
    std::cout << "Updated inventory: " << product << " now has " << inventory[product] << " in stock.\n\n";
}

// Mostrar categorías
void displayCategories(const std::set<std::string>& categories) {
    std::cout << "\nProduct Categories:\n";
    for (const auto& category : categories) {
        std::cout << "- " << category << "\n";
    }
    std::cout << std::endl;
}

// Agregar una categoría
void addCategory(std::set<std::string>& categories, const std::string& category) {
    if (categories.insert(category).second) {
        std::cout << "Category '" << category << "' added successfully.\n";
    } else {
        std::cout << "Category '" << category << "' already exists.\n\n";
    }
}

// Agregar pedido a la cola
void addOrder(std::queue<std::string>& orders, const std::string& order) {
    orders.push(order);
    std::cout << "Added to queue: " << order << std::endl;
}

// Procesar pedidos
void processOrders(std::queue<std::string>& orders) {
    std::cout << "\nProcessing orders:\n";
    while (!orders.empty()) {
        std::cout << "Processing " << orders.front() << std::endl;
        orders.pop();
    }
}

// Agregar un lote de reabastecimiento
void addRestock(std::stack<std::pair<std::string, int>>& restocks, const std::string& product, int quantity) {
    restocks.push({product, quantity});
    std::cout << "Added restock batch: " << quantity << " units of " << product << std::endl;
}

// Procesar reabastecimientos y actualizar inventario
void processRestocks(std::stack<std::pair<std::string, int>>& restocks, std::map<std::string, int>& inventory) {
    std::cout << "\nProcessing restocks:\n";
    while (!restocks.empty()) {
        auto item = restocks.top();
        inventory[item.first] += item.second;
        std::cout << "Restocked " << item.second << " units of " << item.first << std::endl;
        restocks.pop();
    }
}

// Agregar productos al carrito del cliente
void addToCart(std::vector<std::string>& cart, const std::string& product) {
    cart.push_back(product);
    std::cout << "Added to cart: " << product << std::endl;
}

// Mostrar productos en el carrito
void displayCart(const std::vector<std::string>& cart) {
    std::cout << "\nItems in customer cart:\n";
    for (const auto& item : cart) {
        std::cout << "- " << item << "\n";
    }
    std::cout << std::endl;
}

int main() {
    std::map<std::string, int> inventory = {{"Laptop", 5}, {"Mouse", 20}, {"Keyboard", 10}};
    displayInventory(inventory);

    // Actualizar inventario
    addOrUpdateProduct(inventory, "Mouse", 5);
    addOrUpdateProduct(inventory, "Headphones", 15);

    // Categorías de productos
    std::set<std::string> productCategories;
    addCategory(productCategories, "Electronics");
    addCategory(productCategories, "Accessories");
    addCategory(productCategories, "Peripherals");
    addCategory(productCategories, "Electronics");  // Intento duplicado
    displayCategories(productCategories);

    // Procesar pedidos
    std::queue<std::string> orders;
    addOrder(orders, "Order#1: Laptop");
    addOrder(orders, "Order#2: Mouse");
    addOrder(orders, "Order#3: Keyboard");
    processOrders(orders);

    // Reabastecer inventario
    std::stack<std::pair<std::string, int>> restocks;
    addRestock(restocks, "Mouse", 10);
    addRestock(restocks, "Laptop", 2);
    addRestock(restocks, "Keyboard", 5);
    processRestocks(restocks, inventory);  // Se actualiza el inventario
    displayInventory(inventory);  // Se muestra el inventario actualizado

    // Carrito de compras
    std::vector<std::string> customerCart;
    addToCart(customerCart, "Laptop");
    addToCart(customerCart, "Mouse");
    addToCart(customerCart, "Keyboard");
    displayCart(customerCart);

    return 0;
}
