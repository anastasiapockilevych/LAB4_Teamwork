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

void searchByTitle(const std::vector<Book>& library, const std::string& title) {
    bool found = false;
    for (const Book& b : library) {
        if (b.title.find(title) != std::string::npos) {
            std::cout << b.title << " - " << b.author << " (" << b.year << "), "
                      << b.genre << ", " << (b.isRead ? "прочитана" : "не прочитана") << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Книг з такою назвою не знайдено.\n";
    }
}

int main() {
    std::vector<Book> library;
    int choice;
    do {
        std::cout << "\n1. Додати книгу\n2. Переглянути всі книги\n3. Пошук за назвою\n4. Вийти\nВибір: ";
        std::cin >> choice;
        std::cin.ignore(); // очищення буфера
        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                showBooks(library);
                break;
            case 3: {
                std::string searchTitle;
                std::cout << "Введіть назву (або частину): ";
                std::getline(std::cin, searchTitle);
                searchByTitle(library, searchTitle);
                break;
            }
            case 4:
                std::cout << "До побачення!\n";
                break;
            default:
                std::cout << "Невірний вибір.\n";
        }
    } while (choice != 4);

    return 0;
}