#include "Date.h"

/* Конструкторы */

Date::Date(int day, int month, int year) {
    if (isValidDate(day, month, 0))
        setDate(day, month, year);
    else
        throw std::invalid_argument("Invalid values of date");
}

Date::Date() {
    time_t now = time(nullptr);

    tm *ltm = std::gmtime(&now);

    _year = 1900 + ltm->tm_year;
    _month = 1 + ltm->tm_mon;
    _day = ltm->tm_mday;
}

Date::Date(const Date &date) {
    setDate(date._day, date._month, date._year);
}


/* Валидаторы */

bool Date::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400);
}

int Date::dayInMonth(int month, int year) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year))
        days[1] = 29;

    return days[month - 1];
}

bool Date::isValidDay(int day, int month, int year) {
    return day >= 1 && day <= dayInMonth(month, year);
}

bool Date::isValidMonth(int month) {
    return month >= 1 && month <= 12;
}

bool Date::isValidDate(int day, int month, int year) {
    return isValidDay(day, month, year) && isValidMonth(month);
}


/* Сеттеры*/

void Date::setDate(int day, int month, int year) {
    if (isValidDate(day, month, year)) {
        _year = year;
        _month = month;
        _day = day;
    } else
        throw std::invalid_argument("Invalid values of date");
}

void Date::setDay(int day) {
    if (isValidDate(day, _month, _year))
        _day = day;
    else
        throw std::invalid_argument("Invalid value of day");
}

void Date::setMonth(int month) {
    if (isValidDate(_day, month, _year))
        _month = month;
    else
        throw std::invalid_argument("Invalid value of month");
}

void Date::setYear(int year) {
    _year = year;
}


/* Перегрузка ввода/вывода */

std::ostream &operator<<(std::ostream &out, const Date &date) {

    out << date._day << '.' << date._month << '.' << date._year;

    return out;
}

std::istream &operator>>(std::istream &in, Date &date) {
    int day, month, year;

    in >> day >> month >> year;

    if (Date::isValidDate(day, month, 0))
        date.setDate(day, month, year);
    else
        throw std::runtime_error("Trying to input incorect date.");
}


/* Перегрузка операций сравнения */

short Date::compareDates(const Date &date1, const Date &date2) {
    if (date1._year > date2._year)
        return 1;
    else if (date1._year < date2._year)
        return -1;
    else {
        if (date1._month > date2._month)
            return 1;
        else if (date1._month < date2._month)
            return -1;
        else {
            if (date1._day > date2._day)
                return 1;
            else if (date1._day < date2._day)
                return -1;
            else
                return 0;
        }
    }
}

bool Date::operator==(const Date &date) const {
    return compareDates(*this, date) == 0;
}

bool Date::operator!=(const Date &date) const {
    return compareDates(*this, date) != 0;
}

bool Date::operator>(const Date &date) const {
    return compareDates(*this, date) == 1;
}

bool Date::operator>=(const Date &date) const {
    return compareDates(*this, date) > -1;
}

bool Date::operator<(const Date &date) const {
    return compareDates(*this, date) == -1;
}

bool Date::operator<=(const Date &date) const {
    return compareDates(*this, date)  < 1;
}

