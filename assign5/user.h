/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

 #include <iostream>
 #include <string>
 
 class User
 {
 public:
   User(const std::string& name);
   void add_friend(const std::string& name);
   std::string get_name() const;
   size_t size() const;
   void set_friend(size_t index, const std::string& name);
 
   /** 
    * STUDENT TODO:
    * Your custom operators and special member functions will go here!
    */
   ~User(); // Destructor
   
   // Copy operations
   User(const User& other); // Copy constructor
   User& operator=(const User& other); // Copy assignment
   
   // Delete move operations
   User(User&& other) = delete;
   User& operator=(User&& other) = delete;
   
   // Operator overloads
   User& operator+=(User& other);
   bool operator<(const User& other) const;
   
   // Friend function for output
   friend std::ostream& operator<<(std::ostream& os, const User& user);
 
 private:
   std::string _name;
   std::string* _friends;
   size_t _size;
   size_t _capacity;
   
   void resize_friends(); // Helper function for resizing friends array
 };