       IDENTIFICATION DIVISION.
       PROGRAM-ID. ELIUDS-EGGS.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUTVARS.
          05 WS-INPUT    PIC 9(10).
       01 WS-OUTPUTVARS.
          05 WS-RESULT   PIC 9999.
       
       PROCEDURE DIVISION.
       EGG-COUNT.
           INITIALIZE WS-RESULT
           PERFORM UNTIL WS-INPUT = 0
                   IF FUNCTION MOD(WS-INPUT, 2) = 1
                      ADD 1 TO WS-RESULT 
                   END-IF
                   COMPUTE WS-INPUT = WS-INPUT / 2 
           END-PERFORM
           .