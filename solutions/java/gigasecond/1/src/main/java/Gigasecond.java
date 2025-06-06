import java.time.LocalDate;
import java.time.LocalDateTime;

class Gigasecond {
    private LocalDateTime data;
    static final long GIGASECOND = 1000000000;

    Gigasecond(LocalDate moment) {
        this.data = moment.atStartOfDay().plusSeconds(GIGASECOND);
    }

    Gigasecond(LocalDateTime moment) {
        this.data = moment.plusSeconds(GIGASECOND);
    }

    LocalDateTime getDateTime() {
        return this.data;
    }

}
