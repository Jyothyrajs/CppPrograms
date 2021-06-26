using namespace std;
class Student
{
	int roll_No;
};

int main()
{
	Student s;
	Student::s.roll_No=1;
	cout<<Student::s.roll_No;
	return 0;
}
