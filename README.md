## Registration Process
During the registration process, users must provide their national ID number. The system performs the following steps:

1. **Input Validation**: The entered national ID is validated for proper format and length. If the format is incorrect, an error message is displayed.
2. **Age Verification**: The system extracts the birth date from the national ID and calculates the user's age. If the user is under 18 years old, registration is denied, and a message informs them of the age requirement.
3. **Unique Account Number Generation**: Upon successful registration, a unique 12-digit account number is generated for the user. This account number will be used for all future transactions and logins.
4. **Password Setup**: Users are prompted to create a secure password .
5. **Data Storage**: User details, including the national ID, account number, and  password, are saved to a file for future access.

## Managing Funds
Once registered and logged in, users can manage their funds through the following options:

1. **Deposit Funds**:
   - Users can select the "Deposit" option from the main menu.
   - They enter the amount they wish to deposit.
   - The system validates the input to ensure it is a positive number.
   - Upon successful validation, the amount is added to the user's account balance, and a confirmation message is displayed.

2. **Withdraw Funds**:
   - Users can select the "Withdraw" option.
   - They enter the desired withdrawal amount.
   - The system checks if the requested amount is less than or equal to the current balance.
   - If sufficient funds are available, the amount is deducted from the account, and a confirmation message is shown. If not, an error message informs the user of insufficient funds.

3. **View Balance**:
   - Users can easily check their current account balance by selecting the "View Balance" option from the menu.
   - The system displays the balance, allowing users to make informed decisions regarding their transactions.

## Data Persistence
The system employs file stream techniques to ensure that user data is securely stored and preserved across sessions:

1. **File Storage**: User information, including account numbers, balances, and encrypted passwords, is saved to a text file. This allows the system to retrieve user data upon subsequent logins.

2. **Data Retrieval**: When the application starts, it reads the file and loads user data into memory. This enables users to log in and access their information quickly.

3. **Data Update**: When users perform transactions (deposits or withdrawals), the system updates the relevant user's data in memory and writes the updated information back to the file to ensure consistency.

This structure ensures that user data is not lost when the program is closed, providing a reliable and persistent banking experience.

## Getting Started
1. **Setup Requirements**: Ensure you have a compatible C++ development environment installed, such as Code::Blocks, Visual Studio, or any other IDE of your choice.
2. **Clone the Repository**: Use the following command to clone the project repository:
   ```bash
   git clone <repository-link>
   cd bank-system

## Requirements
To successfully run and contribute to this bank system project, the following requirements should be met:

1. **C++ Development Environment**: 
   - A compatible C++ development environment should be installed on your machine. Recommended IDEs include:
     - Code::Blocks
     - Visual Studio
     - CLion
     - Any other C++ IDE of your choice

2. **Basic Knowledge**:
   - Familiarity with **File Dialogs and File Streams**: Understanding how to read from and write to files in C++.
   - Basic knowledge of **Object-Oriented Programming (OOP)**: Familiarity with concepts such as classes, objects, inheritance, and encapsulation.
   - Understanding of the **Standard Template Library (STL)**: Basic knowledge of STL components like vectors, lists, and maps to manage collections of data effectively.

3. **C++ Compiler**: 
   - Ensure that you have a C++ compiler installed (e.g., GCC, MSVC) to compile and run the code.

4. **Operating System**: 
   - This project is designed to work on Windows, macOS, and Linux systems, as long as a compatible C++ development environment is used.

By meeting these requirements, you will be well-prepared to work on this bank system project and understand its functionality.


## Contact
For any questions or inquiries, please reach out via email at [fmoamen83@gmail.com].

You can also connect with me on:
- **FaceBook**: [Fa Mo](https://www.facebook.com/profile.php?id=100055668613916)
- **LinkedIn**: [Fathy Momaen](https://www.linkedin.com/in/fathy-moamen-5464312ab/)

