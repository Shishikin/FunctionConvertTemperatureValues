
#include "conversions.h"

double ConvertCelsiusToFahrenheit(const double cel)
{
    return 1.8 * cel + 32;
}

double ConvertCelsiusToKelvin(const double cel)
{
    return cel + 273.15;
}