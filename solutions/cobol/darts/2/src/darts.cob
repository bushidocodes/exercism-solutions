       IDENTIFICATION DIVISION.
       PROGRAM-ID. DARTS.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-X         PIC 99V9.
       01 WS-Y         PIC 99V9.
       01 WS-RESULT    PIC 99.
       77 WS-DISTANCE COMP-2.

       PROCEDURE DIVISION.
       DARTS.
           COMPUTE WS-DISTANCE =(WS-X ** 2 + WS-Y ** 2) ** 0.5

           EVALUATE WS-DISTANCE 
           WHEN 0 THROUGH 1.0
                MOVE 10 TO WS-RESULT
           WHEN 1.0 THROUGH 5.0
                MOVE 5 TO WS-RESULT
           WHEN 5.0 THROUGH 10.0
                MOVE 1 TO WS-RESULT
           WHEN OTHER
                MOVE 0 TO WS-RESULT
           END-EVALUATE
           .