

class Date
{
	int date,month,year;
	int days_month(int month);
	int till_days();
public:
	Date();
	Date(int date, int month, int year);
	Date(const Date&);
	bool valid();
	void show();
	void next_Date();
	void prev_Date();
	void difference(Date&);
	void my_age();
	void operator+(int days);
	void operator-( int days);
	void operator++();
	void operator--();
	
	~Date();

};

