# s21_smartcalc v_1.0

## Contents
1. [About the project](#about-the-project)
2. [Development team](#development-team)
3. [Completed tasks](#completed-tasks)
4. [Implementation features](#implementation-features)
5. [Building the project](#building-the-project)
6. [Feedback](#feedback)

## About the project

This project is part of the School 21 project database from Sber. The goal of this project is to implement our own version of an engineering calculator with additional modes of deposit and credit calculators.

## Development team

Composition of the team that implemented the project: <br>
**kossadda** (https://github.com/kossadda) <br>

## Completed tasks

The following were implemented as part of the project:

| No. | Calculator Mode        | Description                                                                                                           |
|-----|------------------------|-----------------------------------------------------------------------------------------------------------------------|
|  1  | Engineering calculator | Allows you to calculate complex mathematical expressions up to 255 characters long with the ability to create graphs. |
|  2  | Loan calculator        | Allows you to obtain complete information about monthly payments when lending.                                        |
|  3  | Deposit calculator     | Allows you to obtain complete information about income for periods of account capitalization.                         |

## Implementation features

While writing the project, it was decided to implement the calculations on the backend in C (based on the technical specifications), the GUI component in C++ using the qt framework (which is allowed by the technical specifications of our project, despite the fact that the project is part of the C branch of the language ). The project is built using CMake, although as a backup there is the option to build using QMake.

Briefly about the engineering calculator: <br>

1) Supports input of mathematical expressions up to 255 characters. <br>
2) Support for plotting. <br>
3) Support for zooming charts. <br>
4) Support for tracing graphs. <br>
5) Interactive input validation. <br>

Briefly about the loan calculator: <br>

1) The advanced loan calculator from calcus.ru is used as a basis. <br>
2) Supports both types of monthly payments. <br>
3) Support for early repayment transactions of two types. <br>
4) Full report on all monthly payment periods. <br>
5) Full report on final lending indicators. <br>

Briefly about the deposit calculator: <br>

1) The advanced loan calculator from calcus.ru is used as a basis. <br>
2) Support for replenishment operations and partial withdrawals from the deposit. <br>
3) Support for any frequency of account capitalization. <br>
4) Full report on all periods of account capitalization. <br>
5) Full report on the final indicators of the deposit. <br>

To learn more about all the available functionality, go to the project manual, where you can find instructions for their use.

## Building the project

The following main goals for working with the project have been added to the Makefile:

| #  | Command            | Description                                                              |
|----|--------------------|--------------------------------------------------------------------------|
| 1  | `all`              | Generates documentation for the project and starts testing modules.      |
| 2  | `s21_smartcalc`    | Assembles modules into a static library.                                 |
| 3  | `test`             | Tests modules.                                                           |
| 4  | `gcov_report`      | Tests modules and generates a coverage report in html format.            |
| 5  | `dvi`              | Generates documentation in html and manual format for the functionality. |
| 6  | `rebuild`          | Rebuilding the project.                                                  |
| 7  | `clang_check`      | Testing modules for compliance with Google style.                        |
| 8  | `valgrind`         | Testing modules for working with memory through Valgrind.                |
| 9  | `install`          | Installs the necessary dependencies for testing the project.             |
| 10 | `clean`            | Cleans the repository from generated files.                              |

## Feedback

If you have any questions regarding the features or other aspects of the project that interest you, please contact us by email:

gabilov1997@gmail.com <br>

Thank you for your attention. We hope that you will like this project.