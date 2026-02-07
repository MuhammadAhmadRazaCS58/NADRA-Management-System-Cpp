# 🚀 NADRA Record Management System (C++)

A console-based C++ application that simulates the National Database & Registration Authority (NADRA) system.  
This project was developed to practice core computer science concepts including file handling, data structures, role-based access control, and input validation.

---

## 📌 Project Overview

This system manages citizen records through a structured, role-based interface.  
It demonstrates understanding of:

- Modular programming
- Role-Based Access Control (RBAC)
- Persistent data storage using file systems
- Dynamic memory handling
- Input validation techniques

The system stores records in memory using `std::vector` and saves them to text files to ensure data persistence.

---

## 🔑 Key Features

### 👤 Multi-User Login System
Separate portals with different permissions:
- **Admin**
- **Operator**
- **Citizen**

### 🆔 Automatic CNIC Generation
- Generates unique CNIC numbers
- Prevents duplication
- Automatically assigns issue & expiry dates

### 📂 File Persistence
- Saves records to `nadra_records.txt`
- Loads records on program start
- Ensures no data loss after program exit

### 🔄 CNIC Renewal System
- Detects expired CNICs
- Automatically recalculates new 10-year expiry

### 📊 Sorting & Statistics
- Youngest person
- Oldest person
- Tallest person
- Shortest person
- Total persons
- Male/Female count

### 🧠 Session History Tracking
- Stores last 5 actions performed
- Displays operator/admin activity log

### 🛡 Smart Input Validation
Custom validation functions:
- `getInt()`  
- `getFloat()`  
- `getChar()`  
- `getString()`  
- Blood group validation (A+, B-, etc.)  
- Gender validation (M/F)

Prevents crashes due to invalid input.

---

## 🛠️ Technologies & Concepts Used

### Language
- C++

### Data Structures
- `struct`
- `std::vector`
- 2D arrays (for history tracking)

### File Handling
- `fstream`
- Read/Write operations
- Persistent storage

### Algorithms
- Linear search
- Conditional sorting logic
- Random number generation (`rand()`)

### Libraries Used
- `<iostream>`
- `<vector>`
- `<fstream>`
- `<ctime>`
- `<cstdlib>`

---

## 🎮 System Portals & Permissions

| Role      | Permissions |
|-----------|------------|
| **Admin** | Full access: Add, Edit, Delete, Search, Save/Load, Sort, Renew CNIC, View Statistics |
| **Operator** | Add records, Search by CNIC, Renew CNIC, View statistics |
| **Citizen** | Load records and check personal record |

---

## 🧮 Smart System Logic

### 📅 Expiry Calculation
- Issue date = current system date
- Expiry date = 10 years from issue date

### 🔍 CNIC Expiry Detection
- Compares system date with expiry date
- Displays CNIC status: VALID / EXPIRED


---

## 🚀 How to Run

1. Clone the repository:
2. Open the project in any C++ IDE:
   - Dev-C++
   - Code::Blocks
   - VS Code
   - CLion

3. Compile and run `main.cpp`

---
## 📸 System Portals & Screenshots

The system is divided into three distinct portals. Below are the visual representations of each interface.

### 👑 Admin Portal
*The highest access level, allowing for full CRUD (Create, Read, Update, Delete) operations on citizen records and system configuration.*
|
| **Main Dashboard** | ![Admin Screen](https://github.com/MuhammadAhmadRazaCS58/NADRA-Management-System-Cpp/tree/45b7b7a5a02c17569eb4eb9e53710dd7df031bf3/Admin%20portal%20screenshots) |



### 🛠️ Operator Portal
*Designed for staff members to handle data entry, verify citizen details, and process CNIC renewals.*
|
| **Operator Menu** | ![Operator Dashboard](https://github.com/MuhammadAhmadRazaCS58/NADRA-Management-System-Cpp/tree/45b7b7a5a02c17569eb4eb9e53710dd7df031bf3/Operator%20portal%20screenshots) |


### 👤 Citizen Portal
*A restricted view for citizens to load the database and verify their own registration status.*


| **Login Interface** | ![Citizen Login](https://github.com/MuhammadAhmadRazaCS58/NADRA-Management-System-Cpp/tree/45b7b7a5a02c17569eb4eb9e53710dd7df031bf3/Citizen%20portal%20screenshots) |

---
---
## 🔮 Future Improvements

- Convert structure-based system into full OOP architecture
- Password encryption / hashing
- GUI version (Qt or C++ GUI framework)
- Database integration (MySQL / SQLite)
- Search by name feature
- Data export functionality
---

## 👨‍💻 Author

MUHAMMAD AHMAD RAZA 
BS Computer Science Student  
---
