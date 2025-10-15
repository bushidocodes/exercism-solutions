       IDENTIFICATION DIVISION.
       PROGRAM-ID. COLLATZ-CONJECTURE.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       77 WS-NUMBER  PIC S9(8).
       77 WS-STEPS   PIC 9(4).
       77 WS-ERROR   PIC X(35).

       PROCEDURE DIVISION.
       COLLATZ-CONJECTURE.
           INITIALIZE WS-STEPS
           INITIALIZE WS-ERROR

           IF WS-NUMBER < 1
              MOVE "Only positive integers are allowed" TO WS-ERROR
              GOBACK
           END-IF

           PERFORM UNTIL WS-NUMBER = 1
                   ADD 1 TO WS-STEPS
                   IF FUNCTION MOD(WS-NUMBER, 2) = 0
                      COMPUTE WS-NUMBER = WS-NUMBER / 2
                   ELSE
                      COMPUTE WS-NUMBER = 3 * WS-NUMBER + 1
                   END-IF
           END-PERFORM.