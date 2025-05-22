Oceanographic Data Processor in C
=================================

Description
-----------
This C program reads oceanographic sample data from a CSV file (`ocean.csv`), processes the measurements (temperature, nutrient levels, salinity, etc.), and provides sorting and searching capabilities to analyze the dataset.

Implemented features include:
- Data parsing
- Struct handling
- Insertion Sort & Quicksort
- Binary search
- Minimum & maximum value identification
- (Planned) Counting Sort

Data Structure
--------------
The program uses the following `Samples` struct:

    typedef struct Samples {
        float degrees;
        float PO4uM;
        float SiO3uM;
        float NO2uM;
        float NO3uM;
        float Salnty;
        float O2ml_L;
        char dates[200];
    } Samples;

Each line of the CSV is mapped into a `Samples` struct object.

Features
--------
- CSV Parsing: Reads data from the CSV into an array of structs.
- Data Copying: Duplicates the dataset for sorting/analysis.
- Sorting Algorithms:
  - Insertion Sort (by temperature)
  - Quicksort (by temperature)
  - (Planned) Counting Sort (by PO4uM)
- Search:
  - Binary search by date after sorting
- Statistical Functions:
  - Find minimum and maximum temperatures
- Display:
  - Print unsorted, insertion-sorted, and quicksorted results

Compilation & Execution
-----------------------
Compile using:

    gcc main.c -o ocean_data

Run the program (ensure `ocean.csv` is in the same directory):

    ./ocean_data

Sample Usage
------------
When prompted, input a specific date in the format used in the CSV. The program will perform a binary search and display the corresponding sample’s temperature.

Example:

    Give a date: 6/15/2005

Known Issues
------------
- Improper use of dynamic strings (e.g., unsafe use of `char *po[N]`).
- Binary search contains incorrect recursive function call (e.g., `binarySearch` vs `binarysearch`).
- Redundant logic for date sorting (individual blocks for each year).
- CSV parsing is rigid and assumes a strict structure.
- Incorrect implementation of `swap()` and `piviot()` functions for structs.
- Counting Sort is present but not fully implemented.
- Lacks input validation and robust error handling.

Suggested Improvements
----------------------
- Use `strdup()` and `malloc()` for safer dynamic string management.
- Replace repetitive date sorting with a generalized `struct tm` or `YYYYMMDD` sorting method.
- Ensure sorting algorithms handle full struct records, not just temperature.
- Improve CSV parsing using `sscanf()` or a dedicated CSV parser.
- Correct the binary search function and its recursive logic.
- Implement Counting Sort with proper support for floating-point grouping.
