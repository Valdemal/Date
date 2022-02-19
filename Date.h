#pragma once
#include <iostream>
#include <ctime>

class Date { // Класс "Дата"
public:
    // Конструктор по умолчанию. Создает сегодняшнюю дату
    Date();

    // Конструктор
    Date(int day, int month, int year);

    // Конструктор копирования
    Date(const Date &date);

    // Возвращает текущее значение дня
    inline int day() const { return _day; }

    // Возвращает текущее значение месяца
    inline int month() const { return _month; }

    // Возвращает текущее значение года
    inline int year() const { return _year; }

    // Устанавливает значение day
    void setDay(int day);

    // Устанавливает значение month
    void setMonth(int month);

    // Устанавливает значение year
    void setYear(int year);

    // Уставанливает значение даты (day, month, year)
    void setDate(int day, int month, int year);

    // Возвращает ИСТИНА, если даты произошли одновременно, иначе ЛОЖЬ
    bool operator==(const Date &date) const;

    // Возвращает ИСТИНА, если даты произошли не одновременно, иначе ЛОЖЬ
    bool operator!=(const Date &date) const;

    // Возвращает ИСТИНА, если дата(this) произошла позже date, иначе ЛОЖЬ
    bool operator>(const Date &date) const;

    /* Возвращает ИСТИНА, если дата(this) произошла позже или
     * одновременно date, иначе ЛОЖЬ */
    bool operator>=(const Date &date) const;

    // Возвращает ИСТИНА, если дата(this) произошла раньше date, иначе ЛОЖЬ
    bool operator<(const Date &date) const;

    /* Возвращает ИСТИНА, если дата(this) произошла раньше или
     * одновременно date, иначе ЛОЖЬ */
    bool operator<=(const Date &date) const;

    // Перегрузка вывода в поток
    friend std::ostream &operator<<(std::ostream &out, const Date &date);

    // Перегрузка чтения из потока
    friend std::istream &operator>>(std::istream &in, Date &date);

    // Возвращает значение ИСТИНА, если год year - високосный, иначе ЛОЖЬ
    static bool isLeapYear(int year);

    // Возвращает количество дней в месяце month года year
    static int dayInMonth(int month, int year);

private:
    int _day;
    int _month;
    int _year;

    /* Возвращает значение ИСТИНА, если дата (day, month, year) имеет
     * корректный вид */
    static bool isValidDate(int day, int month, int year);

    /* Возвращает значение ИСТИНА, если day месяца month и года year
     * имеет корретное значение */
    static bool isValidDay(int day, int month, int year);

    // Возвращает значение ИСТИНА, если month имеет корретное значение
    static bool isValidMonth(int month);

    /* Возвращает 1, если date1 произошло позже, чем date2.
     * Возвращает -1, если date1 произошло раньше, чем date2.
     * Возвращает 0, если date1 и date2 призошли одновременно. */
    static short compareDates(const Date & date1, const Date & date2);

};
