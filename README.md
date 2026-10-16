# Car Management System

A C++ console application for creating, validating, updating, displaying, and comparing car records.

The project demonstrates object-oriented programming concepts such as encapsulation, immutable and mutable attributes, validation methods, operator overloading, vectors, regular expressions, and formatted output.

## Features

- Create car objects with detailed vehicle information
- Validate license plate formats
- Validate vehicle colors
- Validate production years
- Validate chassis and engine numbers
- Validate purpose of use
- Validate vehicle prices
- Update mutable vehicle fields
- Display formatted vehicle information
- Compare cars using chassis and engine numbers
- Store multiple cars in a vector

## Car Information

Each car contains the following attributes:

- Make
- Model
- License plate
- Color
- Production year
- Chassis number
- Engine number
- Purpose of use
- Price
- Validation status

## Immutable and Mutable Fields

Some vehicle properties are defined as immutable and cannot be changed after the car object is created.

### Immutable Fields

- Make
- Model
- Production year
- Chassis number
- Engine number

### Mutable Fields

- License plate
- Color
- Purpose of use
- Price

The mutable fields can be updated using dedicated setter methods.

## Validation Rules

### License Plate

The system accepts Turkish-style license plates matching one of the following formats:

```text
34AB123
34A123
34A1234
34AB1234
```

The plate must:

- Start with two digits
- Continue with one or two uppercase letters
- End with three or four digits

### Color

The following colors are supported:

```text
White
Red
Black
Blue
```

Color validation is case-insensitive.

### Production Year

The year must be between:

```text
1886 and 2025
```

### Chassis Number

The chassis number must contain exactly 17 characters.

### Engine Number

The engine number must contain exactly 17 characters.

### Purpose of Use

The accepted values are:

```text
Private
Commercial
```

### Price

The vehicle price must be greater than zero.

## Main Class

### `Car`

The `Car` class manages all vehicle data and validation logic.

It includes:

- Constructor-based initialization
- Private validation methods
- Getter methods
- Setter methods
- Equality and inequality operators
- Stream output operator

## Setter Methods

The following methods update mutable vehicle information:

```cpp
setLicensePlate()
setColor()
setPurposeOfUse()
setPrice()
```

Each setter validates the new value before applying the change.

Invalid changes are rejected and the existing value remains unchanged.

## Operator Overloading

### Equality Operator

Two cars are considered the same when both their chassis and engine numbers are equal.

```cpp
bool operator==(const Car& other) const
```

### Inequality Operator

The inequality operator returns the opposite result of the equality comparison.

```cpp
bool operator!=(const Car& other) const
```

### Output Operator

The stream insertion operator displays all car information in a formatted form.

```cpp
friend ostream& operator<<(ostream& os, const Car& car)
```

## Example Vehicles

The application creates three sample vehicles:

```text
Ford Custom
Mercedes G63 AMG
Dacia Duster
```

The cars are stored in a `vector<Car>` and displayed using the overloaded output operator.

## Example Update

The first vehicle is updated with new mutable values:

```cpp
cars[0].setLicensePlate("34AT738");
cars[0].setColor("Red");
cars[0].setPurposeOfUse("Commercial");
cars[0].setPrice(190000);
```

## Example Comparison

The program compares the first two cars:

```cpp
if (cars[0] == cars[1]) {
    cout << "The cars are the same.";
} else {
    cout << "The cars are different.";
}
```

The comparison uses chassis and engine numbers instead of license plates.

## Project Structure

```text
car-management-system/
├── car_management_system.cpp
└── README.md
```

## Build Instructions

Compile the project using a C++ compiler:

```bash
g++ -std=c++11 car_management_system.cpp -o car_management_system
```

Run the application:

```bash
./car_management_system
```

On Windows:

```bash
car_management_system.exe
```

## Requirements

- A compiler supporting C++11 or later
- No external libraries are required

## Technologies and Concepts

- C++
- Object-Oriented Programming
- Encapsulation
- Classes and objects
- Constructors
- Constant class members
- Regular expressions
- Input validation
- Getter and setter methods
- Operator overloading
- Friend functions
- Vectors
- Formatted output

## Current Limitations

- Vehicle data is defined directly inside the source code
- The application does not accept user input
- Vehicle records are not saved after the program closes
- Only four colors are accepted
- Purpose validation is case-sensitive
- The maximum allowed year is fixed at 2025
- Chassis and engine validation checks only their length
- Duplicate chassis or engine numbers are not prevented in the vector
- The system does not support searching, deleting, or sorting vehicles

## Possible Improvements

- Add an interactive command-line menu
- Allow users to add new cars
- Add car search by license plate
- Add update and delete operations
- Save vehicle records to a file or database
- Support sorting by price, year, make, or model
- Add duplicate chassis and engine number detection
- Use the current year dynamically
- Improve chassis and engine number validation
- Make purpose validation case-insensitive
- Add custom exception handling
- Separate the class into header and source files
- Add automated unit tests

## Author

Developed by **Ezgi Erdoğan**

GitHub: [ezgerdog](https://github.com/ezgerdog)
