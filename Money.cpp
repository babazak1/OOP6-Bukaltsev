#include "pch.h"
#include "Moneydll.h"
#include <cmath>
#include <string>

namespace MoneyOperations
{
    void Money::normalize()
    {
        if (kopiyky >= 100)
        {
            hryvnias += kopiyky / 100;
            kopiyky %= 100;
        }

        if (hryvnias < 0 && kopiyky > 0)
        {
            hryvnias += 1;
            kopiyky = 100 - kopiyky;
        }
    }

    Money::Money() : hryvnias(0), kopiyky(0) {}

    Money::Money(long hryvnias, unsigned char kopiyky)
        : hryvnias(hryvnias), kopiyky(kopiyky)
    {
        normalize();
    }

    Money::Money(double amount)
    {
        hryvnias = static_cast<long>(amount);
        double fractional = std::abs(amount - hryvnias);
        kopiyky = static_cast<unsigned char>(std::round(fractional * 100));
        normalize();
    }

    Money Money::operator+(const Money& other) const
    {
        long totalHryvnias = hryvnias + other.hryvnias;
        int totalKopiyky = kopiyky + other.kopiyky;

        Money result(totalHryvnias, static_cast<unsigned char>(totalKopiyky));
        result.normalize();
        return result;
    }

    Money Money::operator-(const Money& other) const
    {
        long totalHryvnias = hryvnias - other.hryvnias;
        int totalKopiyky = kopiyky - other.kopiyky;

        Money result(totalHryvnias, static_cast<unsigned char>(totalKopiyky));
        result.normalize();
        return result;
    }

    Money Money::operator*(double multiplier) const
    {
        double total = toDouble() * multiplier;
        return Money(total);
    }

    Money Money::operator/(double divisor) const
    {
        if (divisor == 0.0)
            throw std::invalid_argument("Division by zero!");

        double total = toDouble() / divisor;
        return Money(total);
    }

    double Money::operator/(const Money& other) const
    {
        if (other.toDouble() == 0.0)
            throw std::invalid_argument("Division by zero money!");

        return toDouble() / other.toDouble();
    }

    bool Money::operator==(const Money& other) const
    {
        return hryvnias == other.hryvnias && kopiyky == other.kopiyky;
    }

    bool Money::operator!=(const Money& other) const
    {
        return !(*this == other);
    }

    bool Money::operator<(const Money& other) const
    {
        if (hryvnias != other.hryvnias)
            return hryvnias < other.hryvnias;
        return kopiyky < other.kopiyky;
    }

    bool Money::operator>(const Money& other) const
    {
        return other < *this;
    }

    bool Money::operator<=(const Money& other) const
    {
        return !(other < *this);
    }

    bool Money::operator>=(const Money& other) const
    {
        return !(*this < other);
    }

    double Money::toDouble() const
    {
        return hryvnias + (kopiyky / 100.0);
    }

    std::string Money::toString() const
    {
        std::string result = std::to_string(hryvnias) + ",";
        if (kopiyky < 10)
            result += "0";
        result += std::to_string(static_cast<int>(kopiyky));
        return result;
    }
}
