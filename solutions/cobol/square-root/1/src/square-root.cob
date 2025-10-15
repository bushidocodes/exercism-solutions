       IDENTIFICATION DIVISION.
       PROGRAM-ID. SQUARE-ROOT.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-NUMBER  PIC 9(32).
       01 WS-SQRT    PIC 9(32).

       77 WS-L       PIC 9(33).
       77 WS-M       PIC 9(33).
       77 WS-R       PIC 9(33).
       PROCEDURE DIVISION.
       SQUARE-ROOT.
      *    MOVE FUNCTION SQRT(WS-NUMBER) TO WS-SQRT.

      *    Integer SQRT using Binary Search
           MOVE ZERO TO WS-L
           COMPUTE WS-R = WS-NUMBER + 1

           PERFORM UNTIL WS-L = WS-R - 1
                   COMPUTE WS-M =(WS-L + WS-R) / 2
                   IF (WS-M * WS-M) <= WS-NUMBER 
                      MOVE WS-M TO WS-L
                   ELSE
                      MOVE WS-M TO WS-R
                   END-IF
           END-PERFORM

           MOVE WS-L TO WS-SQRT
           .