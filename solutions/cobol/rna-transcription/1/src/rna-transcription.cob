       IDENTIFICATION DIVISION.
       PROGRAM-ID. RNA-TRANSCRIPTION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 WS-COMPLEMENT  PIC X(64).
       77 I              PIC 9(2).

       PROCEDURE DIVISION.
       RNA-TRANSCRIPTION.
           PERFORM VARYING I FROM 1 BY 1 UNTIL I > LENGTH OF
              WS-COMPLEMENT
                   EVALUATE WS-COMPLEMENT(I:1)
                   WHEN "G"
                        MOVE "C" TO WS-COMPLEMENT(I:1)
                   WHEN "C"
                        MOVE "G" TO WS-COMPLEMENT(I:1)
                   WHEN "T"
                        MOVE "A" TO WS-COMPLEMENT(I:1)
                   WHEN "A"
                        MOVE "U" TO WS-COMPLEMENT(I:1)
                   WHEN OTHER
                        MOVE SPACE TO WS-COMPLEMENT(I:1)
                   END-EVALUATE
           END-PERFORM.