#include <iostream>
#include <vector>
#include <string>

struct Book {
    std::string title;
    std::string author;
    int year;
    std::string genre;
    bool isRead;
};

void addBook(std::vector<Book>& library) {
    Book newBook;
    std::cout << "Назва книги: ";
    std::getline(std::cin, newBook.title);
    std::cout << "Автор: ";
    std::getline(std::cin, newBook.author);
    std::cout << "Рік видання: ";
    std::cin >> newBook.year;
    std::cin.ignore(); // очищення буфера
    std::cout << "Жанр: ";
    std::getline(std::cin, newBook.genre);
    char readInput;
    std::cout << "Прочитана (y/n): ";
    std::cin >> readInput;
    newBook.isRead = (readInput == 'y' || readInput == 'Y');
    std::cin.ignore();
    library.push_back(newBook);
    std::cout << "Книгу додано!\n";
}

void showBooks(const std::vector<Book>& library) {
    if (library.empty()) {
        std::cout << "Бібліотека порожня.\n";
        return;
    }
    for (size_t i = 0; i < library.size(); ++i) {
        const Book& b = library[i];
        std::cout << i+1 << ". " << b.title << " - " << b.author << " (" << b.year << "), "
                  << b.genre << ", " << (b.isRead ? "прочитана" : "не прочитана") << "\n";
    }
}