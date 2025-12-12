       IDENTIFICATION DIVISION.
       PROGRAM-ID. PANGRAM.
       ENVIRONMENT DIVISION.
       CONFIGURATION SECTION.
       REPOSITORY.
         FUNCTION ALL INTRINSIC.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-SENTENCE         PIC X(60).
       01 WS-RESULT           PIC 9.
       01 LETTER-COUNTS.
          05 LETTER OCCURS 26 TIMES.
             10 LETTER-COUNT  PIC 9(2) VALUE 0.
       77 I                   PIC 9(2). 
       77 POS                 PIC 9(2).
        
       PROCEDURE DIVISION.
       PANGRAM.
      * Initialize Counts and Result
           MOVE 1 TO WS-RESULT
           INITIALIZE LETTER-COUNTS
      * Count letters in the input sentence
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > LENGTH OF WS-SENTENCE
               EVALUATE WS-SENTENCE(I:1)
                  WHEN 'A' THRU 'Z'
                     COMPUTE POS = ORD(WS-SENTENCE(I:1)) - ORD('A') + 1
                     ADD 1 TO LETTER-COUNT(POS)
                  WHEN 'a' THRU 'z'
                     COMPUTE POS = ORD(WS-SENTENCE(I:1)) - ORD('a') + 1
                     ADD 1 TO LETTER-COUNT(POS)
               END-EVALUATE 
           END-PERFORM
      * Check if all letters are present
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > 26
              IF LETTER-COUNT(I) = 0
                 MOVE 0 TO WS-RESULT
                 EXIT PERFORM
              END-IF
           END-PERFORM
           .
      