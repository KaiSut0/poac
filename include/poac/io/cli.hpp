#ifndef POAC_IO_CLI_HPP
#define POAC_IO_CLI_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>


namespace poac::io::cli {
    // Clear screen
    static const std::string clr_screen = "\x1b[2J";
    // Clear from the cursor position to the right end
    static const std::string clr_right = "\x1b[0K";
    // Clear from the cursor position to the left end
    static const std::string clr_left = "\x1b[1K";
    // Clear the line at the cursor position
    static const std::string clr_line = "\x1b[2K";
    // Move cursor position
    const std::string up(unsigned int y)    { return "\x1b["+std::to_string(y)+"A"; }
    const std::string down(unsigned int y)  { return "\x1b["+std::to_string(y)+"B"; }
    const std::string right(unsigned int x) { return "\x1b["+std::to_string(x)+"C"; }
    const std::string left(unsigned int x)  { return "\x1b["+std::to_string(x)+"D"; }
    const std::string location(unsigned int x, unsigned int y) {
        return "\x1b["+std::to_string(x)+";"+std::to_string(y)+"H";
    }

    void rel_mv(int x=0, int y=0) {
        if (x > 0) std::cout << right(x);
        else       std::cout << left(-x);
        if (y > 0) std::cout << up(y);
        else       std::cout << down(-y);
    }

    void set_left(const int&& n) { std::cout << std::setw(n) << std::left; }

    static const std::string red = "\x1b[31m";
    static const std::string green = "\x1b[32m";
    static const std::string yellow = "\x1b[33m";
    static const std::string blue = "\x1b[34m";
    static const std::string bold = "\x1b[1m";
    static const std::string underline = "\x1b[4m";
    static const std::string reset = "\x1b[0m";

    const std::vector<std::string> spinners{ "⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏" };
} // end namespace

#endif // !POAC_IO_CLI_HPP
