//
// Created by nevemlaci on 14/07/2024.
//

#pragma once
#include <stdexcept>
#include <string>

using std::literals::string_literals::operator ""s;

namespace SDL{
    class Exception final : public std::runtime_error{
        explicit Exception(const std::string& what) : std::runtime_error("[SDL Exception]: "s + what) {}
    };
}
