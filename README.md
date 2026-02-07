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
## 📸 Project Screenshots

### 🛠️ Operator Portal
| Login View | Main Dashboard |
| :---: | :---: |
| ![Operator Login](Operator%20portal%20screenshots/operator_login.png) | ![Operator Dashboard](Operator%20portal%20screenshots/operator_dashboard.png) |

> **Note:** Replace `operator_login.png` and `operator_dashboard.png` with the actual file names you have uploaded inside that folder.
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
