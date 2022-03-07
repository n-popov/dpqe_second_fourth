// Регулярные выражения
// шаблоны, по которым производится поиск в тексте

#include <regex>
#include <iostream>

std::vector<std::string> search(const std::regex& pattern,
                                const std::string& text) {
    auto begin = std::sregex_iterator(std::begin(text),
                                      std::end(text), pattern);
    auto end = std::sregex_iterator();
    std::vector<std::string> results(std::distance(begin, end));
    std::transform(begin, end, std::back_inserter(results), [](auto x){
        return x.str();
    });
    auto it = std::remove_if(std::begin(results), std::end(results), [](auto item) {
        return item.empty();
    });
    results.erase(it, std::end(results));
    return results;
}

int main() {
//    std::regex pattern(R"(\d+\.\d+)");

    std::regex pattern(R"((\+7|8)(\([4983]\d{2}\)|[4983]\d{2})[0-9]{3}((\s|\-)?\d{2}){2})");

    std::string text = "sforgje arig earg +7900000-00-00 dfmpa +734241"
                       " +80000000000 2341241241wfm fgerg wfwertrt"
                       "+7 000000000 +73000000000 +75000000000"
                       "89000000000 +7(910)555-55-00";
//    std::string text = "BTCRUB: 4328403.0\n"
//                       "ETHRUB: 292138.2\n"
//                       "XRPRUB: 83.88\n"
//                       "BNBRUB: 42015.0\n"
//                       "BUSDRUB: 110.5\n"
//                       "USDTRUB: 110.53\n"
//                       "LTCRUB: 11374.2\n"
//                       "ADARUB: 94.82\n"
//                       "DOGERUB: 13.65\n"
//                       "SHIBRUB: 0.0005773\n"
//                       "MATICRUB: 163.8\n"
//                       "DOTRUB: 1918.0\n"
//                       "SOLRUB: 9853.0\n"
//                       "ICPRUB: 4589.0\n"
//                       "TRURUB: 19.88\n"
//                       "WAVESRUB: 1190.49\n"
//                       "ARPARUB: 7.744\n"
//                       "FTMRUB: 181.8\n"
//                       "NURUB: 41.13\n"
//                       "ALGORUB: 84.3\n"
//                       "NEORUB: 2373.0\n"
//                       "NEARRUB: 1151.0";

    auto search_result = search(pattern, text);
    for(const auto& item: search_result) {
        std::cout << item << ' ';
    }
}