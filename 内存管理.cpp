#include<iostream>
using namespace std;
class Date
{
	friend ostream& operator <<(ostream& _cout, const Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1): _year(year), _month(month), _day(day)
	{}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	Date operator+(int days)
	{
		return _day += days;
	}
	Date operator-(int days) {return  _day -= days; }
	int operator-(const Date& d)
	{
		_year -= d._year;
		_month -= d._month;
		_day -= d._day;
	}
	Date& operator++()
	{
		++_year;
		++_month;
			++_day;
			return *this;
	}
	Date operator++(int)
	{
		Date tmp(*this);
		++*this;
		return tmp;
	}
	Date& operator--()
	{
		--_year;
		--_month;
		--_day;
		return *this;
	}
	Date operator--(int)
	{
		Date tmp(*this);
		--*this;
		return tmp;
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) && (_month > d._month) && (_day > d._day);
	}
	bool operator>=(const Date& d)const
	{
      return (_year >= d._year) && (_month >= d._month) && (_day >= d._day);
	}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) && (_month < d._month) && (_day < d._day);

	}
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator <<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}
void main()
{

}