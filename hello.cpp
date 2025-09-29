#include <iostream>
using namespace std;
#include <string>
#include <vector>

struct User {

	string username;
	string password;
	vector<string> permissions;
	User* next;	
	

	User(const string& u, const string & p, const vector<string>& perms = {"viewer"}){
		username = u;
		password = p;
		permissions = perms;
		next = nullptr;

	};

};


bool insertUser(User*& head, const string& username, const string& password, const vector<string>& permissions = {"viewer"});
void printUsers(User*& head);
User* findUser(User* head, const string& username);
bool authorize(User* head, const string& username, const string& permission);


int main(){

	cout << "hello world \n";
	
	User* head = nullptr; 

	insertUser(head, "Carl", "abcde",{ "viewer"});
	insertUser(head, "Bob", "qwerty", {"viewer", "editor"});
	insertUser(head, "Mike", "banana123", {"viewer", "editor", "delete"});

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



bool insertUser(User*& head, const string& username, const string& password, const vector<string>& permissions){

	User* newUser = new User(username, password, permissions);
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
			current->next = new User(username, password, permissions);	
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


bool authorize(User* head, const string& username, const string& permission){

	User* current = findUser(head, username);
	
	if(current == nullptr){
		return false;
	}

	for(const string& perm : current->permissions){	
		if(perm == permission){
			return true;
		}
	}

return false;

}	
