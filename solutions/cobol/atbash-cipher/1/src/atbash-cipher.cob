       IDENTIFICATION DIVISION.
       PROGRAM-ID. ATBASH-CIPHER.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-PHRASE             PIC X(60).
       77 WS-PHRASE-LEN         PIC 99.

       01 WS-RESULT             PIC X(60).
       77 WS-RESULT-LEN         PIC 99.

      *Count of characters (excluding spaces) added to result
      *to determine when to add a space
       77 WS-RESULT-CHAR-COUNT  PIC 99.
      *Index for WS-PHRASE
       77 I                     PIC 99.

       PROCEDURE DIVISION.
       ENCODE.
           INITIALIZE WS-RESULT
           MOVE 0 TO WS-RESULT-LEN 
           MOVE 0 TO WS-RESULT-CHAR-COUNT 
           MOVE FUNCTION LOWER-CASE(WS-PHRASE) TO WS-PHRASE 
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-PHRASE))
              TO WS-PHRASE-LEN

           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-PHRASE-LEN
                   EVALUATE TRUE
                   WHEN WS-PHRASE(I:1) >= 'a' AND WS-PHRASE(I:1) <= 'z'
                        PERFORM PAD-EVERY-FIVE

                        MOVE FUNCTION CHAR(FUNCTION ORD('z')
                           - (FUNCTION ORD(WS-PHRASE(I:1))
                           - FUNCTION ORD('a')))
                           TO WS-RESULT(WS-RESULT-LEN + 1:1)

                        ADD 1 TO WS-RESULT-LEN
                        ADD 1 TO WS-RESULT-CHAR-COUNT
                   WHEN WS-PHRASE(I:1) IS NUMERIC
                        PERFORM PAD-EVERY-FIVE
                        
                        MOVE WS-PHRASE(I:1) TO
                           WS-RESULT(WS-RESULT-LEN + 1:1)
                        
                        ADD 1 TO WS-RESULT-LEN
                        ADD 1 TO WS-RESULT-CHAR-COUNT
                   END-EVALUATE
           END-PERFORM
           .

       PAD-EVERY-FIVE.
           IF WS-RESULT-CHAR-COUNT > 1 AND
              FUNCTION MOD(WS-RESULT-CHAR-COUNT, 5) = 0

              MOVE SPACE TO WS-RESULT(WS-RESULT-LEN + 1:1)
              ADD 1 TO WS-RESULT-LEN
           END-IF
           .

       DECODE.
           INITIALIZE WS-RESULT
           MOVE 0 TO WS-RESULT-LEN 
           MOVE 0 TO WS-RESULT-CHAR-COUNT 
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-PHRASE))
              TO WS-PHRASE-LEN

           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-PHRASE-LEN
                   EVALUATE TRUE
                   WHEN WS-PHRASE(I:1) >= 'a' AND WS-PHRASE(I:1) <= 'z'
                        MOVE FUNCTION CHAR(FUNCTION ORD('z')
                           - (FUNCTION ORD(WS-PHRASE(I:1))
                           - FUNCTION ORD('a')))
                           TO WS-RESULT(WS-RESULT-LEN + 1:1
                           )
                        ADD 1 TO WS-RESULT-LEN
                        ADD 1 TO WS-RESULT-CHAR-COUNT
                   WHEN WS-PHRASE(I:1) IS NUMERIC
                        PERFORM PAD-EVERY-FIVE
                        MOVE WS-PHRASE(I:1) TO
                           WS-RESULT(WS-RESULT-LEN + 1:1)
                        ADD 1 TO WS-RESULT-LEN
                        ADD 1 TO WS-RESULT-CHAR-COUNT
                   END-EVALUATE
           END-PERFORM
           .