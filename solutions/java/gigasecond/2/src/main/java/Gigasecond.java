import java.time.Duration;
import java.time.LocalDate;
import java.time.LocalDateTime;

class Gigasecond {
    private LocalDateTime data;
    static final Duration GIGASECOND = Duration.ofSeconds(1_000_000_000);

    Gigasecond(LocalDateTime moment) {
        this.data = moment.plus(GIGASECOND);
    }

    Gigasecond(LocalDate moment) {
        this(moment.atStartOfDay());
    }

    LocalDateTime getDateTime() {
        return this.data;
    }

}
