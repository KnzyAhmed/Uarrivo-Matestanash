# 🚗 Uarrivo/Matestanash App

**Uarrivo** is a car-reservation application inspired by Uber, developed in C++ using the Qt framework. Built as a team project in the **Fundamentals of Computing II** course at the **American University in Cairo** (2020), the app demonstrates object-oriented design, algorithmic problem-solving, and practical GUI development.

---

## 🔍 Overview

- **Team Size:** 2 students  
- **Role:** Team Lead and Developer  
- **Technologies:** C++, Qt  
- **Routing Algorithm:** Dijkstra’s Algorithm  

Uarrivo efficiently calculates the fastest routes using Dijkstra's algorithm, handles user authentication, and simulates a complete ride-hailing experience with features like multiple car types and payment options. It also had a very primary database functionality where information would be read/written to .csv file.

---

## 🧠 Learning Outcomes

- Practicing Object Oriented Programming principles and tools used in project planning 
- Applied graph algorithms (Dijkstra) in a real-world scenario
- Gained experience in C++ GUI programming using Qt
- Strengthened teamwork and modular development skills

---

## ✨ Features

- 🚘 **Car Classes**  
  Different ride options with variable pricing (e.g. Economy, Luxurious).

- 💳 **Multiple Payment Methods**  
  Users can store and select preferred payment options.

- 🔐 **Authentication System**  
  Sign-up and sign-in functionality with input validation.

- 👤 **User Profile Management**  
  Users can update their age, phone number, and payment details.

- 🗺️ **Optimized Routing**
  This has a very CUTE feature, hand drawn maps we made specifically for the app that show the shortest paths whenever the user enters 2 locations.
  We Utilized Dijkstra’s algorithm to find the shortest/fastest route.

![Uarrivo](Maps/Maps/Map_finished.png)


---

## 🧱 Architecture & Design

Uarrivo was developed using a modular, object-oriented approach:

- Designed UML class diagrams and separated logic into modules; UML (very immature UML diagrams made by your one & only freshman self back in 2020) diagrams from back then can be found in this repo.
- Used Qt for GUI and event-driven architecture.
- Divided responsibilities among team members for effective collaboration.

### Development Workflow

1. **Design Phase**  
   - Object-oriented system architecture
   - UI mockups using Qt Designer

2. **Implementation Phase**  
   - Core features divided and implemented by individual team members
   - Integrated into a cohesive working application

3. **Testing & Debugging**  
   - Manual scenario testing
   - Route and input validation checks

---

## 📚 Course Context

This project was submitted for **CSCE 1102 - Fundamentals of Computing II** (Spring 2020) at the **American University in Cairo**. It served as a hands-on application of:

- Object-Oriented Programming  
- GUI Development using Qt  
- Graph Algorithms and Data Structures  
- Team-based Software Engineering

---

## 🚀 Future Enhancements (if continued)

- Real-time GPS integration  
- Backend database for persistent user/trip data, and other information retrieval tasks  
- Mobile version using Qt for Android/iOS  
- Live map view with route preview

---

## ⚙️ Tech Stack

- **Language:** C++  
- **Framework:** Qt (Desktop GUI)  
- **Algorithm:** Dijkstra’s Shortest Path


