#pragma once
#ifdef MONEYDLL_EXPORTS
#define MONEYDLL_API __declspec(dllexport)
#else
#define MONEYDLL_API __declspec(dllimport)
#endif

#include <iostream>
#include <stdexcept>
#include <string>

namespace MoneyOperations
{
    class MONEYDLL_API Money
    {
    private:
        long hryvnias;
        unsigned char kopiyky;
        void normalize();

    public:
        Money();
        Money(long hryvnias, unsigned char kopiyky);
        Money(double amount);

        Money operator+(const Money& other) const;
        Money operator-(const Money& other) const;
        Money operator*(double multiplier) const;
        Money operator/(double divisor) const;
        double operator/(const Money& other) const;

        bool operator==(const Money& other) const;
        bool operator!=(const Money& other) const;
        bool operator<(const Money& other) const;
        bool operator>(const Money& other) const;
        bool operator<=(const Money& other) const;
        bool operator>=(const Money& other) const;

        long getHryvnias() const { return hryvnias; }
        unsigned char getKopiyky() const { return kopiyky; }
        double toDouble() const;

        std::string toString() const;
    };
}
