       IDENTIFICATION DIVISION.
       PROGRAM-ID. ALL-YOUR-BASE.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-INPUTBASE   PIC S999.
       01 WS-OUTPUTBASE  PIC S999.
       01 WS-DIGITS      PIC X(60).
       01 WS-RESULT      PIC X(60).
       01 WS-ERROR       PIC X(60).
      * Pointer to start of current field
       01 WS-PTR         PIC 99.
      * Pointer to end of current field
       01 WS-COMMA-POS   PIC 99.
       01 ACC            PIC 9(18) COMP.
       01 DIGIT          PIC S9(18) COMP.
       01 TEMP           PIC X(60).
 
       PROCEDURE DIVISION.
       REBASE.
           INITIALIZE WS-ERROR
           
           EVALUATE TRUE
           WHEN WS-INPUTBASE < 2
                MOVE "input base must be >= 2" TO WS-ERROR
           WHEN WS-OUTPUTBASE < 2
                MOVE "output base must be >= 2" TO WS-ERROR
           WHEN OTHER 
                PERFORM PARSE-INPUT
           END-EVALUATE
           .

       PARSE-INPUT.
           MOVE 1 TO WS-PTR
           MOVE 0 TO WS-COMMA-POS
           MOVE 0 TO ACC
      *    Split comma-separated string into array
           PERFORM UNTIL WS-DIGITS(WS-PTR:1) = SPACE
              OR WS-PTR > LENGTH OF WS-DIGITS
      *            Find next comma
                   INSPECT WS-DIGITS(WS-PTR:)
                      TALLYING WS-COMMA-POS FOR CHARACTERS
                      BEFORE INITIAL ','

      *            Add to accumulator
                   IF WS-COMMA-POS = 0 OR WS-PTR + WS-COMMA-POS
                      > LENGTH OF WS-DIGITS

                      MOVE FUNCTION NUMVAL(FUNCTION
                         TRIM(WS-DIGITS(WS-PTR:))) TO DIGIT

                      IF DIGIT < 0 OR DIGIT >= WS-INPUTBASE
                         MOVE
                          "all digits must satisfy 0 <= d < input base"
                            TO WS-ERROR
                         EXIT PERFORM
                      END-IF

                      MULTIPLY WS-INPUTBASE BY ACC
                      ADD FUNCTION NUMVAL(FUNCTION
                         TRIM(WS-DIGITS(WS-PTR:))) TO ACC

                      EXIT PERFORM
                   ELSE
                      MOVE FUNCTION NUMVAL(FUNCTION
                         TRIM(WS-DIGITS(WS-PTR:WS-COMMA-POS))) TO DIGIT

                      IF DIGIT < 0 OR DIGIT >= WS-INPUTBASE
                         MOVE
                          "all digits must satisfy 0 <= d < input base"
                            TO WS-ERROR
                         EXIT PERFORM
                      END-IF

                      MULTIPLY WS-INPUTBASE BY ACC
                      ADD FUNCTION NUMVAL(FUNCTION
                         TRIM(WS-DIGITS(WS-PTR:WS-COMMA-POS))) TO ACC

                      ADD WS-COMMA-POS TO WS-PTR
                      ADD 1 TO WS-PTR
                      MOVE 0 TO WS-COMMA-POS
                   END-IF
           END-PERFORM

           DISPLAY "WS-DIGITS: " WS-DIGITS
           DISPLAY "ACC: " ACC

           PERFORM CONVERT-OUTPUT
           .

       CONVERT-OUTPUT.
           INITIALIZE WS-RESULT
           INITIALIZE TEMP
           IF ACC = 0
              MOVE "0" TO WS-RESULT
           ELSE
              MOVE SPACE TO WS-RESULT
              PERFORM UNTIL ACC = 0
                      DIVIDE ACC BY WS-OUTPUTBASE GIVING ACC
                         REMAINDER DIGIT 

      *               Convert digit to string, removing leading zeros
      *               and handling all-zero edge case
                      MOVE DIGIT TO TEMP
                      INSPECT TEMP REPLACING LEADING "0" BY " "
                      MOVE FUNCTION TRIM(TEMP) TO TEMP
                      IF TEMP = SPACE 
                         MOVE "0" TO TEMP
                      END-IF

      *               Prepend to result string by appending all
      *               subsequent digits after a comma. This could be
      *               made more efficient by reversing a table or
      *               building the string backwards, but I'm tired.
                      IF WS-RESULT NOT = SPACE
                         STRING FUNCTION TRIM(TEMP)
                                ","
                                WS-RESULT
                            DELIMITED BY SIZE INTO TEMP
                      END-IF

      *               Move temp back to result
                      MOVE FUNCTION TRIM(TEMP)
                         TO WS-RESULT
              END-PERFORM
           END-IF
           .