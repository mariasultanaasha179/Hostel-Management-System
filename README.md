
# The Hostel Management System(HMS)
The Hostel Management System is a command-line application developed in C. It is designed to allow administrators to efficiently manage student records, handle room assignments, and track fee status within a hostel or dormitory environment.
## overview
The system provides a robust set of functionalities, storing persistent data in simple CSV files `(students.csv and users.csv)`.
## Core Features

 - **Authentication & Security:** User registration, login, and an option to change passwords `(data_entry.c, fees_security.c)`.
 - **Student Management:** Add, View All, Search, Edit, and Delete student records `(data_entry.c, data_operations.c).`
 - **Financial Tracking:** Mark student fees as Paid and generate a list of fee defaulters `(fees_security.c).`
 - **Room Management:** Assign rooms to students and check the occupancy/capacity of a specific room `(room_management.c).`

## Getting Started

#### Prerequisites
The system is written in C and requires a standard C compiler (like GCC or Clang) to build and run.

#### Building the System
After obtaining the source code, you can compile the project using a C compiler. In a typical development environment (Linux, macOS, or Windows with MinGW/Cygwin), use the following command:

```http
  gcc main.c
```
#### Running the System
Execute the compiled file from your terminal:
```http
 On Mac/Linux:
  a.out
```
```http
 On Windows:
  a.exe
```
Upon launch, the system will first prompt for Login or Registration. For first-time use, you must select option 2. Register to create an initial administrator account.


## Local Development
The project is structured with multiple C source files and a header file for organization:
| File Name | Perpose                             |
| :-------- | :---------------------------------- |
| `main.c` | Contains the main program loop and menu flow.  |
|`hostel.h`|Defines the `Student` and `User` data structures and all function prototypes.|
|`data_entry.c`|Implements authentication, adding students, and viewing all records.|
|`data_operations.c`|Implements searching, editing, and deleting student records.|
|`fees_security.c`|Handles fee updates, defaulter reports, and password changes.|
|`room_management.c`|Handles room assignment and capacity checks.|
|`students.csv`|Data file for student records (Name, ID, Phone, Room, Fees).|
|`users.csv`|Data file for system users (Username, Password).|

## Running Tests
The repository includes test files to verify core functionality:
- `test_data_entry_authentication_success.c`
- `test_data_operation_delete.c`

To run a specific test (e.g., the delete operation test), you can compile it separately. for example:
```http
Compile the delete operation test: 
gcc test_data_operation_delete.c 
./test_delete
```
