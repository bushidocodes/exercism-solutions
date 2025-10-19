       IDENTIFICATION DIVISION.
       PROGRAM-ID. SIEVE.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-LIMIT           PIC 9999.
       01 WS-RESULT          PIC 999 OCCURS 1000 TIMES.
       01 WS-COUNT           PIC 9999.
       01 WS-LOOP-INDEX      PIC 9999.
       01 WS-MULTIPLE-INDEX  PIC 9999.
       01 WS-RESET-INDEX     PIC 9999.
       01 WS-MARKERS.
          05 WS-MARKER       PIC X OCCURS 1000 TIMES.
       PROCEDURE DIVISION.

       SIEVE.
      * Reset outputs and candidate marks before each run
           MOVE 0 TO WS-COUNT
           PERFORM VARYING WS-RESET-INDEX FROM 1 BY 1
              UNTIL WS-RESET-INDEX > 1000
                   MOVE 0 TO WS-RESULT(WS-RESET-INDEX)
                   MOVE 'N' TO WS-MARKER(WS-RESET-INDEX)
           END-PERFORM
           MOVE 'Y' TO WS-MARKER(1)
      * Return immediately when no primes are possible
           IF WS-LIMIT < 2
              EXIT PARAGRAPH
           END-IF
      * Apply the sieve and collect primes in output order
           PERFORM VARYING WS-LOOP-INDEX FROM 2 BY 1
              UNTIL WS-LOOP-INDEX > WS-LIMIT
                   IF WS-MARKER(WS-LOOP-INDEX) = 'N'
                      ADD 1 TO WS-COUNT
                      MOVE WS-LOOP-INDEX TO WS-RESULT(WS-COUNT)
                      PERFORM MARK-MULTIPLES
                   END-IF
           END-PERFORM
           EXIT PARAGRAPH.
      
       MARK-MULTIPLES.
      * Mark multiples of the current prime as composite
           ADD WS-LOOP-INDEX TO WS-LOOP-INDEX
              GIVING WS-MULTIPLE-INDEX
           PERFORM UNTIL WS-MULTIPLE-INDEX > WS-LIMIT
                   MOVE 'Y' TO WS-MARKER(WS-MULTIPLE-INDEX)
                   ADD WS-LOOP-INDEX TO WS-MULTIPLE-INDEX
           END-PERFORM
           EXIT PARAGRAPH.
       END PROGRAM SIEVE.