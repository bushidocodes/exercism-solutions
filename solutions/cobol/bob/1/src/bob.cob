       IDENTIFICATION DIVISION.
       PROGRAM-ID. BOB.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-HEYBOB            PIC X(60).
       01 WS-HEYBOB-LEN        PIC 99.
       01 WS-RESULT            PIC X(40).
       77 I                    PIC 99.
       01 IS-QUESTION-FLAG     PIC 9.
          88 IS-QUESTION                 VALUE 1 FALSE 0.
       01 IS-YELLING-FLAG      PIC 9.
          88 IS-YELLING                  VALUE 1 FALSE 0.
       01 HAS-UPPER-CASE-FLAG  PIC 9.
          88 HAS-UPPER-CASE              VALUE 1 FALSE 0.
       01 HAS-LOWER-CASE-FLAG  PIC 9.
          88 HAS-LOWER-CASE              VALUE 1 FALSE 0.
       01 IS-SILENT-FLAG       PIC 9.
          88 IS-SILENT                   VALUE 1 FALSE 0.

       PROCEDURE DIVISION.
       BOB.
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-HEYBOB))
              TO WS-HEYBOB-LEN

           IF WS-HEYBOB-LEN = 0
              SET IS-SILENT TO TRUE
           ELSE 
              SET IS-SILENT TO FALSE
           END-IF

           IF WS-HEYBOB-LEN > 0 AND WS-HEYBOB(WS-HEYBOB-LEN:1) = '?'
              SET IS-QUESTION TO TRUE
           ELSE 
              SET IS-QUESTION TO FALSE
           END-IF

           IF WS-HEYBOB-LEN > 0
              SET HAS-LOWER-CASE TO FALSE
              SET HAS-UPPER-CASE TO FALSE
              PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-HEYBOB-LEN
                 OR (HAS-LOWER-CASE AND HAS-UPPER-CASE)
                      EVALUATE WS-HEYBOB(I:1)
                      WHEN 'a' THROUGH 'z'  
                           SET HAS-LOWER-CASE TO TRUE
                      WHEN 'A' THROUGH 'Z'
                           SET HAS-UPPER-CASE TO TRUE
                      END-EVALUATE
              END-PERFORM

              IF HAS-UPPER-CASE AND NOT HAS-LOWER-CASE
                 SET IS-YELLING TO TRUE
              ELSE
                 SET IS-YELLING TO FALSE
              END-IF
           ELSE
              SET IS-YELLING TO FALSE
           END-IF

           EVALUATE TRUE
           WHEN IS-SILENT 
                MOVE "Fine. Be that way!" TO WS-RESULT
           WHEN IS-YELLING AND IS-QUESTION 
                MOVE "Calm down, I know what I'm doing!" TO WS-RESULT
           WHEN IS-YELLING 
                MOVE "Whoa, chill out!" TO WS-RESULT
           WHEN IS-QUESTION 
                MOVE "Sure." TO WS-RESULT
           WHEN OTHER
                MOVE "Whatever." TO WS-RESULT
           END-EVALUATE
           .