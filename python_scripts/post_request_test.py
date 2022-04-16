"""Test the post request feature for login endpoint"""

import requests
url = "http://localhost:8080/login"

response = requests.post(
    url,
    headers={"Content-Type": "application/json"},
    data={"user": "Jared", "password": "Password"},
)

print(response)
