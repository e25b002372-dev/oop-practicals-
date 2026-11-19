#include <iostream>
#include <string>
class Settings {
    Settings() = default;
public:
    Settings(const Settings&) = delete;
    Settings& operator=(const Settings&) = delete;
    static Settings& instance() { static Settings settings; return settings; }
    std::string theme = "light";
};
int main() {
    auto& editor = Settings::instance(); auto& preview = Settings::instance();
    std::cout << "Before: " << preview.theme << '\n'; editor.theme = "dark";
    std::cout << "After editor change: " << preview.theme << "\nSame object: " << std::boolalpha << (&editor == &preview) << '\n';
}
