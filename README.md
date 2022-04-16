# POS

An open source POS system written in C++

## Database Structure

Each separate database instances are docker images running on they're respective port

- User information: `sudo docker run --name pos-user-information -p 80:6379 -d redis`
- Gift cards: `sudo docker run --name pos-giftcard-information -p 81:6379 -d redis`
