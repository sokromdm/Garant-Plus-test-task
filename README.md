Test task for Garant-Plus comp.
===========
This is a simple Qt-project that reads selected .txt file with lines of streets and house numbers and displays them on two windows: one shows street names, second shows house numbers of selected street from the first window.

#### Requirements
Qt Creator 4.13.2 with *Desktop_Qt_5_15_1_MinGW_32_bit* kit.

#### Usage
Start the application from **Qt Creator** by pressing [Ctrl+R]. Two windows will appear, press the "Open file" button on one of them and select .txt file with data (example file *"Streets.txt"* lies on default folder). After that the list widget will be filled with streets names, clicking on one of them will fill the second window with house numbers of selected street.

#### File format
File standart:
- .txt filename extension;
- UTF-8 encoding;

Single line must contain:
- Street name without numbers, may contain spaces between words, must contain at least one space before first house number;
- House numbers separated by ','(may contain spaces). May contain non-numbers but first symbol must be number (example: 39а or 10/2);
- End of the line symbol ('\n').

Examples of lines:

    "Свободы 1,2,3";
    "Улица Пушкина 12 , 12а,1 , 10".

Examples of wrong lines:
    
     "Улица 1 а1, б2"  // Street name contains numbers, house number starts with non-number;
     "Пушкина 10; 11/2," // Wrong separation symbol ';'.
