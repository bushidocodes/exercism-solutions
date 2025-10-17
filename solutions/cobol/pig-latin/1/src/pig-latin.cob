       IDENTIFICATION DIVISION.
       PROGRAM-ID. PIG-LATIN.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUT         PIC X(60).
       01 WORD             PIC X(20).
       01 WS-INPUT-LEN     PIC 99.
       01 WS-RESULT        PIC X(60).
       01 PTR              PIC 99.
       01 WORD-START       PIC 99.
       01 WORD-END         PIC 99.
       01 WORD-LENGTH      PIC 99.
       01 RESULT-PTR       PIC 99.
       01 TRANSLATED-WORD  PIC X(25).

       PROCEDURE DIVISION.

       TRANSLATE.
           MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-INPUT)) TO WS-INPUT-LEN

           MOVE FUNCTION LOWER-CASE(WS-INPUT) TO WS-INPUT

           MOVE 1 TO PTR
           MOVE 1 TO WORD-START
           MOVE 1 TO RESULT-PTR
           INITIALIZE WS-RESULT
           INITIALIZE WORD

           PERFORM UNTIL PTR > WS-INPUT-LEN
                   PERFORM FIND-NEXT-WORD
                   IF WORD-LENGTH > 0
                      PERFORM TRANSLATE-WORD
                      PERFORM ADD-WORD-TO-RESULT
                   END-IF
           END-PERFORM

           .

       FIND-NEXT-WORD.
      *    Skip leading spaces
           PERFORM UNTIL PTR > WS-INPUT-LEN OR WS-INPUT(PTR:1) NOT = " "
                   ADD 1 TO PTR
           END-PERFORM
           
           MOVE PTR TO WORD-START
           
      *    Find end of word
           PERFORM UNTIL PTR > WS-INPUT-LEN OR WS-INPUT(PTR:1) = " "
                   ADD 1 TO PTR
           END-PERFORM
           
           MOVE PTR TO WORD-END
           SUBTRACT 1 FROM WORD-END
           
           IF WORD-END >= WORD-START
              COMPUTE WORD-LENGTH = WORD-END - WORD-START + 1
              MOVE WS-INPUT(WORD-START:WORD-LENGTH) TO WORD
           ELSE
              MOVE 0 TO WORD-LENGTH
           END-IF
           .

       TRANSLATE-WORD.
           INITIALIZE TRANSLATED-WORD

           EVALUATE TRUE
           WHEN WORD-LENGTH >= 3 AND (WORD(1:3) = 'sch' OR
              WORD(1:3) = 'thr'
              OR (WORD(1:1) NOT = 'a' AND
              WORD(1:1) NOT = 'e' AND
              WORD(1:1) NOT = 'i' AND
              WORD(1:1) NOT = 'o' AND
              WORD(1:1) NOT = 'u' AND WORD(2:2) = "qu")
              )
                STRING WORD(4:) DELIMITED BY SPACE
                       WORD(1:3) DELIMITED BY SIZE
                       "ay" DELIMITED BY SIZE
                   INTO TRANSLATED-WORD
                END-STRING
           WHEN WORD-LENGTH >= 2 AND (WORD(1:2) = 'ch' OR
              WORD(1:2) = 'qu' OR WORD(1:2) = 'th')
                STRING WORD(3:) DELIMITED BY SPACE
                       WORD(1:2) DELIMITED BY SIZE
                       "ay" DELIMITED BY SIZE
                   INTO TRANSLATED-WORD
                END-STRING
      *    Handle consonant clusters followed by y (treat y as vowel)
           WHEN WORD-LENGTH >= 3 AND
              WORD(1:1) NOT = 'a' AND WORD(1:1) NOT = 'e' AND
              WORD(1:1) NOT = 'i' AND WORD(1:1) NOT = 'o' AND
              WORD(1:1) NOT = 'u' AND
              WORD(2:1) NOT = 'a' AND WORD(2:1) NOT = 'e' AND
              WORD(2:1) NOT = 'i' AND WORD(2:1) NOT = 'o' AND
              WORD(2:1) NOT = 'u' AND WORD(3:1) = 'y'
                STRING WORD(3:) DELIMITED BY SPACE
                       WORD(1:2) DELIMITED BY SIZE
                       "ay" DELIMITED BY SIZE
                   INTO TRANSLATED-WORD
                END-STRING
      *    ay is added to words that start with vowels
           WHEN WORD-LENGTH > 0 AND (WORD(1:1) = 'a' OR
              WORD(1:1) = 'e' OR WORD(1:1) = 'i' OR
              WORD(1:1) = 'o' OR WORD(1:1) = 'u'
              OR WORD(1:2) = "yt" OR WORD(1:2) = "xr"
              )
                STRING WORD DELIMITED BY SPACE
                       "ay" DELIMITED BY SIZE
                   INTO TRANSLATED-WORD
                END-STRING
           WHEN OTHER 
                STRING WORD(2:) DELIMITED BY SPACE
                       WORD(1:1) DELIMITED BY SIZE
                       "ay" DELIMITED BY SIZE
                   INTO TRANSLATED-WORD
                END-STRING
           END-EVALUATE
           .

       ADD-WORD-TO-RESULT.
           IF RESULT-PTR > 1
              STRING " " DELIMITED BY SIZE
                 INTO WS-RESULT
                 WITH POINTER RESULT-PTR
           END-IF
           STRING FUNCTION TRIM(TRANSLATED-WORD) DELIMITED BY SIZE
              INTO WS-RESULT
              WITH POINTER RESULT-PTR
           END-STRING
           .