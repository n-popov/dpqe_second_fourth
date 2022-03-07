#include <filesystem>
#include <iostream>
#include <string>

int main() {
    std::filesystem::path root_directory("C:\\");
    // "C:\Users\Nikita\Downloads\banana"
    auto bananas_directory =
            root_directory / "Users" / "Nikita" / "Downloads" / "banana";
    for(std::filesystem::directory_iterator begin(bananas_directory),
                end, it = begin; it != end; it++) {
        auto filename = it->path();
        if (filename.stem().string().find("images") != std::string::npos
            && !filename.has_extension()) {
            auto new_path = bananas_directory / (filename.stem().string() + ".jpg");
            std::filesystem::copy(filename, new_path);
            std::filesystem::remove(filename);
        }
    }

}