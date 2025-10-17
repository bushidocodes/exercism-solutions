       IDENTIFICATION DIVISION.
       PROGRAM-ID. ANAGRAM.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-SUBJECT           PIC X(20).
       01 WS-CANDIDATES-COUNT  PIC 9.
       01 WS-CANDIDATES-TABLE.
          02 WS-CANDIDATES OCCURS 1 TO 20
                DEPENDING ON WS-CANDIDATES-COUNT.
             05 WS-CANDIDATE   PIC X(20).
       01 WS-RESULT-LIST       PIC X(48).

       01 LHS                  PIC X(20).
       01 RHS                  PIC X(20).
       01 TEMP                 PIC X.
       01 I                    PIC 99.
       01 J                    PIC 99.
       01 K                    PIC 99.
       01 PTR                  PIC 99.

       PROCEDURE DIVISION.

       FIND-ANAGRAMS.
           INITIALIZE WS-RESULT-LIST
           MOVE FUNCTION LOWER-CASE(WS-SUBJECT) TO LHS

      *    Bubble Sort LHS
           PERFORM BUBBLE-SORT-LHS.

           MOVE 1 TO PTR
           PERFORM VARYING K FROM 1 BY 1 UNTIL K > WS-CANDIDATES-COUNT
                   IF FUNCTION LOWER-CASE(
                      WS-CANDIDATE OF WS-CANDIDATES(K))
                      NOT = FUNCTION LOWER-CASE(WS-SUBJECT)

      *               Bubble Sort RHS
                      MOVE FUNCTION LOWER-CASE(
                         WS-CANDIDATE OF WS-CANDIDATES(K)) TO RHS
                      PERFORM BUBBLE-SORT-RHS

      *               If sorted chars match, they're anagrams
                      IF LHS = RHS
                         IF PTR > 1
                            STRING "," DELIMITED BY SIZE
                               INTO WS-RESULT-LIST
                               WITH POINTER PTR
                            END-STRING
                         END-IF
                         STRING WS-CANDIDATE OF WS-CANDIDATES(K)
                            DELIMITED BY SPACE
                            INTO WS-RESULT-LIST
                            WITH POINTER PTR
                         END-STRING
                      END-IF
                   END-IF
           END-PERFORM
           .

       BUBBLE-SORT-LHS.
           PERFORM VARYING I FROM 1 BY 1 UNTIL I >= FUNCTION LENGTH
              (LHS)
                   PERFORM VARYING J FROM 1 BY 1 UNTIL J >=
                      FUNCTION LENGTH(LHS)
                           IF LHS(J:1) < LHS(J + 1:1)
                              MOVE LHS(J:1) TO TEMP
                              MOVE LHS(J + 1:1) TO LHS(J:1)
                              MOVE TEMP TO LHS(J + 1:1)
                           END-IF
                   END-PERFORM
           END-PERFORM
           .

       BUBBLE-SORT-RHS.
           PERFORM VARYING I FROM 1 BY 1 UNTIL I >= FUNCTION LENGTH
              (RHS)
                   PERFORM VARYING J FROM 1 BY 1 UNTIL J >=
                      FUNCTION LENGTH(RHS)
                           IF RHS(J:1) < RHS(J + 1:1)
                              MOVE RHS(J:1) TO TEMP
                              MOVE RHS(J + 1:1) TO RHS(J:1)
                              MOVE TEMP TO RHS(J + 1:1)
                           END-IF
                   END-PERFORM
           END-PERFORM
           .