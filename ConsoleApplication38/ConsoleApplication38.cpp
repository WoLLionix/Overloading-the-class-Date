#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void display() const 
    {
        std::cout << day << '/' << month << '/' << year;
    }

    int operator-(const Date& other) const 
    {
        int thisDays = day + month * 30 + year * 365;
        int otherDays = other.day + other.month * 30 + other.year * 365;

        return thisDays - otherDays;
    }

    Date operator+(int days) const 
    {
        Date result = *this;
        result.day += days;

        while (result.day > 30) 
        {
            result.day -= 30;
            result.month += 1;

            if (result.month > 12) 
            {
                result.month = 1;
                result.year += 1;
            }
        }

        return result;
    }
};

int main() 
{
    system("chcp 1251 > 0");
    Date date1(18, 7, 2023);
    Date date2(6, 4, 2022);

    std::cout << "Дата 1: ";
    date1.display();
    std::cout << std::endl;

    std::cout << "Дата 2: ";
    date2.display();
    std::cout << std::endl;

    int difference = date1 - date2;
    std::cout << "Різниця між датами: " << difference << " днів" << std::endl;

    int daysToAdd = 10;
    Date newDate = date1 + daysToAdd;
    std::cout << "Дата 1 після додавання " << daysToAdd << " днів: ";
    newDate.display();
    std::cout << std::endl;

    return 0;
}
