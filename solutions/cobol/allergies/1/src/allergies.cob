       IDENTIFICATION DIVISION.
       PROGRAM-ID. ALLERGIES.

       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-SCORE            PIC 9(3).
       01 WS-ITEM             PIC X(12).
       01 WS-RESULT           PIC A.
       01 WS-RESULT-LIST      PIC X(108).
       
       77 WS-RESULT-LIST-LEN  PIC 9(3)   VALUE 0.
       77 WS-ITEM-LEN         PIC 9(3)   VALUE 0.
       77 WS-TEMP             PIC 9(3).

       PROCEDURE DIVISION.
       ALLERGIC-TO.
           MOVE "N" TO WS-RESULT
           EVALUATE WS-ITEM 
           WHEN "eggs"
                IF FUNCTION MOD(WS-SCORE, 2) = 1
                   MOVE "Y" TO WS-RESULT
                END-IF
           WHEN "peanuts"
                DIVIDE WS-SCORE BY 2 GIVING WS-TEMP
                IF FUNCTION MOD(WS-TEMP, 2) = 1
                   MOVE "Y" TO WS-RESULT
                END-IF
           WHEN "shellfish"
                DIVIDE WS-SCORE BY 4 GIVING WS-TEMP
                IF FUNCTION MOD(WS-TEMP, 2) = 1
                   MOVE "Y" TO WS-RESULT
                END-IF
           WHEN "strawberries"
                DIVIDE WS-SCORE BY 8 GIVING WS-TEMP
                IF FUNCTION MOD(WS-TEMP, 2) = 1
                   MOVE "Y" TO WS-RESULT
                END-IF
           WHEN "tomatoes"
                DIVIDE WS-SCORE BY 16 GIVING WS-TEMP
                IF FUNCTION MOD(WS-TEMP, 2) = 1
                   MOVE "Y" TO WS-RESULT
                END-IF
           WHEN "chocolate"
                DIVIDE WS-SCORE BY 32 GIVING WS-TEMP
                IF FUNCTION MOD(WS-TEMP, 2) = 1
                   MOVE "Y" TO WS-RESULT
                END-IF
           WHEN "pollen"
                DIVIDE WS-SCORE BY 64 GIVING WS-TEMP
                IF FUNCTION MOD(WS-TEMP, 2) = 1
                   MOVE "Y" TO WS-RESULT
                END-IF
           WHEN "cats"
                DIVIDE WS-SCORE BY 128 GIVING WS-TEMP
                IF FUNCTION MOD(WS-TEMP, 2) = 1
                   MOVE "Y" TO WS-RESULT
                END-IF
           WHEN OTHER
                DISPLAY "UNKNOWN ITEM" WS-ITEM
           END-EVALUATE
           .

       LIST-ALLERGENS.
           INITIALIZE WS-RESULT-LIST
           MOVE 0 TO WS-RESULT-LIST-LEN

           MOVE "eggs" TO WS-ITEM
           PERFORM TRY-APPEND-ALLERGEN 
           MOVE "peanuts" TO WS-ITEM
           PERFORM TRY-APPEND-ALLERGEN 
           MOVE "shellfish" TO WS-ITEM
           PERFORM TRY-APPEND-ALLERGEN 
           MOVE "strawberries" TO WS-ITEM
           PERFORM TRY-APPEND-ALLERGEN 
           MOVE "tomatoes" TO WS-ITEM
           PERFORM TRY-APPEND-ALLERGEN 
           MOVE "chocolate" TO WS-ITEM
           PERFORM TRY-APPEND-ALLERGEN 
           MOVE "pollen" TO WS-ITEM
           PERFORM TRY-APPEND-ALLERGEN 
           MOVE "cats" TO WS-ITEM
           PERFORM TRY-APPEND-ALLERGEN 
           .

       TRY-APPEND-ALLERGEN.
           PERFORM ALLERGIC-TO
           IF WS-RESULT = "Y"
              MOVE FUNCTION LENGTH(FUNCTION TRIM(WS-ITEM))
                 TO WS-ITEM-LEN
              IF WS-RESULT-LIST-LEN = 0
                 MOVE WS-ITEM TO WS-RESULT-LIST
                 ADD WS-ITEM-LEN TO WS-RESULT-LIST-LEN
              ELSE
                 MOVE "," TO WS-RESULT-LIST(WS-RESULT-LIST-LEN + 1:1)
                 MOVE WS-ITEM TO WS-RESULT-LIST(WS-RESULT-LIST-LEN + 2:
                    WS-ITEM-LEN)
                 COMPUTE WS-RESULT-LIST-LEN = WS-RESULT-LIST-LEN
                    + WS-ITEM-LEN + 1
              END-IF
           END-IF
           .