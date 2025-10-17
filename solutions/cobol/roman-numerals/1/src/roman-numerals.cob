000001 IDENTIFICATION DIVISION.
       PROGRAM-ID. ROMAN-NUMERALS.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-NUMBER  PIC 9999.
       01 WS-RESULT  PIC X(20).
       01 PTR        PIC 99.
       PROCEDURE DIVISION.
       ROMAN-NUMERALS.
           INITIALIZE WS-RESULT
           MOVE 1 TO PTR
           PERFORM UNTIL WS-NUMBER = 0
                   EVALUATE TRUE
                   WHEN WS-NUMBER >= 1000
                        STRING "M" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 1000 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 900
                        STRING "CM" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 900 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 500
                        STRING "D" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 500 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 400
                        STRING "CD" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 400 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 100
                        STRING "C" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 100 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 90
                        STRING "XC" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 90 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 50
                        STRING "L" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 50 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 40
                        STRING "XL" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 40 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 10
                        STRING "X" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 10 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 9
                        STRING "IX" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 9 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 5
                        STRING "V" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 5 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 4
                        STRING "IV" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 4 FROM WS-NUMBER
                   WHEN WS-NUMBER >= 1
                        STRING "I" DELIMITED BY SIZE
                           INTO WS-RESULT
                           WITH POINTER PTR
                        END-STRING
                        SUBTRACT 1 FROM WS-NUMBER
                   END-EVALUATE
           END-PERFORM
           .