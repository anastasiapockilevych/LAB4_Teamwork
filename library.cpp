#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    int year;
};

std::vector<Book> library;

void addBook() {
    Book book;
    std::cin.ignore(); // Очищення буфера
    std::cout << "Назва книги: ";
    std::getline(std::cin, book.title);
    std::cout << "Автор: ";
    std::getline(std::cin, book.author);
    std::cout << "Рік видання: ";
    std::cin >> book.year;
    library.push_back(book);
    std::cout << "Книгу додано!\n";
}

void showBooks() {
    if (library.empty()) {
        std::cout << "Бібліотека порожня.\n";
        return;
    }
    for (size_t i = 0; i < library.size(); ++i) {
        std::cout << i + 1 << ". " << library[i].title << " — " << library[i].author << ", " << library[i].year << "\n";
    }
}

void saveToFile(const std::string& filename) {
    std::ofstream out(filename);
    for (const auto& book : library) {
        out << book.title << ";" << book.author << ";" << book.year << "\n";
    }
    out.close();
}

void loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return;
    Book book;
    std::string line;
    while (std::getline(in, line)) {
        size_t pos1 = line.find(';');
        size_t pos2 = line.rfind(';');
        if (pos1 != std::string::npos && pos2 != std::string::npos && pos1 != pos2) {
            book.title = line.substr(0, pos1);
            book.author = line.substr(pos1 + 1, pos2 - pos1 - 1);
            book.year = std::stoi(line.substr(pos2 + 1));
            library.push_back(book);
        }
    }
    in.close();
}

void searchBook() {
    std::cin.ignore();
    std::string keyword;
    std::cout << "Введіть назву або частину назви: ";
    std::getline(std::cin, keyword);
    bool found = false;
    for (const auto& book : library) {
        if (book.title.find(keyword) != std::string::npos) {
            std::cout << book.title << " — " << book.author << ", " << book.year << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Книг не знайдено.\n";
    }
}

int main() {
    const std::string filename = "library.txt";
    loadFromFile(filename);
    int choice;
    do {
        std::cout << "\n==== Домашня бібліотека ====\n";
        std::cout << "1. Додати книгу\n";
        std::cout << "2. Показати всі книги\n";
        std::cout << "3. Пошук книги\n";
        std::cout << "4. Вихід\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1: addBook(); break;
        case 2: showBooks(); break;
        case 3: searchBook(); break;
        case 4: saveToFile(filename); break;
        default: std::cout << "Невірний вибір.\n";
        }
    } while (choice != 4);

    return 0;
}