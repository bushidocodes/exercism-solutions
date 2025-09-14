#include <string>

namespace log_line {
std::string message(std::string line) {
    auto end_idx = line.find(':');
    if (end_idx == std::string::npos) return "";
    return line.substr(line.find_first_not_of(": ", end_idx));
}

std::string log_level(std::string line) {
    auto end_idx = line.find(':');
    if (end_idx == std::string::npos) return "";
    return line.substr(line.find_first_not_of(" ["), line.find_last_not_of(": ]", end_idx));
}

std::string reformat(std::string line) {
    if (line.find(':') == std::string::npos) return "";
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
