////Eli Ahmed
////Lab 4b Palindrome Check
//
//
//#include<iostream> 
//#include<string>  //For strings and getline in case
//#include<stack>  //In case we need stack
//#include<vector>   //For vector below for palindrome check
//
//
//using namespace std;
//
////Probably need nodes to check it's 
//
//
//bool isPalindrome(string s);
//
//
//
//
//int main(void) {
//
//
//	cout << "Welcome to the amazing Palindrome Checker!" << endl;
//
//	//What I'm thinking of using a queue or stack
//	//using chars 
//
//	char userInput;  //For the do while loop to rerun
//
//	string palCheck;  //For the user input palindrome check
//
//
//	//1) Implement UI and Run again Loop 
//
//	do {
//
//		
//			cout << "\nEnter a word to check if it's a Palindrome: ";
//			getline(cin, palCheck);
//
//
//
//			if (isPalindrome(palCheck)) {  //If it is a palindrome
//
//				cout << "Yes, " << palCheck << " is a palindrome. " << endl;
//
//			}
//			else {  //If it's not a palindrome
//
//				cout << "No, " << palCheck << " is not a palindrome. " << endl;
//
//			}
//
//
//			cout << "\nDo you want to enter another Palindrome? (y or n): ";
//			cin >> userInput;
//			
//			cin.ignore();
//
//	} while (userInput != 'n' && userInput != 'N');   //Will continue until user inputs N or n, when prompted if they
//													  //want to continue
//
//
//
//		return(0);
//}
//
//
//
//
//
//bool isPalindrome(string s) {
//	
//
//	//Could've used Stack here, but it's unnecessary.
//	//Is longer and involves more memory consumption.
//	
//	int n = s.length(); //Length of string s is n
//	
//	
//	
//	for (int i = 0; i < n / 2; i++) {   //Goes through first half of string
//	
//		if (s[i] != s[n - i - 1]) {  //Compares the beginning of string and end
//									 //as palindrome is the same fowards
//									 //and backwards meaning if it is
//									//it should be the same in the middle.
//			
//			return false;   //If it doesn't as signalled above (!=)
//							//then returns false
//	
//		}
//	
//	
//	}
//	
//	return true;   //If it's empty string 
//	
//	}
//
//
//
////BELOW FOR FUN THERE 