
/* Sum of arithemetic Progression

Sum= a+(n-1)d
*/

#include<iostream>
int main()
{
	int initial_term,sum,number_of_terms, difference,nth_term;
	std::cout<<"Enter value of initial_term,number_of_terms and the difference\n";
	std::cin>> initial_term>>number_of_terms>>difference;
	
	nth_term=initial_term+(number_of_terms-1)*difference;

	sum=number_of_terms*(initial_term+nth_term)/2;
	std::cout<<"Arithmetic Progression Sum:"<<sum<<"\n";
}
