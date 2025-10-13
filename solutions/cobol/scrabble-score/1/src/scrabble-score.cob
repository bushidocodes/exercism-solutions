       IDENTIFICATION DIVISION.
       PROGRAM-ID. SCRABBLE-SCORE.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      *Inputs
       01 WS-WORD      PIC X(60).
      *Outputs
       01 WS-RESULT    PIC 99.
      *Locals
       77 I            PIC 99.
       77 WS-WORD-LEN  PIC 99.
       PROCEDURE DIVISION.
       SCRABBLE-SCORE.
           MOVE FUNCTION UPPER-CASE(WS-WORD) TO WS-WORD 
           COMPUTE WS-RESULT = 0.
           COMPUTE WS-WORD-LEN = FUNCTION LENGTH(FUNCTION TRIM(WS-WORD))
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > WS-WORD-LEN
                   EVALUATE WS-WORD(I:1)
                   WHEN "A"
                   WHEN "E"
                   WHEN "I"
                   WHEN "O"
                   WHEN "U"
                   WHEN "L"
                   WHEN "N"
                   WHEN "R"
                   WHEN "S"
                   WHEN "T"
                        ADD 1 TO WS-RESULT
                   WHEN "D"
                   WHEN "G"
                        ADD 2 TO WS-RESULT
                   WHEN "B"
                   WHEN "C"
                   WHEN "M"
                   WHEN "P"
                        ADD 3 TO WS-RESULT
                   WHEN "F"
                   WHEN "H"
                   WHEN "V"
                   WHEN "W"
                   WHEN "Y"
                        ADD 4 TO WS-RESULT
                   WHEN "K"
                        ADD 5 TO WS-RESULT
                   WHEN "J"
                   WHEN "X"
                        ADD 8 TO WS-RESULT
                   WHEN "Q"
                   WHEN "Z"
                        ADD 10 TO WS-RESULT
                   WHEN OTHER
                        CONTINUE
                   END-EVALUATE
           END-PERFORM.