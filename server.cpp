#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Dish {
    std::string name;
    int price;
};

// Sample menu data
std::map<std::string, std::vector<Dish>> menu = {
    {"Monday", {{"Appam & Stew", 30}, {"Rice & Chicken Curry", 50}, {"Pulav", 40}}},
    {"Tuesday", {{"Chapati & Dal Curry", 25}, {"Meals", 35}, {"Biriyani", 60}}}
    // Add more days and dishes if needed
};

// Function to read votes from the file (simulating file-based communication)
void load_votes(std::map<std::string, std::vector<std::string>>& votes) {
    std::ifstream file("votes.txt");
    std::string username, dish;

    while (file >> username >> dish) {
        votes[username].push_back(dish);
    }
    file.close();
}

// Function to calculate total expense for a user
int calculate_total_expense(const std::string& username, const std::map<std::string, std::vector<std::string>>& votes) {
    int total_expense = 0;

    if (votes.find(username) != votes.end()) {
        for (const auto& dish_name : votes.at(username)) {
            for (const auto& day : menu) {
                for (const auto& dish : day.second) {
                    if (dish.name == dish_name) {
                        total_expense += dish.price;
                    }
                }
            }
        }
    }
    return total_expense;
}

int main() {
    std::map<std::string, std::vector<std::string>> votes;

    // Load votes from the file
    load_votes(votes);

    // Example: Get total expense for a user
    std::string username;
    std::cout << "Enter username to check total expense: ";
    std::cin >> username;

    int total = calculate_total_expense(username, votes);
    std::cout << "Total Expense for " << username << ": " << total << " ₹\n";

    return 0;
}
