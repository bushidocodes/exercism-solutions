       IDENTIFICATION DIVISION.
       PROGRAM-ID. PANGRAM.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-SENTENCE         PIC X(60).
       01 WS-RESULT           PIC 9.
       01 LETTER-COUNTS.
          05 LETTER OCCURS 26 TIMES INDEXED BY IDX.
             10 LETTER-COUNT  PIC 9(2).
       77 J                   PIC 9(2).
       77 CHAR                PIC X(1).     
       77 POS                 PIC 9(2).
        
       PROCEDURE DIVISION.

       PANGRAM.
      * Initialize Counts and Result
           MOVE 1 TO WS-RESULT.
           PERFORM VARYING IDX FROM 1 BY 1 UNTIL IDX > 26
                   MOVE 0 TO LETTER-COUNT(IDX)
           END-PERFORM.

      * Count letters in the input sentence
           PERFORM VARYING J FROM 1 BY 1 UNTIL J > LENGTH OF WS-SENTENCE
                   MOVE WS-SENTENCE(J:1) TO CHAR
                    IF CHAR >= 'A' AND CHAR <= 'Z'
                        COMPUTE POS = FUNCTION ORD(CHAR) - FUNCTION ORD('A') + 1
                        ADD 1 TO LETTER-COUNT(POS)
                    END-IF
                    IF CHAR >= 'a' AND CHAR <= 'z'
                        COMPUTE POS = FUNCTION ORD(CHAR) - FUNCTION ORD('a') + 1
                        ADD 1 TO LETTER-COUNT(POS)
                    END-IF
           END-PERFORM.


      * Check if all letters are present
           PERFORM VARYING IDX FROM 1 BY 1 UNTIL IDX > 26
                   MOVE FUNCTION CHAR(IDX + FUNCTION ORD('A') - 1) TO CHAR
      *             DISPLAY "CHARACTER " CHAR " = " LETTER-COUNT(IDX)
                   IF LETTER-COUNT(IDX) = 0
                       MOVE 0 TO WS-RESULT
                       EXIT PERFORM
                   END-IF
           END-PERFORM.
      *     DISPLAY "Is Pangram? " WS-RESULT.