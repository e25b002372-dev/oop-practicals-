#include <iostream>
#include <memory>
#include <string>
struct Panel { std::shared_ptr<const std::string> theme; };
int main() {
    for (int i = 0; i < 1000; ++i) {
        auto value = std::make_unique<int>(42);
        auto owner = std::move(value);
        Panel editor{std::make_shared<const std::string>("dark")};
        if (!i) std::cout << "Moved unique value: " << *owner << '\n';
        {
            Panel preview{editor.theme};
            if (!i) std::cout << "Preview theme: " << *preview.theme << "; owners: " << preview.theme.use_count() << '\n';
        }
        if (!i) std::cout << "Owners after preview closes: " << editor.theme.use_count() << '\n';
    }
    std::cout << "Completed 1000 scopes\n";
}
