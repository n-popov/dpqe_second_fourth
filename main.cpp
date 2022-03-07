#include <iostream>
#include <fstream>

// Библиотека для работы с файлами
#include <filesystem>

// Какие действия можно производить с файлами программно?
// Читать, писать
// Копировать, создавать, удалять
// Итерироваться по директории (в т.ч. рекурсивно)


int main() {
    std::filesystem::path parent_directory("..");

    auto filepath = parent_directory / "main.cpp";
//    auto filepath = std::filesystem::path("../main.cpp"); // То же самое

    std::cout << std::filesystem::absolute(filepath) << std::endl;
    std::cout << std::filesystem::relative(filepath) << std::endl;

    auto new_path = parent_directory / "copied.cpp";
    std::filesystem::copy(filepath, new_path);
    std::fstream fin(new_path, std::ios::in);
    for(std::string line; std::getline(fin, line);) {
        std::cout << line << std::endl;
    }
    fin.close();
    std::filesystem::remove(new_path);

    std::filesystem::directory_iterator begin(parent_directory / "cmake-build-debug");
    std::filesystem::directory_iterator end;

    for(auto it = begin; it != end; it++) {
        auto path = it->path();
        if (is_directory(path)) {
            std::cout << path.filename();
        } else {
            std::cout << path.stem() << path.extension() << std::endl;
        }
    }

    return 0;
}
