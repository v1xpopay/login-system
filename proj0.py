#login system (the base code)
users = {
    "admin": "1234",
    "nayuu": "thefinalboss"
}

username = input("Enter username: ")
password = input("Enter password: ")

if username in users and users[username] == password:
    print("Access granted smaryy")
else:
    print("Access denied (nice try diddy)")
    