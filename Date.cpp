

#include "Date.h"
#include <iostream>
#include <cstring>
#include <ctime>
Date::Date()
{
	date=14;
	month=08;
	year=1947;
}

Date::Date(int dd,int mm, int yy)
{
	date=dd;
	month=mm;
	year=yy;
}
Date::Date(const Date& d)
{
	date=d.date;
	month=d.month;
	year=d.year;
}
Date::~Date()
{

}
int Date::days_month(int month)
{
		int days=0;
		if((month==1||month==3||month==5||month==7||month==8||month==10||month==12))
		{
			days=31;
			return days;
		}
		if((month==4 || month==6|| month==9|| month==11))
		{
			days=30;
			return days;
		}
		if(year/4!=0)
		{
			days=28;
			return days;
		}
		days=29;
		return days;
}
bool Date::valid()
{
	if(year==0 || date==0 || month>12 || month<1)
		return false;
	if(date>31)
		return false;
	if(date>30 && (month!=1||month!=3||month!=5||month!=7||month!=8||month!=10||month!=12))
		return false;
	if(date>29 && (month!=4 || month!=6|| month!=9|| month!=11))
		return false;
	if(date>28 && year/4!=0)
		return false;
	return true;
}
void Date::next_Date()
{
	date=date+1;
	if(!valid())
	{
		date=1;
		month=month+1;
		if(month>12)
		{
			month=1;
			year=year+1;
			return;
		}
	}
}
void Date::operator+(int count)
{
	std::cout<<"Shifted "<<count<<" days forward"<<"\n";
	while(count)
	{
		++*this;
		count--;
	}
}
void Date::operator++()
{
	date=date+1;
	if(!valid())
	{
		date=1;
		month=month+1;
		if(month>12)
		{
			month=1;
			year=year+1;
			return;
		}
	}
}
void Date::operator-(int count)
{
	std::cout<<"Shifted "<<count<<" days backward"<<"\n";
	while(count)
	{
		--*this;
		count--;
	}
}
void Date::operator--()
{
	date=date-1;
	if(!valid())
	{
		month--;
		if(!month)
		{
			month=12;
			year=year-1;
		}
		date=days_month(month);
	}
}
void Date::prev_Date()
{
	date=date-1;
	if(!valid())
	{
		month--;
		if(!month)
		{
			month=12;
			year=year-1;
		}
		date=days_month(month);
	}
}
int Date::till_days()
{
	int mm=month,t_days=0;
	while(mm)
	{
		t_days=t_days+days_month(mm);
		mm--;
	}
	return t_days;
}
void Date::difference(Date& d)
{
	int dy=0,dm=0,dd=0;
	if(d.year>year)
	{
		dy=d.year-year-1;
	}
	if(d.month>=month)
	{
		if(dy>1)
			dy++;
			
		if(d.date>=date)
		{
			dm=d.month-month;
			dd=d.date-date;
		}
		else
		{
			dd=(days_month(month)-date+d.date);
			dm=d.month-month-1;
		}
	}
	else 
	{
		if(d.date>=date)
		{
			dd=d.date-date;
			dm=12-month+d.month;
		}
		else	
		{	
			dd=(days_month(month)-date+d.date);
			dm=12-month+d.month-1;
		}
	}
	std::cout<<"difference:"<<dy<<" years "<<dm<<" months "<<dd<<" days "<<"\n";
}

void Date::my_age()
{
	int c_date=0,c_month=0,c_year=0,dd=0,dm=0,dy=0;
	time_t m_time;
	struct tm* timeinfo;
	time(&m_time);
	timeinfo=localtime(&m_time);
	c_date=timeinfo->tm_mday;
	c_month=timeinfo->tm_mon;
	c_year=(timeinfo->tm_year+1900);
	std::cout<<"Today's Date:";
	std::cout<<timeinfo->tm_mday<<"/"<<timeinfo->tm_mon<<"/"<<(timeinfo->tm_year+1900)<<"\n";
	if(c_year>year)
	{
		dy=c_year-year-1;
	}
	if(c_month>=month)
	{
		if(dy>1)
			dy++;
			
		if(c_date>=date)
		{
			dm=c_month-month;
			dd=c_date-date;
		}
		else
		{
			dd=days_month(month)-date+c_date;
			dm=c_month-month-1;
		}
	}
	else 
	{
		if(c_date<date)
		{
			dd=days_month(month)-date+c_date;
			dm=12-month+c_month-1;
		}
		if(c_date>=date)
		{
			dd=c_date-date;
			dm=12-month+c_month;
		}
	}
	std::cout<<"Age:"<<dy<<" years "<<dm<<" months "<<dd<<" days "<<"\n";
}
void Date::show()
{
	std::cout<<*this;
	std::cout<<"\n"<<"Date:"<<date<<"/"<<month<<"/"<<year<<"\n";
}

int main()
{
	
	Date d2(14,3,1984),d3(10,10,2015),d1(d2);
	d1.show();
	++d1;
	d1.show();
	d1.my_age();
	d1-3;
	d3.show();
	--d3;
	d2+10;
	d3.show();
	d3.my_age();
/*	std::cout<<std::boolalpha<<d2.valid();
	std::cout<<"D2:";
	d2.show();
	d2.next_Date();
	std::cout<<"Next date(D2):";
	d2.show();
	std::cout<<"Prev(D1):";
	d1.prev_Date();
	d1.show();*/

	d2.show();
	d2.difference(d3);
}
