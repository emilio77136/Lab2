#include <iostream>
using namespace std;
#include <string>


struct User {

	string username;
	string password;
	string role;
	User* next;	
	

	User(const string& u, const string & p, const string& r = "viewer"){
		username = u;
		password = p;
		role = r;
		next = nullptr;

	};

};


bool insertUser(User*& head, const string& username, const string& password, const string& role = "viewer");
void printUsers(User*& head);
User* findUser(User* head, const string& username);
bool authorize(User* head, const string& username, const string& role);


int main(){

	cout << "hello world \n";
	
	User* head = nullptr; 

	insertUser(head, "Carl", "abcde", "viewer");
	insertUser(head, "Bob", "qwerty", "viewer");
	insertUser(head, "Mike", "banana123", "viewer");

	printUsers(head);

return 0;
	
}
void printUsers(User*& head){

	User* current = head;
	
	while(current != nullptr){
		cout << current->username << endl;
		current = current->next;
	}

}



bool insertUser(User*& head, const string& username, const string& password, const string& role){

	User* newUser = new User(username, password, role);
	User* current = head;


	if(head == nullptr){
		head = newUser;
		return true;
	}

	while(current != nullptr){
		if(current->username == username){
			return false;
		}
		if(current->next == nullptr){
			current->next = new User(username, password, role);	
			return true;
		}
	current = current->next;
	}

return false;
};


User* findUser(User* head, const string& username){

	User* current = head;

	while(current != nullptr){
		if(current->username == username){
		return current;
		}
	current = current->next;
	}

return nullptr;
}


bool authorize(User* head, const string& username, const string& role){

	User* current = findUser(head, username);
	
	if(current == nullptr){
		return false;
	}

	if(current->role == "admin"|| current->role == "editor" || current->role == "viewer"){
		return true;
	}

return false;

}	
