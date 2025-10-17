       IDENTIFICATION DIVISION.
       PROGRAM-ID. BINARY-SEARCH.
       ENVIRONMENT DIVISION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
      * Comma-separated haystack
       01 WS-ARRAY      PIC X(60).
      * Needle
       01 WS-ITEM       PIC 9999.
      * 1-based index of found item, undefined if not found
       01 WS-RESULT     PIC 99.
      * "value not in array" if not found, undefined if found
       01 WS-ERROR      PIC X(40).
      
      * locals
      * Pointer to start of current field
       01 WS-PTR        PIC 99.
      * Pointer to end of current field
       01 WS-COMMA-POS  PIC 99.
       01 WS-LEN        PIC 99    VALUE 0.

       01 WS-FIELD      PIC X(10).

      * Array of elements
       01 WS-ARR-DATA.
          05 WS-ARR     PIC 9999 OCCURS 99 TIMES.
          05 WS-COUNT   PIC 99.    

       01 LO            PIC 99.
       01 HI            PIC 99.
       01 MID           PIC 99.   

       PROCEDURE DIVISION.
       
       BINARY-SEARCH.
           MOVE 0 TO WS-COUNT 
           MOVE 1 TO WS-PTR
           MOVE 0 TO WS-COMMA-POS

      *    Split comma-separated string into array
           PERFORM UNTIL WS-PTR > LENGTH OF WS-ARRAY
              OR WS-ARRAY(WS-PTR:1) = SPACE OR WS-COUNT = 99
      *            Find next comma
                   INSPECT WS-ARRAY(WS-PTR:)
                      TALLYING WS-COMMA-POS FOR CHARACTERS
                      BEFORE INITIAL ','

      *            Append field to array
                   IF WS-COMMA-POS = 0 OR WS-PTR + WS-COMMA-POS
                      > LENGTH OF WS-ARRAY

                      MOVE FUNCTION TRIM(WS-ARRAY(WS-PTR:)) TO WS-FIELD
                      MOVE FUNCTION NUMVAL(WS-FIELD) TO WS-ARR
                         (WS-COUNT + 1)
                      ADD 1 TO WS-COUNT
                      EXIT PERFORM
                   ELSE
                      COMPUTE WS-LEN = WS-COMMA-POS
                      MOVE FUNCTION TRIM(WS-ARRAY(WS-PTR:WS-LEN)) TO
                         WS-FIELD
                      MOVE FUNCTION NUMVAL(WS-FIELD) TO WS-ARR
                         (WS-COUNT + 1)
                      ADD WS-LEN TO WS-PTR
                      ADD 1 TO WS-PTR
                      ADD 1 TO WS-COUNT
                      MOVE 0 TO WS-COMMA-POS
                   END-IF
           END-PERFORM

           MOVE 1 TO LO 
           MOVE WS-COUNT TO HI 
           MOVE 0 TO WS-RESULT 

           PERFORM UNTIL LO > HI 
                   MOVE FUNCTION INTEGER((LO + HI) / 2) TO MID
                   EVALUATE TRUE 
                   WHEN WS-ARR(MID) = WS-ITEM
                        MOVE MID TO WS-RESULT 
                        EXIT PERFORM
                   WHEN WS-ARR(MID) < WS-ITEM
                        COMPUTE LO = MID + 1
                   WHEN WS-ARR(MID) > WS-ITEM
                        COMPUTE HI = MID - 1
                   END-EVALUATE
           END-PERFORM

           IF WS-RESULT = 0
              MOVE "value not in array" TO WS-ERROR
           END-IF
           .