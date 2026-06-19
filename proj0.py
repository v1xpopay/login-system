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
attempts = 3

while attempts > 0:
    username = input("Enter username: ")
    password = input("Enter password: ")

    if username in users and users[username] == password:
        print("Access granted")
        break
        
    else:
        attempts -= 1
        print("Wrong credentials. Attempts left:", attempts)

if attempts == 0:
    print("Account locked")