       IDENTIFICATION DIVISION.
       PROGRAM-ID. DIFFERENCE-OF-SQUARES.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-DIFFERENCE-OF-SQUARES  PIC 9(8).
       01 WS-SUM-OF-SQUARES         PIC 9(8).
       01 WS-SQUARE-OF-SUM          PIC 9(8).
       01 WS-NUMBER                 PIC 9(8).

       77 I                         PIC 9(8) VALUE 1.

       PROCEDURE DIVISION.
       
       SQUARE-OF-SUM.
           INITIALIZE WS-SQUARE-OF-SUM
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-NUMBER
                   ADD I TO WS-SQUARE-OF-SUM
           END-PERFORM
           COMPUTE WS-SQUARE-OF-SUM = WS-SQUARE-OF-SUM ** 2
           DISPLAY "WS-SQUARE-OF-SUM: " WS-SQUARE-OF-SUM
           .
       SUM-OF-SQUARES.
           INITIALIZE WS-SUM-OF-SQUARES
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-NUMBER
                   COMPUTE WS-SUM-OF-SQUARES = WS-SUM-OF-SQUARES
                      + I ** 2
           END-PERFORM
           DISPLAY "WS-SUM-OF-SQUARES: " WS-SUM-OF-SQUARES
           .

       
       DIFFERENCE-OF-SQUARES.
      *    Assumes that SQUARE-OF-SUM and SUM-OF-SQUARES were called
           COMPUTE WS-DIFFERENCE-OF-SQUARES = WS-SQUARE-OF-SUM
              - WS-SUM-OF-SQUARES
           .