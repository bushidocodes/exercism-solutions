       IDENTIFICATION DIVISION.
       PROGRAM-ID. ACRONYM.
       ENVIRONMENT DIVISION.
       DATA DIVISION.

       WORKING-STORAGE SECTION.
       01 WS-ACRONYM          PIC X(80).
       01 WS-ACRONYM-LEN      PIC 9(02) VALUE 0.
       01 WS-RESULT           PIC X(20).
       01 WS-RESULT-LEN       PIC 9(02) VALUE 0.
       01 I                   PIC 9(02) VALUE 1.
       01 APPEND-LETTER-FLAG  PIC X.
          88 APPEND-LETTER              VALUE 'Y' FALSE 'N'.

       PROCEDURE DIVISION.

       ABBREVIATE.
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-ACRONYM))
              TO WS-ACRONYM-LEN
           INITIALIZE WS-RESULT
           MOVE 0 TO WS-RESULT-LEN
           SET APPEND-LETTER TO TRUE
           
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-ACRONYM-LEN
                   EVALUATE TRUE
      *            Delimit on spaces and hyphens
                   WHEN WS-ACRONYM(I:1) = SPACE
                   WHEN WS-ACRONYM(I:1) = "-"
                        SET APPEND-LETTER TO TRUE 
      *            Ignore apostrophes
                   WHEN WS-ACRONYM(I:1) = "'"
                        CONTINUE 
                   WHEN WS-ACRONYM(I:1) IS ALPHABETIC
                        IF APPEND-LETTER 
                           ADD 1 TO WS-RESULT-LEN
                           MOVE FUNCTION UPPER-CASE(WS-ACRONYM(I:1))
                              TO WS-RESULT(WS-RESULT-LEN:1)
                           SET APPEND-LETTER TO FALSE
                        END-IF
                   END-EVALUATE
           END-PERFORM
           .