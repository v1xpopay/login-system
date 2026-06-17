#login system (the base code)
users = {
    "admin": "12345678",
    "nayuu": "thefinalboss"
}

username = input("Enter username: ")
password = input("Enter password: ")

if len(password) < 8:
    print("Password must be at least 8 characters long")
else:
    if username in users and users[username] == password:
        print("Access granted smarty")
    else:
        print("Access denied (nice try diddy)")
typu = 3
while username == "admin":
    print("welcome admin")

typu = typu + 1    