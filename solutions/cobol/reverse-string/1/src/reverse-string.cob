       IDENTIFICATION DIVISION.
       PROGRAM-ID. REVERSE-STRING.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-STRING  PIC X(64).
       77 I          PIC 9(2).
       77 J          PIC 9(2).
       77 TEMP       PIC X(1).

       PROCEDURE DIVISION.
       REVERSE-STRING.
           COMPUTE J = FUNCTION LENGTH(FUNCTION TRIM(WS-STRING))
           PERFORM VARYING I FROM 1 BY 1 UNTIL I >= J
                   MOVE WS-STRING(J:1) TO TEMP
                   MOVE WS-STRING(I:1) TO WS-STRING(J:1)
                   MOVE TEMP TO WS-STRING(I:1)
                   SUBTRACT 1 FROM J
           END-PERFORM.