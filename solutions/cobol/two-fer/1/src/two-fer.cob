       IDENTIFICATION DIVISION.
       PROGRAM-ID. TWO-FER.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-NAME    PIC X(16).
       01 WS-RESULT  PIC X(64).
       
       PROCEDURE DIVISION.
       TWO-FER.
           IF FUNCTION LENGTH(FUNCTION TRIM(WS-NAME)) = 0
              MOVE "you" TO WS-NAME
           END-IF.
           MOVE FUNCTION CONCATENATE("One for ", FUNCTION TRIM(WS-NAME),
              ", one for me.") TO WS-RESULT.