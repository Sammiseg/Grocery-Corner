This C++ console application was created to help the Corner Grocer analyze how frequently specific items are purchased throughout the day. By reading from a list of item names stored in a text file, the program allows users to search for individual item frequencies, display a full list of item counts, view a histogram, and automatically generate a backup data file. This solution improves the store's ability to plan inventory and arrange their produce section effectively.

The goal of this project was to provide a small business with a tool to analyze daily purchase data. The Corner Grocer wanted to understand which items were most and least purchased so they could improve customer experience by rearranging their produce layout. This application solves that by giving clear visibility into item frequency using a simple text interface.

I organized the program using object-oriented programming, encapsulating all data tracking and file operations inside a GroceryTracker class. I used a map to efficiently count item frequencies and made the program interactive with a clean, easy-to-understand menu. I also added input validation and clear output formatting to make the program user-friendly and error-resistant.

The code could be enhanced by allowing the user to specify the input file at runtime, supporting export to CSV, or adding sorting options for highest/lowest frequency. These improvements would make the tool more flexible and potentially useful for other types of retail data. Adding exception handling and unit tests could also make the code more robust and secure.

The most challenging part was managing case-insensitive item lookups while preserving the original capitalization for display. I solved this by writing a helper function to compare lowercase versions of strings, while storing the original strings in the map. I also leaned on resources like the C++ documentation, Stack Overflow, and course materials to troubleshoot and verify file I/O logic.

This project strengthened my skills in object-oriented design, standard template library (STL) usage, file operations, and input validation. These are core C++ skills that apply to many types of applications, from system-level programming to desktop tools. The habits I practiced—like clean naming conventions, in-line documentation, and breaking logic into helper functions—will carry over to any future software development.

I made the code clean and maintainable by:

Using consistent formatting and indentation

Writing clear and descriptive comments

Grouping logic into logically named functions

Avoiding repetition through reusable helper methods

Naming variables and functions meaningfully

This structure ensures that the code is easy to update, expand, or hand off to another developer in the future.
