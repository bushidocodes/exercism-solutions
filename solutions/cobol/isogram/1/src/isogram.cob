       IDENTIFICATION DIVISION.
       PROGRAM-ID. ISOGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      * WS-PHRASE indexed by J
       01 WS-PHRASE           PIC X(60).
       01 WS-RESULT           PIC 9.
       01 LETTER-COUNTS.
          05 LETTER OCCURS 26 TIMES INDEXED BY I.
             10 LETTER-COUNT  PIC 9.
       77 J                   PIC 99.
       77 CHAR                PIC X(1).     

       PROCEDURE DIVISION.
       ISOGRAM.
           MOVE 1 TO WS-RESULT.
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 26
                   MOVE 0 TO LETTER-COUNT(I)
           END-PERFORM.

           PERFORM VARYING J FROM 1 BY 1 UNTIL J > LENGTH OF WS-PHRASE
                   MOVE WS-PHRASE(J:1) TO CHAR
                   COMPUTE I = 0
                   IF CHAR >= 'A' AND CHAR <= 'Z'
                      COMPUTE I = FUNCTION ORD(CHAR) - FUNCTION ORD
                         ('A') + 1
                   END-IF 
                   IF CHAR >= 'a' AND CHAR <= 'z'
                      COMPUTE I = FUNCTION ORD(CHAR) - FUNCTION ORD
                         ('a') + 1
                   END-IF

                   IF I >= 1 AND I <= 26
                      IF LETTER-COUNT(I) > 0
                         MOVE 0 TO WS-RESULT
                         MOVE LENGTH OF WS-PHRASE TO J
                         EXIT PERFORM
                      ELSE
                         ADD 1 TO LETTER-COUNT(I)
                      END-IF
                   END-IF              
           END-PERFORM.