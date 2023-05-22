/*
   Kevin Alvarez
   CS 131
   Feb 23 2023
   
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
	bool p, q;

	/* Prompt user to input values of p and q */
	string input_p, input_q;

	while (true) 
	{
		cout << "Enter the truth value of p (true or false): ";
		cin >> input_p;

		if (input_p == "true" || input_p == "false") 
		{
			p = (input_p == "true");
			break;
		} 
		else 
		{
			cout << "Invalid input for p. Please enter either true or false." << endl;
		}
	}

	while (true) 
	{
		cout << "Enter the truth value of q (true or false): ";
		cin >> input_q;

		if (input_q == "true" || input_q == "false") 
		{
			q = (input_q == "true");
			break;
		} 
		else 
		{
			cout << "Invalid input for q. Please enter either true or false." << endl;
		}
	}

	/* conjunction */
	bool conjunction = p && q;
	cout << "p AND q: " << boolalpha << conjunction << endl;

	/* disjunction */
	bool disjunction = p || q;
	cout << "p OR q: " << boolalpha << disjunction << endl;

	/* exclusive or */
	bool exclusive_or = (p && !q) || (!p && q);
	cout << "p XOR q: " << boolalpha << exclusive_or << endl;

	/* conditional statement  */
	bool conditional = !p || q;
	cout << "p IF-THEN q: " << boolalpha << conditional << endl;

	/* biconditional */
	bool biconditional = (!p || q) && (!q || p);
	cout << "p IF-AND-ONLY-IF q: " << boolalpha << biconditional << endl;


	return 0;
}


/*
   Test 1
   Enter the truth value of p (true or false): true
   Enter the truth value of q (true or false): false
   p AND q: false
   p OR q: true
   p XOR q: true
   p IF-THEN q: false
   p IF-AND-ONLY-IF q: false

   Test 2
   Enter the truth value of p (true or false): false
   Enter the truth value of q (true or false): true
   p AND q: false
   p OR q: true
   p XOR q: true
   p IF-THEN q: true
   p IF-AND-ONLY-IF q: false

   Test 3
   Enter the truth value of p (true or false): dsa
   Invalid input for p. Please enter either true or false.
   Enter the truth value of p (true or false): true
   Enter the truth value of q (true or false): true
   p AND q: true
   p OR q: true
   p XOR q: false
   p IF-THEN q: true
   p IF-AND-ONLY-IF q: true

   Test 4
   Enter the truth value of p (true or false): false 
   Enter the truth value of q (true or false): false
   p AND q: false
   p OR q: false
   p XOR q: false
   p IF-THEN q: true
   p IF-AND-ONLY-IF q: true
 */
