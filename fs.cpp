#include <iterator>
#include <iostream>
#include <fstream>
#include <filesystem>

int main() {
    try {
        std::filesystem::path parent_directory("..");
        auto main_filepath = parent_directory / "main.cpp";
        auto copy_filepath = parent_directory / "copied.cpp";
        std::filesystem::copy(main_filepath, copy_filepath);
        std::cout << "Full main filepath: " << std::filesystem::absolute(main_filepath) << std::endl;
        std::cout << "Relative main filepath: " << std::filesystem::relative(main_filepath) << std::endl;
        auto directory = parent_directory / "cmake-build-debug";
        for(const auto& element : std::filesystem::directory_iterator(directory)) {
            auto element_is_directory = element.is_directory();
            std::cout << element << ' ' << std::boolalpha << element_is_directory << std::endl;
            if (!element_is_directory) {
                std::cout << element.path().stem() << ' ' << element.path().extension() << std::endl;
            }

        }
        std::fstream in(copy_filepath, std::ios::in);
        std::copy(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>(),
                  std::ostream_iterator<std::string>(std::cout, "\n"));
        in.close();
    std::filesystem::remove(copy_filepath);
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

}
